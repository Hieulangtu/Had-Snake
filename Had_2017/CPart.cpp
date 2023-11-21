#include "stdafx.h"
#include "CPart.h"

void CPart::Zobraz()
{
	//PrintXY(m_PoziceOld.x, m_PoziceOld.y, " ");
	//PrintXY(m_Pozice.x, m_Pozice.y, "o");
	gotoXY(m_PoziceOld.x, m_PoziceOld.y); printf(" ");
	//SetColor(2);
	gotoXY(m_Pozice.x, m_Pozice.y); printf("o");
}

void CPart::Zobrazd()
{
	//PrintXY(m_PoziceOld.x, m_PoziceOld.y, " ");
	//PrintXY(m_Pozice.x, m_Pozice.y, "0");
	gotoXY(m_PoziceOld.x, m_PoziceOld.y); printf(" ");
	//SetColor(2);
	gotoXY(m_Pozice.x, m_Pozice.y); printf("0");
}

void CPart::Pohni()
{
	m_PoziceOld = m_Pozice;
}

//void CPart::Pohni()
//{

//}

void CPart::Pohni1()
{
	m_PoziceOld = m_Pozice;
	m_Pozice.x--;
}

void CPart::Pohni2()
{
	m_PoziceOld = m_Pozice;
	m_Pozice.x++;
}

void CPart::Pohni3()
{
	m_PoziceOld = m_Pozice;
	m_Pozice.y--;
}

void CPart::Pohni4()
{
	m_PoziceOld = m_Pozice;
	m_Pozice.y++;
}

CPozice CPart::GetPozice()
{
	return m_Pozice;
}

CPart::CPart(int x, int y)
{
	m_Pozice.x = x;
	m_Pozice.y = y;

	//m_PoziceOld = m_Pozice;
}

CPart::CPart(CPozice pozice)
{
	m_Pozice = pozice;
}

CPart::CPart()
{
	m_Pozice.x = 0;
	m_Pozice.y = 0;
}

CPart::~CPart()
{
}
