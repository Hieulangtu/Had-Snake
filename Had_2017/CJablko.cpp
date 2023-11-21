#include "stdafx.h"
#include "CJablko.h"

void CJablko::Zobraz()
{
	//PrintXY(m_Pozice.x, m_Pozice.y, "a");
	gotoXY(m_Pozice.x, m_Pozice.y);
	SetColor(m_color);
	printf("a");
}

bool CJablko::Pohni()
{
	return false;
}

CPozice CJablko::GetPozice()
{
	return(m_Pozice);
}

void CJablko::VytvorJablko()
{
	m_Pozice.x = rand() % 49 + 1;
	m_Pozice.y = rand() % 22 + 2;
}

CJablko::CJablko(int x, int y)
{
	m_Pozice.x = x;
	m_Pozice.y = y;

}

CJablko::CJablko()
{
}
