# Nova
Nova is a Pulseaudio volume control program. It is similar to Vol2X-Reloaded – but it is done with C++ and QT5.

#<Nova> Copyright (c) 2017 JJ Posti <techtimejourney.net>
#<Nova> comes with ABSOLUTELY NO WARRANTY;
#for details see: http://www.gnu.org/copyleft/gpl.html.
#This is free software, and you are welcome to redistribute it under #GPL Version 2, June 1991″

Icons are from Adwaita project and they may have different license. See: Icons file for further information.

![nova2](https://user-images.githubusercontent.com/29865797/41203436-56b80c72-6cc6-11e8-907f-5110d809595e.jpg)
______________

Features:

-When program starts the slider is always in a zero position.
This is done to prevent accidental volume increases to very loud levels.

-Pavucontrol opens when the program is double-clicked with right or left mouse button. When Nova is double-clicked it closes itself and opens Pavucontrol.

-Supports keyboard volume keys. If you have something in global space taking keypresses, like Xbindkeys, then keypress events might not work in Nova.

-Has buttons with tooltips and highlighting.

-Decorated with CSS.

-Increases or decreases volume of 5 devices simultaneously. The previous method gives abilities to control the levels of standard sound output together with, for example, Bluetooth or HDMI volume output levels.

-Has a statusbar, which shows the amount of volume.

_________________

About the project´s structure:

-Documentation folder contains licenses.

-Icons folder contains icons, which are used by the project.
Icons are used when compiling icons.qrc file.

-main.cpp file contains QApplication definitions(window creation etc.).

-mainwindow.cpp file contains majority of the program’s code.

-mainwindow.h file contains project’s header declarations.

-mainwindow.ui file is the user interface file.

-Nova.pro file is the project file. You want to open this file with QtCreator to open the entire project.

-volumelevels.cpp file contains functions for icon press events(volume to 0%, volume to 50% and volume to 100%).

 __________________
 
 Building/Dependencies:

I use Debian base as an example here. Adapt the dependencies according to your distribution.

Required dependencies: pulseaudio,  pulseaudio-utils and pavucontrol. Pulseaudio-utils provides pactl, which is needed by the project. Pavucontrol is not an absolute necessity but it should be installed to achieve full functionality.

To make things easy, you should install qtcreator package and build this project with it.

_____________

Detailed instructions:

Make sure that you have, at least, these installed alongside qtcreator package:

build-essential g++ qt5-default

qt5-default should provide something like this:

qtbase5-dev, qtchooser, qt5-qmake and qtbase5-dev-tools

Finally,  build the program using Qtcreator. In Debian you need to select your kit manually and point it to the installed qt5. Qt5-default and g++ are very important in the task of manual pointing and are thus very much needed.

____________________

Select the kit manually:

To select your build kit manually, first install the packages mentioned above.

Then open Qtcreator–>Tools–>Options–>Build & Run –> Kits and choose Manual. Manual should provide something along the lines of Desktop (default).

_______________

Opening and building the project:

After you have specified the kit and everything is good, open the Nova.pro file with Qtcreator to open the project. Then open the mainwindow.ui file found within the Forms directory. Press the Run arrow(green arrow). If the application builds and runs everything should be fine.

You should be able to find the resulted executable called Nova from the build-Nova-Desktop-Debug folder(or similar). The build-Nova-Desktop-Debug is in the same folder level than the actual project folder.

_________________


Executing:

QtCreator should, by default,  make the program executable.

If for some reason you need to make the program file executable manually use:

chmod +x program_name

Open terminal and execute this command(in the location that has the executable):

./Nova

If you need to supply a full path then the command goes like this:

/home/user/some_location/Nova

______

Original post is at:http://www.techtimejourney.net/nova-is-released/
