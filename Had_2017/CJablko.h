#pragma once
#include"Pozice.h"
#include"printxy.h"
#include<vector>

using namespace std;

class CJablko
{
private:
	CPozice m_Pozice;
	//CPozice m_PoziceOld;
public:
	int m_color;
	void Zobraz();
	bool Pohni();
	CPozice GetPozice();
	void VytvorJablko();

	CJablko(int x, int y);
	CJablko();
		
};

