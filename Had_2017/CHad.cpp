#include "stdafx.h"
#include "CHad.h"

#define DOLEVA 0;
#define DOPRAVA 1;
#define NAHORU 2;
#define DOLU 3;

void CHad::VytorPart(int x, int y)
{
	CPart parthad(x,y);
	Had.push_back(parthad);
}

void CHad::Zobraz()
{
	SetColor(m_color);
	Had[0].Zobrazd();
	for (int i = 1; i<Had.size(); i++) {
		Had[i].Zobraz();
	}//Had[Had.size() - 1].Zobrazd();
	char text[30];
	sprintf_s(text, 30, "Your Score: %d", m_Score);
	PrintXY(79, 3, text);

}

bool CHad::Pohni()
{
	int znak;

	if (_kbhit()) {
		znak = _getch();
		//m_PoziceOld = m_Pozice;
		if (znak == 'a'&& Had[0].m_Pozice.x <= Had[1].m_Pozice.x && Had[0].GetPozice().x != 0 && Had[0].GetPozice().x != 70 && Had[0].GetPozice().y != 1 && Had[0].GetPozice().y != 24) m_Smer = DOLEVA;
		if (znak == 'd' && Had[0].m_Pozice.x >= Had[1].m_Pozice.x && Had[0].GetPozice().x != 0 && Had[0].GetPozice().x != 70 && Had[0].GetPozice().y != 1 && Had[0].GetPozice().y != 24) m_Smer = DOPRAVA;
		if (znak == 's' && Had[0].m_Pozice.y >= Had[1].m_Pozice.y &&Had[0].GetPozice().x != 0 && Had[0].GetPozice().x != 70 && Had[0].GetPozice().y != 1 && Had[0].GetPozice().y != 24) m_Smer = DOLU;
		if (znak == 'w' && Had[0].m_Pozice.y <= Had[1].m_Pozice.y &&Had[0].GetPozice().x != 0 && Had[0].GetPozice().x != 70 && Had[0].GetPozice().y != 1 && Had[0].GetPozice().y != 24) m_Smer = NAHORU;
		if (znak == 'p') return(true);
	}
	if (m_Smer == 0) {
		//Had[0].GetPozice().x--;
		for (int i = Had.size() - 1; i > 0;i--) {
			Had[i].m_PoziceOld = Had[i].m_Pozice;
			Had[i].m_Pozice= Had[i - 1].m_Pozice;
		}
		Had[0].Pohni1();
	}
	else if (m_Smer == 1) {
		//Had[0].GetPozice().x++;
		for (int i = Had.size() - 1; i > 0; i--) {
			Had[i].m_PoziceOld = Had[i].m_Pozice;
			Had[i].m_Pozice = Had[i - 1].m_Pozice;
		//	

		}
		Had[0].Pohni2();
	}
	else if (m_Smer == 2) {
		for (int i = Had.size() - 1; i > 0; i--) {
			Had[i].m_PoziceOld = Had[i].m_Pozice;
			Had[i].m_Pozice = Had[i - 1].m_Pozice;
			//	Had[0].GetPozice().y--;

		}Had[0].Pohni3();
	}
	else if (m_Smer == 3) {
		for (int i = Had.size() - 1; i > 0; i--) {
			Had[i].m_PoziceOld = Had[i].m_Pozice;
			Had[i].m_Pozice = Had[i - 1].m_Pozice;
		//	Had[0].GetPozice().y++;

		}Had[0].Pohni4();
	}

	if (Had[0].m_Pozice.x == 0) Had[0].m_Pozice.x = 70;	
	 else if(Had[0].m_Pozice.y == 24) Had[0].m_Pozice.y = 1;
	 else if(Had[0].m_Pozice.x == 70) Had[0].m_Pozice.x = 0;
	 else if(Had[0].m_Pozice.y == 1) Had[0].m_Pozice.y = 24;
	
	//for (int i = 1; i < Had.size(); i++) {
	//	if (Had[0].m_Pozice == Had[i].m_Pozice) return(true);
	//}

	
	return false;
}

void CHad::GenerujPart(int pocet)
{
	for (int i = 0; i < pocet; i++) {
		VytorPart(23 + i, 12);
	}
}

void CHad::GetPartpozice()
{
	for (int i = 0; i < Had.size(); i++) {
		Had[i].GetPozice();
	}
}

bool CHad::ZkontrojJablko(CJablko* jablko)
{
	for (int i = 0; i < Had.size(); i++) {
		if (Had[i].m_Pozice == jablko->GetPozice()) {
			return true;
			
		}
	}
	return false;
}

void CHad::GenerujJablko(CJablko* jablko)
{
	do {
		jablko->VytvorJablko();
	} while (ZkontrojJablko(jablko));
}

bool CHad::EatApple(CJablko* jablko)
{
	if (Had[0].m_Pozice == jablko->GetPozice()) {
		m_Score++;
		CPart Ocas(Had[Had.size() - 1].m_Pozice);
		Had.push_back(Ocas);
		GenerujJablko(jablko);
		return(true);
	}
	return false;
}

bool CHad::ZkontrojJistSebe()
{
	for (int i = 1; i < Had.size(); i++) {
		if (Had[0].m_Pozice == Had[i].m_Pozice) return(true);
	}

	return false;
}

bool CHad::Hitwall()
{
	if (Had[0].GetPozice().x == 0 || Had[0].GetPozice().x == 70 || Had[0].GetPozice().y == 1 || Had[0].GetPozice().y == 24) return(true);
	return false;
}

//Had[0].GetPozice().x != 0 && Had[0].GetPozice().x != 70 && Had[0].GetPozice().y != 1 && Had[0].GetPozice().y != 24



CHad::CHad()
{
	m_Score = 0;
}

CHad::~CHad()
{
}
