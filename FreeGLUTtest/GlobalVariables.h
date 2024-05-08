#pragma once
#ifndef GLOBALVARIABLES_H
#define GLOBALVARIABLES_H

#include <GL/freeglut.h>
#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>
#include <cstdlib>

namespace Global
{
    #define mapW 10
    #define mapH 20

    enum ColorType {
        LIGHT_BLUE,
        DARK_BLUE,
        ORANGE,
        YELLOW,
        GREEN,
        VIOLET,
        RED
    };

    enum CellType {
        EMPTY,
        OLD_FIGURE,
        NEW_FIGURE
    };

    const int windowSizeX = 700;
    const int windowSizeY = 700;
    const int marginLeft = 200;
    const int marginTop = 50;


    extern int millisecondsBeforeUpdate;
    extern int score;
    extern int dy;
    extern int dx;
    extern int rotateMode;
    extern int AmountOfMiliseconds;

    extern float angle;

    extern bool isDxChanged;
    extern bool isRotateChanged;
    extern bool isRightCellsEmpty;
    extern bool isLeftCellsEmpty;
    extern bool isLose;
    extern bool isFirstTime;
    extern bool isPerspectiveMode;

    extern char nowFigure;
    extern char nextFigure;

    class MyTime
    {
        int minutes, seconds, miliseconds;

        void AddSpeed()
        {
            if (minutes < 3 && (minutes * 60 + seconds) % 18 == 0)
            {
                Global::millisecondsBeforeUpdate -= 50;
            }
        }
    public:
        MyTime() : minutes(0), seconds(0), miliseconds(0) {}

        MyTime(int min, int sec, int msec) : minutes(min), seconds(sec), miliseconds(msec) {}

        MyTime(const MyTime& t) : minutes(t.minutes), seconds(t.seconds), miliseconds(t.miliseconds) {}

        void AddMiliseconds(int msec)
        {
            miliseconds += msec;

            if (miliseconds >= 1000)
            {
                seconds += miliseconds / 1000;
                miliseconds %= 1000;

                this->AddSpeed();
            }
            if (seconds >= 60)
            {
                minutes += seconds / 60;
                seconds %= 60;
            }
        }

        std::string GetTime()
        {
            std::string myString = std::to_string(minutes / 10) + std::to_string(minutes % 10) + ':' + std::to_string(seconds / 10) + std::to_string(seconds % 10);
            return myString;
        }
    };

    struct TColor
    {
        float red, green, blue;

        TColor() : red(0), green(0), blue(0) {}

        TColor(float r, float g, float b) : red(r / 255), green(g / 255), blue(b / 255) {}

        TColor(const TColor& c) : red(c.red), green(c.green), blue(c.blue) {}

        TColor& operator=(const TColor& c) {
            if (this != &c) {
                this->red = c.red;
                this->green = c.green;
                this->blue = c.blue;
            }
            return *this;
        }
    };

    struct SetOfColors
    {
        TColor frontColor, sideColor, backColor;

        SetOfColors(ColorType type) 
        {
            switch (type) 
            {
                case LIGHT_BLUE:
                    frontColor = TColor(0, 205, 205);
                    sideColor = TColor(0, 255, 255);
                    backColor = TColor(0, 154, 154);
                    break;
                case DARK_BLUE:
                    frontColor = TColor(0, 0, 205);
                    sideColor = TColor(0, 0, 255);
                    backColor = TColor(0, 0, 154);
                    break;
                case ORANGE:
                    frontColor = TColor(205, 102, 0);
                    sideColor = TColor(255, 137, 0);
                    backColor = TColor(154, 66, 0);
                    break;
                case YELLOW:
                    frontColor = TColor(205, 205, 0);
                    sideColor = TColor(255, 255, 0);
                    backColor = TColor(154, 154, 0);
                    break;
                case GREEN:
                    frontColor = TColor(0, 205, 0);
                    sideColor = TColor(0, 255, 0);
                    backColor = TColor(0, 154, 0);
                    break;
                case VIOLET:
                    frontColor = TColor(154, 0, 205);
                    sideColor = TColor(205, 0, 255);
                    backColor = TColor(102, 0, 154);
                    break;
                case RED:
                    frontColor = TColor(205, 0, 0);
                    sideColor = TColor(255, 0, 0);
                    backColor = TColor(154, 0, 0);
                    break;
            }
        }
    };

    struct TCell {
        CellType type;
        ColorType color;

        TCell() : type(EMPTY), color(LIGHT_BLUE) {}
    };

    extern TCell map[mapW][mapH];
    extern MyTime myTime;
}


#endif // GLOBALVARIABLES_H