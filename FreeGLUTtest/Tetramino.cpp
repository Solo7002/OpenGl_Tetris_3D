#include "Tetramino.h"
#define _USE_MATH_DEFINES
#include <math.h>

struct Point {
	double x;
	double y; 
	
	Point() : x(0.0), y(0.0) {}

	Point(double xCord, double yCord) : x(xCord), y(yCord) {}

	Point& operator=(const Point& other) {
		if (this != &other) {
			x = other.x;
			y = other.y;
		}
		return *this;
	}
};

int MySin(double degrees)
{
	if (degrees == 0) return 0;
	if (degrees == 90) return 1;
	if (degrees == 180) return 0;
	if (degrees == 270) return -1;
}

int MyCos(double degrees)
{
	if (degrees == 0) return 1;
	if (degrees == 90) return 0;
	if (degrees == 180) return -1;
	if (degrees == 270) return 0;
}

Point rotatePoint(const Point& A, const Point& O, double alphaDegrees) {
	Point A1;
	A1.x = (A.x - O.x) * MyCos(alphaDegrees) - (A.y - O.y) * MySin(alphaDegrees) + O.x;
	A1.y = (A.x - O.x) * MySin(alphaDegrees) + (A.y - O.y) * MyCos(alphaDegrees) + O.y;
	return A1;
}

void Change_X_Y(int& _x, int& _y, int x, int y, Point O, int rotate)
{
	Point A = Point(x, y);
	Point A1 = rotatePoint(A, O, rotate);
	
	_x = (int)A1.x;
	_y = (int)A1.y;
}

void Tetramino::DrawTetramino_I(int x, int y, int rotate)
{
	Point O(x, y - 2);
	int _x = 0, _y = 0;

	for (int i = 0; i < 4; i++)
	{
		Change_X_Y(_x, _y, x, y - i, O, rotate);

		if (_y == -1 || map[_x][_y].type == OLD_FIGURE)
		{
			Tetramino::AllNewToOld();
			return;
		}
		else if (map[_x + 1][_y - 1].type == OLD_FIGURE) isRightCellsEmpty = false;
		else if (map[_x - 1][_y - 1].type == OLD_FIGURE) isLeftCellsEmpty = false;
	}

	ClearAllNew();

	ColorType colorType = LIGHT_BLUE;

	for (int i = 0; i < 4; i++)
	{
		Change_X_Y(_x, _y, x, y - i, O, rotate);

		map[_x][_y].color = colorType;
		map[_x][_y].type = NEW_FIGURE;
	}
}

void Tetramino::DrawTetramino_J(int x, int y, int rotate)
{
	Point O(x, y - 2);
	int _x = 0, _y = 0;

	for (int i = 0; i < 3; i++)
	{
		Change_X_Y(_x, _y, x, y - i, O, rotate);

		if (_y == -1 || map[_x][_y].type == OLD_FIGURE)
		{
			Tetramino::AllNewToOld();
			return;
		}
		else if (map[_x + 1][_y - 1].type == OLD_FIGURE) isRightCellsEmpty = false;
		else if (map[_x - 1][_y - 1].type == OLD_FIGURE) isLeftCellsEmpty = false;
	}
	Change_X_Y(_x, _y, x - 1, y - 2, O, rotate);

	if (_y == -1 || map[_x][_y].type == OLD_FIGURE)
	{
		Tetramino::AllNewToOld();
		return;
	}
	else if (map[_x + 1][_y - 1].type == OLD_FIGURE) isRightCellsEmpty = false;
	else if (map[_x - 1][_y - 1].type == OLD_FIGURE) isLeftCellsEmpty = false;

	ClearAllNew();

	ColorType colorType = DARK_BLUE;

	for (int i = 0; i < 3; i++)
	{
		Change_X_Y(_x, _y, x, y - i, O, rotate);

		map[_x][_y].color = colorType;
		map[_x][_y].type = NEW_FIGURE;
	}
	Change_X_Y(_x, _y, x - 1, y - 2, O, rotate);

	map[_x][_y].color = colorType;
	map[_x][_y].type = NEW_FIGURE;
}

