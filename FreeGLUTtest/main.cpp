#include "GlobalVariables.h"
#include "Tetramino.h"

using namespace Global;

void drawText(double x, double y, const char* text, TColor color)
{
    glColor3f(color.red, color.green, color.blue);
    glRasterPos2f(x, y);
    glutBitmapString(GLUT_BITMAP_TIMES_ROMAN_24, (const unsigned char*)text);
}

void drawText(double x, double y, int number, TColor color)
{
    std::string string = std::to_string(number);
    const char* text = string.c_str();
    glColor3f(color.red, color.green, color.blue);
    glRasterPos2f(x, y);
    glutBitmapString(GLUT_BITMAP_TIMES_ROMAN_24, (const unsigned char*)text);
}

void Game_Show()
{
    glLoadIdentity();
    
    if (isPerspectiveMode) {
        gluPerspective(40.0f, 1.0f, 0.1f, 100.0f);
        gluLookAt((30.0 * sin(angle)) + 15, 10.0, 40.0 * cos(angle), 
            15.0, 10.0, 0.0, 
            0.0, 1.0, 0.0);
    }
    else
    {
        glScalef(2.0 / (mapW * 2), 2.0 / mapH, 1);
        glTranslatef(-(mapW * 2) * 0.5, -mapH * 0.5, 0);
    }

    if (isFirstTime)
    {
        nowFigure = Tetramino::RandomLetter();
        nextFigure = Tetramino::RandomLetter();

        isFirstTime = false;
    }
}

void BackGround_Show()
{
    glBegin(GL_TRIANGLE_FAN);
    glColor3f(0.99, 0.99, 0.99);
    glVertex2f(0, 0);
    glVertex2f(0, 20);
    glVertex2f(10, 20);
    glVertex2f(10, 0);
    glEnd();
}

void DrawGrid()
{
    glLineWidth(0.001f);

    glBegin(GL_LINES);
    glColor3f(1, 1, 1);
    for (int i = 0; i <= mapH; i++)
    {
        glVertex3f(mapW, i, 0);
        glVertex3f(mapW * 2, i, 0);

        glVertex3f(mapW, i, 1);
        glVertex3f(mapW * 2, i, 1);


        glVertex3f(mapW, i, 0);
        glVertex3f(mapW, i, 1);

        glVertex3f(mapW * 2, i, 0);
        glVertex3f(mapW * 2, i, 1);
    }
    for (int i = 0; i <= mapW; i++)
    {
        glVertex3f(10 + i, 0, 0);
        glVertex3f(10 + i, mapH, 0);

        glVertex3f(10 + i, 0, 1);
        glVertex3f(10 + i, mapH, 1);


        glVertex3f(10 + i, 0, 0);
        glVertex3f(10 + i, 0, 1);

        glVertex3f(10 + i, mapH, 0);
        glVertex3f(10 + i, mapH, 1);
    }
    glEnd();
}

