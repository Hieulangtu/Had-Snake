#pragma once
#include"CJablko.h"
#include"Pozice.h"
#include"printxy.h"
#include<vector>
#include"CHad.h"

using namespace std;

class CJablek
{
	vector<CJablko> m_Jablek;
public:
	void Zobraz();

public:
	void VytvorJablko(int x, int y, CHad* had);
};

