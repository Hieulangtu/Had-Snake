// Had_2017.cpp : Defines the entry point for the console application.
//

#include <stdio.h>
#include "stdafx.h"
#include "CHad.h"
#include"CJablko.h"
#include"time.h"
#include"windows.h"

using namespace std;

HANDLE  hConsoleOut;                   /* Handle ke konzolovemu oknu */
CONSOLE_SCREEN_BUFFER_INFO csbiInfo;   /* informace o konzolovem okne */

void SetColor(WORD color)
{
	HANDLE hConsoleOutput;
	hConsoleOutput = GetStdHandle(STD_OUTPUT_HANDLE);

	CONSOLE_SCREEN_BUFFER_INFO screen_buffer_info;
	GetConsoleScreenBufferInfo(hConsoleOutput, &screen_buffer_info);

	WORD wAttributes = screen_buffer_info.wAttributes;//
	color &= 0x000f;
	wAttributes &= 0xfff0;
	wAttributes |= color;

	SetConsoleTextAttribute(hConsoleOutput, wAttributes);
}

//void set_color(int code) {
//	HANDLE color = GetStdHandle(STD_OUTPUT_HANDLE);
//	SetConsoleTextAttribute(color, code);
//}

void PrintXY(int x,int y,char *str) {
 COORD coord;
 DWORD written;

	coord.X=x;
	coord.Y=y;

	
	WriteConsoleOutputCharacter(hConsoleOut,str,(DWORD)strlen(str),coord,&written);

}

void gotoXY(int x, int y)
{
	HANDLE hConsoleOutput;
	COORD Cursor_an_Pos = { x, y };
	hConsoleOutput = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleCursorPosition(hConsoleOutput, Cursor_an_Pos);
}
//============== làm ẩn trỏ chuột ===========
void ShowCur(bool CursorVisibility)
{
	HANDLE handle = GetStdHandle(STD_OUTPUT_HANDLE);
	CONSOLE_CURSOR_INFO cursor = { 1, CursorVisibility };
	SetConsoleCursorInfo(handle, &cursor);
}

// *** smaze konzolovou obrazovku
void ClearScreen( void )
{
    DWORD    dummy;
    COORD    Home = { 0, 0 };
    FillConsoleOutputCharacter( hConsoleOut, ' ', csbiInfo.dwSize.X * csbiInfo.dwSize.Y, Home, &dummy );
}

void BuildWall() {
	for (int i = 1; i < 25; i++) {
		SetColor(11);
		gotoXY(0, i);
		printf_s("|");

		gotoXY(70, i);
		printf_s("|");


	}
	for (int i = 1; i < 70; i++) {
		SetColor(11);
		gotoXY(i, 1);
		printf_s("-");
		gotoXY(i, 24);
		printf_s("-");

	}
}

void BuildWallScore() {
	for (int i = 1; i < 6; i++) {
		SetColor(4);
		gotoXY(77, i);
		printf_s("+");

		gotoXY(94, i);
		printf_s("+");


	}
	for (int i = 77; i < 95; i++) {
		SetColor(4);
		gotoXY(i, 1);
		printf_s("+");
		gotoXY(i, 5);
		printf_s("+");

	}
}