void Tetramino::DrawTetramino_L(int x, int y, int rotate)
{
	Point O(x, y-2);
	int _x = 0, _y = 0;

	for (int i = 0; i < 3; i++)
	{
		Change_X_Y(_x, _y, x, y - i, O, rotate);

		if (_y == -1 || map[_x][_y].type == OLD_FIGURE)
		{
			Tetramino::AllNewToOld();
			return;
		}
		else if (map[_x + 1][_y - 1].type == OLD_FIGURE) isRightCellsEmpty = false;
		else if (map[_x - 1][_y - 1].type == OLD_FIGURE) isLeftCellsEmpty = false;
	}
	Change_X_Y(_x, _y, x + 1, y - 2, O, rotate);
	if (_y == -1 || map[_x][_y].type == OLD_FIGURE)
	{
		Tetramino::AllNewToOld();
		return;
	}
	else if (map[_x + 1][_y - 1].type == OLD_FIGURE) isRightCellsEmpty = false;
	else if (map[_x - 1][_y - 1].type == OLD_FIGURE) isLeftCellsEmpty = false;

	ClearAllNew();

	ColorType colorType = ORANGE;

	for (int i = 0; i < 3; i++)
	{
		Change_X_Y(_x, _y, x, y - i, O, rotate);
		map[_x][_y].color = colorType;
		map[_x][_y].type = NEW_FIGURE;
	}
	Change_X_Y(_x, _y, x + 1, y - 2, O, rotate);
	map[_x][_y].color = colorType;
	map[_x][_y].type = NEW_FIGURE;
}

void Tetramino::DrawTetramino_O(int x, int y, int rotate)
{
	for (int i = 0; i < 2; i++)
	{
		if (y - i == -1 || map[x][y - i].type == OLD_FIGURE)
		{
			Tetramino::AllNewToOld();
			return;
		}
		else if (map[x + 1][y - i - 1].type == OLD_FIGURE) isRightCellsEmpty = false;
		else if (map[x - 1][y - i - 1].type == OLD_FIGURE) isLeftCellsEmpty = false;
	}
	for (int i = 0; i < 2; i++)
	{
		if (y - i == -1 || map[x + 1][y - i].type == OLD_FIGURE)
		{
			Tetramino::AllNewToOld();
			return;
		}
		else if (map[x + 2][y - i - 1].type == OLD_FIGURE) isRightCellsEmpty = false;
		else if (map[x][y - i - 1].type == OLD_FIGURE) isLeftCellsEmpty = false;
	}

	ClearAllNew();

	ColorType colorType = YELLOW;

	for (int i = 0; i < 2; i++)
	{
		map[x][y - i].color = colorType;
		map[x][y - i].type = NEW_FIGURE;
	}
	for (int i = 0; i < 2; i++)
	{
		map[x + 1][y - i].color = colorType;
		map[x + 1][y - i].type = NEW_FIGURE;
	}
}

void Tetramino::DrawTetramino_S(int x, int y, int rotate)
{
	Point O(x, y);
	int _x = 0, _y = 0;

	for (int i = 0; i < 2; i++)
	{
		Change_X_Y(_x, _y, x + i, y, O, rotate);
		if (_y == -1 || map[_x][_y].type == OLD_FIGURE)
		{
			Tetramino::AllNewToOld();
			return;
		}
		else if (map[_x + 1][_y - 1].type == OLD_FIGURE) isRightCellsEmpty = false;
		else if (map[_x - 1][_y - 1].type == OLD_FIGURE) isLeftCellsEmpty = false;
	}
	for (int i = 0; i < 2; i++)
	{
		Change_X_Y(_x, _y, x - 1 + i, y - 1, O, rotate);
		if (_y == -1 || map[_x][_y].type == OLD_FIGURE)
		{
			Tetramino::AllNewToOld();
			return;
		}
		else if (map[_x + 1][_y - 1].type == OLD_FIGURE) isRightCellsEmpty = false;
		else if (map[_x - 1][_y - 1].type == OLD_FIGURE) isLeftCellsEmpty = false;
	}

	ClearAllNew();

	ColorType colorType = GREEN;

	for (int i = 0; i < 2; i++)
	{
		Change_X_Y(_x, _y, x + i, y, O, rotate);
		map[_x][_y].color = colorType;
		map[_x][_y].type = NEW_FIGURE;
	}
	for (int i = 0; i < 2; i++)
	{
		Change_X_Y(_x, _y, x - 1 + i, y - 1, O, rotate);
		map[_x][_y].color = colorType;
		map[_x][_y].type = NEW_FIGURE;
	}
}

