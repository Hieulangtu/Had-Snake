#pragma once
#include"Pozice.h"
#include"printxy.h"
#include"CPart.h"
#include <vector>
#include"CJablko.h"



#define DOLEVA 0;
#define DOPRAVA 1;
#define NAHORU 2;
#define DOLU 3;

using namespace std;

class CHad
{
	vector <CPart> Had;
	int m_Smer;
	int m_Score;
	
private:
	void VytorPart(int x,int y);
public:
	int m_color = 2;
	void Zobraz();
	bool Pohni();
	void GenerujPart(int pocet);
	void GetPartpozice();

	bool ZkontrojJablko(CJablko* jablko);

	void GenerujJablko(CJablko* jablko);

	bool EatApple(CJablko* jablko);

	bool ZkontrojJistSebe();
	
	bool Hitwall();

	CHad();
	~CHad();
};

