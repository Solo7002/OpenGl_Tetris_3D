#pragma once

#include "GlobalVariables.h"
using namespace Global;

class Tetramino
{
public:
	static void DrawTetramino_I(int x, int y, int rotate);
	static void DrawTetramino_J(int x, int y, int rotate);
	static void DrawTetramino_L(int x, int y, int rotate);
	static void DrawTetramino_O(int x, int y, int rotate);
	static void DrawTetramino_S(int x, int y, int rotate);
	static void DrawTetramino_T(int x, int y, int rotate);
	static void DrawTetramino_Z(int x, int y, int rotate);
	static void DrawTetramino(int x, int y, char type);

	static void DrawBlock(double x, double y, ColorType colorType);
	static void DrawBigBlock(double x, double y, double width, double height, double volume, ColorType colorType);
	static void DrawFantomTetramino(int x, int y, char type, int rotate);
	static void DrawFantomTetraminoForNext(int x, int y, char type);

	static char RandomLetter(); 
	static int GetNowFigureWidthRight(int rotate, char figure);
	static int GetNowFigureWidthLeft(int rotate, char figure);

	static void ClearAllNew();
	static void AllNewToOld();
	static void DrawAllOldAndNew();
	
	static int CheckIfLineFull();
	static void ClearFullLine(int lineNumber);

	static void LoseGame();
};