void Tetramino::DrawTetramino_T(int x, int y, int rotate)
{
	Point O(x+1, y);
	int _x = 0, _y = 0;

	Change_X_Y(_x, _y, x + 1, y - 1, O, rotate);
	if (_y == -1 || map[_x][_y].type == OLD_FIGURE)
	{
		Tetramino::AllNewToOld();
		return;
	}
	else if (map[_x + 1][_y - 1].type == OLD_FIGURE) isRightCellsEmpty = false;
	else if (map[_x - 1][_y - 1].type == OLD_FIGURE) isLeftCellsEmpty = false;
	for (int i = 0; i < 3; i++)
	{	
		Change_X_Y(_x, _y, x + i, y, O, rotate);
		if (_y == -1 || map[_x][_y].type == OLD_FIGURE)
		{
			Tetramino::AllNewToOld();
			return;
		}
		else if (map[_x + 1][_y - 1].type == OLD_FIGURE) isRightCellsEmpty = false;
		else if (map[_x - 1][_y - 1].type == OLD_FIGURE) isLeftCellsEmpty = false;
	}

	ClearAllNew();

	ColorType colorType = VIOLET;

	Change_X_Y(_x, _y, x + 1, y - 1, O, rotate);
	map[_x][_y].color = colorType;
	map[_x][_y].type = NEW_FIGURE;
	for (int i = 0; i < 3; i++)
	{
		Change_X_Y(_x, _y, x + i, y, O, rotate);
		map[_x][_y].color = colorType;
		map[_x][_y].type = NEW_FIGURE;
	}
}

void Tetramino::DrawTetramino_Z(int x, int y, int rotate)
{
	Point O(x, y);
	int _x = 0, _y = 0;

	for (int i = 0; i < 2; i++)
	{
		Change_X_Y(_x, _y, x - 1 + i, y, O, rotate);
		if (_y == -1 || map[_x][_y].type == OLD_FIGURE)
		{
			Tetramino::AllNewToOld();
			return;
		}
		else if (map[_x + 1][_y - 1].type == OLD_FIGURE) isRightCellsEmpty = false;
		else if (map[_x - 1][_y - 1].type == OLD_FIGURE) isLeftCellsEmpty = false;
	}
	for (int i = 0; i < 2; i++)
	{
		Change_X_Y(_x, _y, x + i, y - 1, O, rotate);
		if (_y == -1 || map[_x][_y].type == OLD_FIGURE)
		{
			Tetramino::AllNewToOld();
			return;
		}
		else if (map[_x + 1][_y - 1].type == OLD_FIGURE) isRightCellsEmpty = false;
		else if (map[_x - 1][_y - 1].type == OLD_FIGURE) isLeftCellsEmpty = false;
	}

	ClearAllNew();

	ColorType colorType = RED;

	for (int i = 0; i < 2; i++)
	{
		Change_X_Y(_x, _y, x - 1 + i, y, O, rotate);
		map[_x][_y].color = colorType;
		map[_x][_y].type = NEW_FIGURE;
	}
	for (int i = 0; i < 2; i++)
	{
		Change_X_Y(_x, _y, x + i, y - 1, O, rotate);
		map[_x][_y].color = colorType;
		map[_x][_y].type = NEW_FIGURE;
	}
}

