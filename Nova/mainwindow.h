#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

class QDial;
class QLabel;
class QPushButton;
class QToolButton;

class MainWindow : public QMainWindow
{
    Q_OBJECT
public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow() override = default;

protected:
    void keyPressEvent(QKeyEvent *e) override;
    void mouseDoubleClickEvent(QMouseEvent *e) override;

private slots:
    void onDialChanged(int value);
    void set50();
    void set100();
    void mute();
    void openAdvanced();

private:
    void setVolume(int percent);
    void setMuted(bool muted);
    void updateReadout(int percent, bool muted);

    QDial *m_dial {};
    QLabel *m_readout {};
    QPushButton *m_btn50 {};
    QPushButton *m_btn100 {};
    QPushButton *m_btnMute {};
    QToolButton *m_btnPrefs {};

    bool m_isMuted {false};
};

#endif // MAINWINDOW_H