void LoseScreen()
{
    glBegin(GL_TRIANGLE_FAN);
    glColor3f(0.5, 0.5, 0.5);
    glVertex2f(0, 0);
    glVertex2f(0, 20);
    glVertex2f(20, 20);
    glVertex2f(20, 0);
    glEnd();

    Tetramino::DrawFantomTetramino(0, 3, 'T', 270);
    Tetramino::DrawFantomTetramino(2, 6, 'I', 90);
    Tetramino::DrawFantomTetramino(1, 9, 'S', 270);
    Tetramino::DrawFantomTetramino(1, 12, 'Z', 270);
    Tetramino::DrawFantomTetramino(2, 14, 'I', 90);
    Tetramino::DrawFantomTetramino(0, 16, 'T', 270);

    Tetramino::DrawFantomTetramino(-1, 1, 'L', 0);
    Tetramino::DrawFantomTetramino(1, 1, 'Z', 0);
    Tetramino::DrawFantomTetramino(3, 1, 'O', 0);
    Tetramino::DrawFantomTetramino(6, 1, 'S', 0);
    Tetramino::DrawFantomTetramino(8, 0, 'I', 0);
    Tetramino::DrawFantomTetramino(11, 1, 'Z', 0);
    Tetramino::DrawFantomTetramino(13, 1, 'O', 0);
    Tetramino::DrawFantomTetramino(16, 1, 'S', 0);
    Tetramino::DrawFantomTetramino(17, 1, 'J', 0);

    Tetramino::DrawFantomTetramino(17, 3, 'T', 90);
    Tetramino::DrawFantomTetramino(21, 6, 'I', 90);
    Tetramino::DrawFantomTetramino(19, 9, 'Z', 270);
    Tetramino::DrawFantomTetramino(19, 12, 'S', 270);
    Tetramino::DrawFantomTetramino(21, 14, 'I', 90);
    Tetramino::DrawFantomTetramino(17, 16, 'T', 90);

    Tetramino::DrawFantomTetramino(2, 22, 'J', 180);
    Tetramino::DrawFantomTetramino(1, 19, 'S', 0);
    Tetramino::DrawFantomTetramino(3, 19, 'O', 0);
    Tetramino::DrawFantomTetramino(6, 19, 'Z', 0);
    Tetramino::DrawFantomTetramino(8, 19, 'I', 0);
    Tetramino::DrawFantomTetramino(11, 19, 'S', 0);
    Tetramino::DrawFantomTetramino(13, 19, 'O', 0);
    Tetramino::DrawFantomTetramino(16, 19, 'Z', 0);
    Tetramino::DrawFantomTetramino(20, 22, 'L', 180);

    Tetramino::DrawBigBlock(7, 15, 6, 2, 0.4, LIGHT_BLUE);

    Tetramino::DrawBigBlock(4, 12, 8, 1, 0.1, VIOLET);
    Tetramino::DrawBigBlock(4, 10, 8, 1, 0.1, VIOLET);
    Tetramino::DrawBigBlock(4, 8, 8, 1, 0.1, VIOLET);

    Tetramino::DrawBigBlock(3, 4, 14, 1.5, 0.2, YELLOW);
}

void display()
{
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

    Game_Show();
    if (AmountOfMiliseconds % millisecondsBeforeUpdate == 0)
    {
        if (!isLose)
        {
            if (!isPerspectiveMode)
            {
                BackGround_Show();

                TColor color(0, 0, 0);

                drawText(2.5, 18.5, "TETRIS  GAME", color);
                drawText(1, 13, "Score: ", color); drawText(7.8, 13, score, color);
                drawText(1, 11.5, "Speed: ", color); drawText(7.8, 11.5, ceil((650 - millisecondsBeforeUpdate) / 50), color);
                drawText(1, 10, "Time: ", color); drawText(7.8, 10, myTime.GetTime().c_str(), color);
                drawText(3.2, 5.5, "Next Figure", color);

                Tetramino::DrawFantomTetraminoForNext(3, 2.5, nextFigure);
            }
            DrawGrid();
            Tetramino::DrawTetramino(dx, 19 - dy++, nowFigure);
            isDxChanged = false;
            isRotateChanged = false;
        }
        else
        {
            TColor red(255, 0, 0);
            TColor yellow(255, 255, 0);
            TColor green(0, 255, 0);
            TColor black(0, 0, 0);
            LoseScreen();
            drawText(7.8, 15.8, "GAME  OVER!", red);
            drawText(4.5, 12.2, "Score: ", yellow); drawText(10, 12.2, score, green);
            drawText(4.5, 10.2, "Speed: ", yellow); drawText(10, 10.2, (650 - millisecondsBeforeUpdate) / 50, green);
            drawText(4.5, 8.2, "Time: ", yellow); drawText(10, 8.2, myTime.GetTime().c_str(), green);
            drawText(3.5, 4.5, "To restart game press \"Enter\"....", black);
        }

        glutSwapBuffers();
    }    
}

void AllKeyVariants(unsigned char& key)
{
    if      (key == 65 || key == 97  || key == 212 || key == 244) key = 65; // a
    else if (key == 68 || key == 100 || key == 194 || key == 226) key = 68; // d
    else if (key == 69 || key == 101 || key == 211 || key == 243) // e
    {
        if (nowFigure == 'S') key = 82;
        else key = 69;
    }  
    else if (key == 82 || key == 114 || key == 202 || key == 234) // r
    { 
        if (nowFigure == 'Z') key = 69;
        else key = 82;
    }  
    else if (key == 79 || key == 111 || key == 217 || key == 249) key = 79; // o
    else if (key == 80 || key == 112 || key == 199 || key == 231) key = 80; // p
}