void Tetramino::DrawTetramino(int x, int y, char type)
{
	isRightCellsEmpty = isLeftCellsEmpty = true;
	switch (type)
	{
	case 'I':
		Tetramino::DrawTetramino_I(x, y, rotateMode);
		break;
	case 'J':
		Tetramino::DrawTetramino_J(x, y, rotateMode);
		break;
	case 'L':
		Tetramino::DrawTetramino_L(x, y, rotateMode);
		break;
	case 'O':
		Tetramino::DrawTetramino_O(x, y, rotateMode);
		break;
	case 'S':
		Tetramino::DrawTetramino_S(x, y, rotateMode);
		break;
	case 'T':
		Tetramino::DrawTetramino_T(x, y, rotateMode);
		break;
	case 'Z':
		Tetramino::DrawTetramino_Z(x, y, rotateMode);
		break;
	}

	Tetramino::DrawAllOldAndNew();
}

void Tetramino::DrawBlock(double x, double y, ColorType colorType)
{
	SetOfColors setOfColors(colorType);
	SetOfColors setOfColors2(YELLOW);
	SetOfColors setOfColors3(VIOLET);

	glBegin(GL_TRIANGLE_STRIP); // bottom
	glColor3f(setOfColors.backColor.red, setOfColors.backColor.green, setOfColors.backColor.blue);
	glVertex3f(x, y, 0);
	glVertex3f(x + 1, y, 0);
	glVertex3f(x, y, 1);
	glVertex3f(x + 1, y, 1);
	glEnd();

	glBegin(GL_TRIANGLE_STRIP); // top
	glColor3f(setOfColors.sideColor.red, setOfColors.sideColor.green, setOfColors.sideColor.blue);
	glVertex3f(x, y + 1, 0);
	glVertex3f(x + 1, y + 1, 0);
	glVertex3f(x, y + 1, 1);
	glVertex3f(x + 1, y + 1, 1);
	glEnd();

	glBegin(GL_TRIANGLE_STRIP); // back
	glColor3f(setOfColors.frontColor.red, setOfColors.frontColor.green, setOfColors.frontColor.blue);
	glVertex3f(x, y, 0);
	glVertex3f(x, y + 1, 0);
	glVertex3f(x + 1, y, 0);
	glVertex3f(x + 1, y + 1, 0);
	glEnd();

	glBegin(GL_TRIANGLE_STRIP); // left
	glColor3f(setOfColors.sideColor.red, setOfColors.sideColor.green, setOfColors.sideColor.blue);
	glVertex3f(x, y, 0);
	glVertex3f(x, y + 1, 0);
	glVertex3f(x, y, 1);
	glVertex3f(x, y + 1, 1);
	glEnd();

	glBegin(GL_TRIANGLE_STRIP); // right
	glColor3f(setOfColors.backColor.red, setOfColors.backColor.green, setOfColors.backColor.blue);
	glVertex3f(x + 1, y, 0);
	glVertex3f(x + 1, y + 1, 0);
	glVertex3f(x + 1, y, 1);
	glVertex3f(x + 1, y + 1, 1);
	glEnd();


	// ----------------------------------------------------
	// front

	glBegin(GL_TRIANGLE_STRIP);
	glColor3f(setOfColors.sideColor.red, setOfColors.sideColor.green, setOfColors.sideColor.blue);
	glVertex3f(x, y, 1);
	glVertex3f(x, y + 1, 1);
	glVertex3f(x + 1, y + 1, 1);
	glEnd();

	glBegin(GL_TRIANGLE_STRIP);
	glColor3f(setOfColors.backColor.red, setOfColors.backColor.green, setOfColors.backColor.blue);
	glVertex3f(x, y, 1);
	glVertex3f(x + 1, y, 1);
	glVertex3f(x + 1, y + 1, 1);
	glEnd();

	float volume = 0.1f;
	float addPerspective = isPerspectiveMode ? 0.01f : 0;

	glBegin(GL_TRIANGLE_STRIP);
	glColor3f(setOfColors.frontColor.red, setOfColors.frontColor.green, setOfColors.frontColor.blue);
	glVertex3f(x + volume, y + volume, 1 + addPerspective);
	glVertex3f(x + volume, y - volume + 1, 1 + addPerspective);
	glVertex3f(x - volume + 1, y + volume, 1 + addPerspective);
	glVertex3f(x - volume + 1, y - volume + 1, 1 + addPerspective);
	glEnd();
}

