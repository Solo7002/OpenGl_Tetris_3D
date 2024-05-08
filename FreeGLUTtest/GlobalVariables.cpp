#include "GlobalVariables.h"

int Global::millisecondsBeforeUpdate = 650;
int Global::score = 0;
int Global::dy = 0;
int Global::dx = 5;
int Global::rotateMode = 0;
int Global::AmountOfMiliseconds = 0;
float Global::angle = 0.0f;
bool Global::isDxChanged = false;
bool Global::isRotateChanged = false;
bool Global::isRightCellsEmpty = true;
bool Global::isLeftCellsEmpty = true;
bool Global::isLose = false;
bool Global::isFirstTime = true;
bool Global::isPerspectiveMode = false;
char Global::nowFigure = 'I';
char Global::nextFigure = 'T';
Global::TCell Global::map[mapW][mapH];
Global::MyTime Global::myTime;