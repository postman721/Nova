#include "mainwindow.h"

#include <QDial>
#include <QLabel>
#include <QPushButton>
#include <QToolButton>
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QFrame>
#include <QStatusBar>
#include <QProcess>
#include <QKeyEvent>
#include <QMouseEvent>

#include <algorithm>

static void runPactl(const QStringList &args)
{
    // Works on PulseAudio and PipeWire setups where pactl is available.
    QProcess::execute("pactl", args);
}

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
{
    setWindowTitle("Nova");
    setMinimumSize(340, 220);

    auto *root = new QWidget(this);
    auto *main = new QVBoxLayout(root);
    main->setContentsMargins(14, 14, 14, 14);
    main->setSpacing(10);

    // "Classic radio" faceplate
    auto *face = new QFrame(root);
    face->setObjectName("faceplate");
    face->setFrameShape(QFrame::StyledPanel);

    auto *faceLayout = new QVBoxLayout(face);
    faceLayout->setContentsMargins(12, 12, 12, 12);
    faceLayout->setSpacing(10);

    // Readout bar
    m_readout = new QLabel("VOL 50", face);
    m_readout->setAlignment(Qt::AlignCenter);
    m_readout->setObjectName("readout");

    // Volume knob
    m_dial = new QDial(face);
    m_dial->setRange(0, 100);
    m_dial->setNotchesVisible(true);
    m_dial->setWrapping(false);
    m_dial->setValue(50);

    connect(m_dial, &QDial::valueChanged, this, &MainWindow::onDialChanged);

    // Buttons row
    auto *row = new QHBoxLayout();
    row->setSpacing(8);

    m_btn50 = new QPushButton("50%", face);
    m_btn100 = new QPushButton("100%", face);
    m_btnMute = new QPushButton("Mute", face);

    connect(m_btn50, &QPushButton::clicked, this, &MainWindow::set50);
    connect(m_btn100, &QPushButton::clicked, this, &MainWindow::set100);
    connect(m_btnMute, &QPushButton::clicked, this, &MainWindow::mute);

    row->addWidget(m_btn50);
    row->addWidget(m_btn100);
    row->addWidget(m_btnMute);

    // Preferences button (optional)
    m_btnPrefs = new QToolButton(face);
    m_btnPrefs->setToolTip("Open sound settings (pavucontrol)");
    m_btnPrefs->setText("⚙");
    connect(m_btnPrefs, &QToolButton::clicked, this, &MainWindow::openAdvanced);

    auto *top = new QHBoxLayout();
    top->addWidget(m_readout, 1);
    top->addWidget(m_btnPrefs, 0);

    faceLayout->addLayout(top);
    faceLayout->addWidget(m_dial, 1, Qt::AlignCenter);
    faceLayout->addLayout(row);

    main->addWidget(face);
    setCentralWidget(root);

    // Styling
    root->setStyleSheet(
        "#faceplate { background: #1d1f22; border: 1px solid #3a3f45; border-radius: 10px; }"
        "#readout { background: #0e0f10; color: #d6d6d6; padding: 10px; border: 1px solid #3a3f45; border-radius: 6px; font: 700 18px; letter-spacing: 2px; }"
        "QPushButton { padding: 8px 10px; border-radius: 6px; background: #2a2e33; color: #e7e7e7; border: 1px solid #3a3f45; }"
        "QPushButton:pressed { background: #22262a; }"
        "QToolButton { padding: 6px 10px; border-radius: 6px; background: #2a2e33; color: #e7e7e7; border: 1px solid #3a3f45; }"
    );

    statusBar()->showMessage("Qt 6 required. Double-click to open sound settings.");

    // Apply initial volume
    setVolume(m_dial->value());
}

void MainWindow::setVolume(int percent)
{
    percent = std::clamp(percent, 0, 100);

    // Use default sink: no hardcoded sink indexes.
    runPactl({"set-sink-volume", "@DEFAULT_SINK@", QString::number(percent) + "%"});

    if (percent == 0) {
        setMuted(true);
    } else if (m_isMuted) {
        // If user turns volume up, unmute.
        setMuted(false);
    }

    updateReadout(percent, m_isMuted);
}

void MainWindow::setMuted(bool muted)
{
    m_isMuted = muted;
    runPactl({"set-sink-mute", "@DEFAULT_SINK@", muted ? "1" : "0"});
    m_btnMute->setText(muted ? "Unmute" : "Mute");
}

void MainWindow::updateReadout(int percent, bool muted)
{
    if (muted || percent == 0) {
        m_readout->setText("MUTED");
        statusBar()->showMessage("Muted.");
    } else {
        m_readout->setText(QString("VOL %1").arg(percent));
        statusBar()->showMessage(QString("Volume %1%.").arg(percent));
    }
}

void MainWindow::onDialChanged(int value)
{
    setVolume(value);
}

void MainWindow::set50()
{
    m_dial->setValue(50);
}

void MainWindow::set100()
{
    m_dial->setValue(100);
}

void MainWindow::mute()
{
    if (!m_isMuted) {
        setMuted(true);
        updateReadout(m_dial->value(), true);
    } else {
        setMuted(false);
        // If dial at 0, bump to something sensible when unmuting.
        if (m_dial->value() == 0) m_dial->setValue(10);
        updateReadout(m_dial->value(), false);
    }
}

void MainWindow::openAdvanced()
{
    // Optional external tool. If missing, nothing breaks.
    QProcess::startDetached("pavucontrol");
}

void MainWindow::keyPressEvent(QKeyEvent *e)
{
    if (e->key() == Qt::Key_VolumeDown) {
        m_dial->setValue(std::max(0, m_dial->value() - 5));
    } else if (e->key() == Qt::Key_VolumeUp) {
        m_dial->setValue(std::min(100, m_dial->value() + 5));
    } else if (e->key() == Qt::Key_VolumeMute) {
        mute();
    } else if (e->key() == Qt::Key_Escape) {
        close();
    } else {
        QMainWindow::keyPressEvent(e);
    }
}

void MainWindow::mouseDoubleClickEvent(QMouseEvent *e)
{
    if (e->button() == Qt::LeftButton || e->button() == Qt::RightButton) {
        openAdvanced();
    } else {
        QMainWindow::mouseDoubleClickEvent(e);
    }
}