int _tmain(int argc, _TCHAR* argv[])
{
	srand(time(NULL));

    /* Otevreme konzolove okno a ziskame informace o jejich parametrech.*/
    hConsoleOut = GetStdHandle( STD_OUTPUT_HANDLE );
    GetConsoleScreenBufferInfo( hConsoleOut, &csbiInfo );

	ClearScreen();

	int mode = 1;
	int speed = 5; //scanf_s("%d", &speed);
	gotoXY(45, 5); SetColor(4); printf_s("WELCOME TO SNAKE GAME ");
	Sleep(700);
	gotoXY(47, 7); SetColor(7); printf_s("LET'S CHOODE MODE ");
	Sleep(700);
	SetColor(6);
	gotoXY(35, 9); printf_s("CLASSIC - PRESS 1");
	gotoXY(60, 9); printf_s("MODERN MODE - PRESS 2");
	
	while (!_kbhit());
	int znak1;
	if (_kbhit()) {
		znak1 = _getch();
		if (znak1 == '1') {
			mode = 1;
			gotoXY(60, 9); printf_s("                     ");
		}
		if (znak1 == '2') {
			mode = 2;
			gotoXY(35, 9); printf_s("                  ");
		}
	}
	Sleep(500);
	gotoXY(44, 11); SetColor(7); printf_s("LET CHOOSE SPEED FROM 1 TO 8 "); Sleep(800);
	gotoXY(47, 12); SetColor(6); printf_s("1 2 3 4 5 6 7 8");
	int znak2;
	
	while (!_kbhit()); //quan trong
	
	if (_kbhit()) {
			znak2 = _getch();
			if (znak2 == '1') speed = 1;
			if (znak2 == '2') speed = 2;
			if (znak2 == '3') speed = 3;
			if (znak2 == '4') speed = 4;
			if (znak2 == '5') speed = 5;
			if (znak2 == '6') speed = 6;
			if (znak2 == '7') speed = 7;
			if (znak2 == '8') speed = 8;
	}
	//gotoXY(55, 13); SetColor(9); printf("%d", speed);
	do {
		gotoXY(55, 13); SetColor(rand()%16); printf_s("%d", speed);
		ShowCur(false);
	} while (!_kbhit());
	Sleep(400);
	gotoXY(50, 15); SetColor(12); printf_s("LET'S START ! ");
	/*
	for (int i = 1; i < 25; i++) {
		SetColor(11);
		PrintXY(0, i, "|");
		PrintXY(70, i, "|");
		
	}
	for (int i = 1; i < 70; i++) {
		SetColor(11);
		PrintXY(i, 1, "-");
		PrintXY(i,24 , "-");
	}
	*/
	
	
	Sleep(2000);
	gotoXY(45, 5); printf_s("                              ");
	gotoXY(47, 7); printf_s("                     ");
	gotoXY(35, 9); printf_s("                                ");
	gotoXY(60, 9); printf_s("                         ");
	gotoXY(44, 11); printf_s("                              "); 
	gotoXY(47, 12); printf_s("                          ");
	gotoXY(55, 13); printf_s("                             ");
	gotoXY(50, 15); printf_s("                                 ");
	bool again = true;
	do {
		CHad Snake;
		Snake.GenerujPart(2);
		bool konec = false;
		
		CJablko apple;

		Snake.GenerujJablko(&apple);

		gotoXY(1, 26); SetColor(7); printf("TRY YOUR BEST - GOOD LUCK");
		do {
			//system("cls");


			konec = Snake.Pohni();
			Snake.Zobraz();

			apple.m_color = rand() % 15 + 1;
			apple.Zobraz();

			if (Snake.EatApple(&apple)&&apple.m_color!=0) {
				Snake.m_color = apple.m_color;
			};

			if (Snake.ZkontrojJistSebe()) {
				PrintXY(74, 7, "SNAKE EATS HIMSELF . YOU LOSE ! ");
				konec = true;
			}
			if (Snake.Hitwall() && mode == 2) {
				PrintXY(74, 7, "SNAKE HITS WALL . YOU LOSE ! ");
				konec = true;
			}

			BuildWall();
			BuildWallScore();

			Sleep(180 - (speed * 20));
			
			ShowCur(false);

		} while (konec == false);
		while (!_kbhit()); int znak4 = _getch();
		gotoXY(35, 12); SetColor(7); printf_s("DO YOU WANNA PLAY AGAIN ? PRESS SPACE TO CONTINUE ");
		while (!_kbhit()); 
		int znak3;
		if (_kbhit()) {
			znak3 = _getch();
			if (znak3 == ' ') { 
				again = true;
				system("cls");
			}
			else again = false;
		}
	} while(again == true);
	//
	SetColor(11);
	//printf("Stiskni cokoliv pro ukonceni aplikace ...\n");
	while (!_kbhit());
	

   return 0;
}
