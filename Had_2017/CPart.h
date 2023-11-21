#pragma once
#include"Pozice.h"
#include"printxy.h"
class CPart
{
//private:
public:

	CPozice m_Pozice;
	CPozice m_PoziceOld;
public:
	void Zobraz();
	void Zobrazd();
	void Pohni();
	void Pohni1();
	void Pohni2();
	void Pohni3();
	void Pohni4();
	CPozice GetPozice();
	CPart(int x, int y);
	CPart(CPozice pozice);
	CPart();
	~CPart();
	
};

