#pragma once
#include "printxy.h"
#include "pozice.h"

class CLod
{
	CPozice m_Pozice;
	CPozice m_PoziceOld;

public:
	void Zobraz();
	bool Pohni();
	CLod(void);
	~CLod(void);
};
