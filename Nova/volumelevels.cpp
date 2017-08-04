#include "mainwindow.h"

void volumeLevels::buttonPress(){

    if(i == 0 ){

        system("pactl -- set-sink-volume 0  0%");

        system("pactl -- set-sink-volume 1  0%");

        system("pactl -- set-sink-volume 2  0%");

        system("pactl -- set-sink-volume 3  0%");

        system("pactl -- set-sink-volume 4  0%");

    }


    else if(i == 50 ){

        system("pactl -- set-sink-volume 0  50%");

        system("pactl -- set-sink-volume 1  50%");

        system("pactl -- set-sink-volume 2  50%");

        system("pactl -- set-sink-volume 3  50%");

        system("pactl -- set-sink-volume 4  50%");


    }


    else if(i == 100 ){

        system("pactl -- set-sink-volume 0  100%");

        system("pactl -- set-sink-volume 1  100%");

        system("pactl -- set-sink-volume 2  100%");

        system("pactl -- set-sink-volume 3  100%");

        system("pactl -- set-sink-volume 4  100%");

   }

};
