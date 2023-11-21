#include "StdAfx.h"
#include "Lod.h"

CLod::CLod(void)
{
	m_Pozice.y=24;
}

CLod::~CLod(void)
{
}

bool CLod::Pohni() {
	int znak;

	if (_kbhit()) { // kontrolujeme zda byla stisknuta klavesa
		znak=_getch(); // nacteme co bylo stisknuto
		m_PoziceOld=m_Pozice;
		if (znak=='a') m_Pozice.x--;
		if (znak=='d') m_Pozice.x++;
		if (znak=='q') return(true);

		if (m_Pozice.x<0) m_Pozice.x=0;
		if (m_Pozice.x>80) m_Pozice.x=80;
	}
	return(false);
}

void CLod::Zobraz() {
	PrintXY(m_PoziceOld.x,m_PoziceOld.y," ",0);
	PrintXY(m_Pozice.x,m_Pozice.y,"#",7);
}