void Tetramino::DrawBigBlock(double x, double y, double width, double height, double volume, ColorType colorType)
{
	SetOfColors setOfColors(colorType);

	glBegin(GL_TRIANGLE_STRIP);
	glColor3f(setOfColors.sideColor.red, setOfColors.sideColor.green, setOfColors.sideColor.blue);
	glVertex2f(x, y);
	glVertex2f(x, y + height);
	glVertex2f(x + width, y + height);
	glEnd();

	glBegin(GL_TRIANGLE_STRIP);
	glColor3f(setOfColors.backColor.red, setOfColors.backColor.green, setOfColors.backColor.blue);
	glVertex2f(x, y);
	glVertex2f(x + width, y);
	glVertex2f(x + width, y + height);
	glEnd();

	double volumeForWidth;
	double volumeForHeight;

	if ((width / height) > 0)
	{
		volumeForWidth = volume;
		volumeForHeight = height / width * volume;
	}
	else if((height / width) > 0)
	{
		volumeForWidth = width / height * volume;
		volumeForHeight = volume;
	}
	else
	{
		volumeForWidth = volume;
		volumeForHeight = volume;
	}

	glBegin(GL_TRIANGLE_STRIP);
	glColor3f(setOfColors.frontColor.red, setOfColors.frontColor.green, setOfColors.frontColor.blue);
	glVertex2f(x + volumeForWidth, y + volumeForHeight);
	glVertex2f(x + volumeForWidth, y - volumeForHeight + height);
	glVertex2f(x - volumeForWidth + width, y + volumeForHeight);
	glVertex2f(x - volumeForWidth + width, y - volumeForHeight + height);
	glEnd();
}

void Tetramino::DrawFantomTetramino(int x, int y, char type, int rotate)
{
	Point O;
	int _x = 0; 
	int _y = 0;
	switch (type)
	{
	case 'I':
		O = Point(x, y - 2);
		for (int i = 0; i < 4; i++)
		{
			Change_X_Y(_x, _y, x + i, y, O, rotate);
			Tetramino::DrawBlock(_x, _y, LIGHT_BLUE);
		}
		break;
	case 'J':
		O = Point(x, y - 2);
		for (int i = 0; i < 3; i++)
		{
			Change_X_Y(_x, _y, x + 2, y - 1 + i, O, rotate);
			Tetramino::DrawBlock(_x, _y, DARK_BLUE);
		}
		Change_X_Y(_x, _y, x + 1, y - 1, O, rotate);
		Tetramino::DrawBlock(_x, _y, DARK_BLUE);
		break;
	case 'L':
		O = Point(x, y - 2);
		for (int i = 0; i < 3; i++)
		{
			Change_X_Y(_x, _y, x + 1, y - 1 + i, O, rotate);
			Tetramino::DrawBlock(_x, _y, ORANGE);
		}
		Change_X_Y(_x, _y, x + 2, y - 1, O, rotate);
		Tetramino::DrawBlock(_x, _y, ORANGE);
		break;
	case 'O':
		for (int i = 0; i < 2; i++)
		{
			Tetramino::DrawBlock(x + 1 + i, y, YELLOW);
		}
		for (int i = 0; i < 2; i++)
		{
			Tetramino::DrawBlock(x + 1 + i, y - 1, YELLOW);
		}
		break;
	case 'S':
		O = Point(x, y);
		for (int i = 0; i < 2; i++)
		{
			Change_X_Y(_x, _y, x + 1 + i, y, O, rotate);
			Tetramino::DrawBlock(_x, _y, GREEN);
		}
		for (int i = 0; i < 2; i++)
		{
			Change_X_Y(_x, _y, x + i, y - 1, O, rotate);
			Tetramino::DrawBlock(_x, _y, GREEN);
		}
		break;
	case 'T':
		O = Point(x + 1, y);
		for (int i = 0; i < 3; i++)
		{
			Change_X_Y(_x, _y, x + i, y, O, rotate);
			Tetramino::DrawBlock(_x, _y, VIOLET);
		}
		Change_X_Y(_x, _y, x + 1, y - 1, O, rotate);
		Tetramino::DrawBlock(_x, _y, VIOLET);
		break;
	case 'Z':
		O = Point(x, y);
		for (int i = 0; i < 2; i++)
		{
			Change_X_Y(_x, _y, x + i, y, O, rotate);
			Tetramino::DrawBlock(_x, _y, RED);
		}
		for (int i = 0; i < 2; i++)
		{
			Change_X_Y(_x, _y, x + 1 + i, y - 1, O, rotate);
			Tetramino::DrawBlock(_x, _y, RED);
		}
		break;
	}
}