void keyboardFunc(unsigned char key, int x, int y) {
    AllKeyVariants(key);

    int widthRight = Tetramino::GetNowFigureWidthRight(rotateMode, nowFigure);
    int widthLeft = Tetramino::GetNowFigureWidthLeft(rotateMode, nowFigure);

    int rotateRightAngle = rotateMode - 90 < 0 ? 270 : rotateMode - 90;
    int rotateLeftAngle = rotateMode + 90 > 270 ? 0 : rotateMode + 90;

    int widthRightRotateRight = Tetramino::GetNowFigureWidthRight(rotateRightAngle, nowFigure);
    int widthLeftRotateRight = Tetramino::GetNowFigureWidthLeft(rotateRightAngle, nowFigure);
    int widthRightRotateLeft = Tetramino::GetNowFigureWidthRight(rotateLeftAngle, nowFigure);
    int widthLeftRotateLeft = Tetramino::GetNowFigureWidthLeft(rotateLeftAngle, nowFigure);

    switch (key) {
    case 65: // a
        if (!isDxChanged && dx - widthLeft >= 0 && isLeftCellsEmpty)
        {
            dx--;
            isDxChanged = true;
        }
        break;
    case 68: // d
        if (!isDxChanged && dx + widthRight < 10 && isRightCellsEmpty)
        {
            dx++;
            isDxChanged = true;
        }
        break;
    case 82: // r
        if (!isRotateChanged && dx - widthLeftRotateRight >= 0 && dx + widthRightRotateRight <= 10 && map[dx - widthLeftRotateRight][19-dy].type == EMPTY && map[dx + widthRightRotateRight][19-dy].type == EMPTY && dy >= 2 && dy < 17)
        {
            rotateMode -= 90.0;
            if (rotateMode < 0) rotateMode = 270.0;
            isRotateChanged = true;
            dy--;
        }
        break;
    case 69: // e
        if (!isRotateChanged && dx - widthLeftRotateLeft >= 0 && dx + widthRightRotateLeft <= 10 && map[dx - widthLeftRotateLeft][19 - dy].type == EMPTY && map[dx + widthRightRotateLeft][19 - dy].type == EMPTY && dy >= 2 && dy < 17)
        {
            rotateMode += 90.0;
            if (rotateMode > 270.0) rotateMode = 0.0;
            isRotateChanged = true;
            dy--;
        }
        break;
    case 13: // Enter
        if (isLose)
        {
            millisecondsBeforeUpdate = 650;
            score = 0;
            dy = 0;
            dx = 5;
            rotateMode = 0;
            isDxChanged = false;
            isRotateChanged = false;
            isLose = false;
            nowFigure = Tetramino::RandomLetter();
            nextFigure = Tetramino::RandomLetter();
            for (int i = 0; i < mapW; i++)
            {
                for (int j = 0; j < mapH; j++)
                {
                    map[i][j].type = EMPTY;
                }
            }
            myTime = MyTime();
            
            angle = 0;
            AmountOfMiliseconds = 0;
        }
        break;
    case 32: // space
        if (!isLose) isPerspectiveMode = !isPerspectiveMode;
        break;
    case 79:
        if (isPerspectiveMode) angle -= 0.01f;
        break;
    case 80:
        if (isPerspectiveMode) angle += 0.01f;
        break;
    }
}

void timer(int value) {
    glutPostRedisplay();
    glutTimerFunc(10, timer, 0);
    AmountOfMiliseconds += 10;

    if (!isLose && AmountOfMiliseconds % millisecondsBeforeUpdate == 0) myTime.AddMiliseconds(millisecondsBeforeUpdate);
}

int main(int argc, char** argv)
{
    srand(time(NULL));

    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_DEPTH);

    glutInitWindowSize(windowSizeX, windowSizeY);
    glutInitWindowPosition(marginLeft, marginTop);
    glutCreateWindow("Tetris");

    if (isPerspectiveMode) glEnable(GL_DEPTH_TEST);

    glClearColor(0, 0, 0, 0);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    glOrtho(-1, 1, -1, 1, 0, 0);

    glutKeyboardFunc(keyboardFunc);

    glutDisplayFunc(display);
    glutTimerFunc(0, timer, 0);

    glutMainLoop();
    return 0;
}
