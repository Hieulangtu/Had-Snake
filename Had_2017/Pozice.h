#pragma once

class CPozice
{
public: 
	int x;
	int y;

public:
	CPozice(void);
	~CPozice(void);
	bool operator==(CPozice pozice);
};