void Tetramino::DrawFantomTetraminoForNext(int x, int y, char type)
{
	switch (type)
	{
	case 'I':
		for (int i = 0; i < 4; i++)
		{
			Tetramino::DrawBlock(x + i, y, LIGHT_BLUE);
		}
		break;
	case 'J':
		for (int i = 0; i < 3; i++)
		{
			Tetramino::DrawBlock(x + 2, y - 1 + i, DARK_BLUE);
		}
		Tetramino::DrawBlock(x + 1, y - 1, DARK_BLUE);
		break;
	case 'L':
		for (int i = 0; i < 3; i++)
		{
			Tetramino::DrawBlock(x + 1, y - 1 + i, ORANGE);
		}
		Tetramino::DrawBlock(x + 2, y - 1, ORANGE);
		break;
	case 'O':
		for (int i = 0; i < 2; i++)
		{
			Tetramino::DrawBlock(x + 1 + i, y + 0.5, YELLOW);
		}
		for (int i = 0; i < 2; i++)
		{
			Tetramino::DrawBlock(x + 1 + i, y - 0.5, YELLOW);
		}
		break;
	case 'S':
		for (int i = 0; i < 2; i++)
		{
			Tetramino::DrawBlock(x + 1.5 + i, y + 0.5, GREEN);
		}
		for (int i = 0; i < 2; i++)
		{
			Tetramino::DrawBlock(x + 0.5 + i, y - 0.5, GREEN);
		}
		break;
	case 'T':
		for (int i = 0; i < 3; i++)
		{
			Tetramino::DrawBlock(x + 0.5 + i, y + 0.5, VIOLET);
		}
		Tetramino::DrawBlock(x + 1.5, y - 0.5, VIOLET);
		break;
	case 'Z':
		for (int i = 0; i < 2; i++)
		{
			Tetramino::DrawBlock(x + 0.5 + i, y + 0.5, RED);
		}
		for (int i = 0; i < 2; i++)
		{
			Tetramino::DrawBlock(x + 1.5 + i, y - 0.5, RED);
		}
		break;
	}
}

char Tetramino::RandomLetter()
{
	char letters[] = { 'I', 'J', 'L', 'O', 'S', 'T', 'Z' };
	int index = rand() % 7;
	return letters[index];
}

int Tetramino::GetNowFigureWidthRight(int rotate, char figure)
{
	switch (figure)
	{
	case 'I':
		if (rotate == 0) return 1;
		if (rotate == 90) return 2;
		if (rotate == 180) return 1;
		if (rotate == 270) return 3;
	case 'J':
		if (rotate == 0) return 1;
		if (rotate == 90) return 1;
		if (rotate == 180) return 2;
		if (rotate == 270) return 3;
	case 'L':
		if (rotate == 0) return 2;
		if (rotate == 90) return 1;
		if (rotate == 180) return 1;
		if (rotate == 270) return 3;
	case 'O':
		return 2;
	case 'S':
		if (rotate == 0) return 2;
		if (rotate == 90) return 2;
		if (rotate == 180) return 2;
		if (rotate == 270) return 1;
	case 'T':
		if (rotate == 0) return 3;
		if (rotate == 90) return 3;
		if (rotate == 180) return 3;
		if (rotate == 270) return 2;
	case 'Z':
		if (rotate == 0) return 2;
		if (rotate == 90) return 2;
		if (rotate == 180) return 2;
		if (rotate == 270) return 1;
	}
	return 1;
}

int Tetramino::GetNowFigureWidthLeft(int rotate, char figure)
{
	switch (figure)
	{
	case 'I':
		if (rotate == 0) return 1;
		if (rotate == 90) return 3;
		if (rotate == 180) return 1;
		if (rotate == 270) return 2;
	case 'J':
		if (rotate == 0) return 2;
		if (rotate == 90) return 3;
		if (rotate == 180) return 1;
		if (rotate == 270) return 1;
	case 'L':
		if (rotate == 0) return 1;
		if (rotate == 90) return 3;
		if (rotate == 180) return 2;
		if (rotate == 270) return 1;
	case 'O':
		return 1;
	case 'S':
		if (rotate == 0) return 2;
		if (rotate == 90) return 1;
		if (rotate == 180) return 2;
		if (rotate == 270) return 2;
	case 'T':
		if (rotate == 0) return 1;
		if (rotate == 90) return 0;
		if (rotate == 180) return 1;
		if (rotate == 270) return 1;
	case 'Z':
		if (rotate == 0) return 2;
		if (rotate == 90) return 1;
		if (rotate == 180) return 2;
		if (rotate == 270) return 2;
	}
	return 1;
}

void Tetramino::ClearAllNew()
{
	int sum = 4;

	for (int i = 0; i < mapW; i++)
	{
		for (int j = 0; j < mapH; j++)
		{
			if (map[i][j].type == NEW_FIGURE)
			{
				map[i][j].type = EMPTY;

				if (--sum == 0)
				{
					return;
				}
			}
		}
	}
}

void Tetramino::AllNewToOld()
{
	for (int i = 0; i < mapW; i++)
	{
		for (int j = 0; j < mapH; j++)
		{
			if (map[i][j].type == NEW_FIGURE)
			{
				map[i][j].type = OLD_FIGURE;
				if (j > 16)
				{
					Tetramino::LoseGame();
				}
			}
		}
	}

	int fullLineNumber = Tetramino::CheckIfLineFull();

	if (fullLineNumber != -1)
	{
		Tetramino::ClearFullLine(fullLineNumber);
	}

	nowFigure = nextFigure;
	nextFigure = Tetramino::RandomLetter();
	dy = 0;
	dx = 5;
	rotateMode = 0;
}

void Tetramino::DrawAllOldAndNew()
{
	for (int i = 0; i < mapW; i++)
	{
		for (int j = 0; j < mapH; j++)
		{
			if (map[i][j].type != EMPTY)
			{
				ColorType colorType = map[i][j].color;
				Tetramino::DrawBlock(10 + i, j, colorType);
			}
		}
	}
}

int Tetramino::CheckIfLineFull()
{
	for (int j = 0; j < mapH; j++)
	{
		int sum = 0;
		for (int i = 0; i < mapW; i++)
		{
			if (map[i][j].type == OLD_FIGURE)
			{
				if (++sum == 10)
				{
					return j;
				}
			}
		}
	}

	return -1;
}

void Tetramino::ClearFullLine(int lineNumber)
{
	for (int i = 0; i < mapW; i++)
	{
		map[i][lineNumber].type = EMPTY;
	}

	for (int i = 0; i < mapW; i++)
	{
		for (int j = lineNumber; j < mapH; j++)
		{
			if (map[i][j].type == OLD_FIGURE && j != 0)
			{
				map[i][j - 1].type = OLD_FIGURE;
				map[i][j - 1].color = map[i][j].color;

				map[i][j].type = EMPTY;
			}
		}
	}
	score += 5 + ((700 - millisecondsBeforeUpdate) / 50);

	int newLineNumber = Tetramino::CheckIfLineFull();
	if (newLineNumber != -1)
	{
		Tetramino::ClearFullLine(newLineNumber);
	}
}

void Tetramino::LoseGame()
{
	isLose = true;
	isPerspectiveMode = false;
}