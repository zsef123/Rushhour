#pragma once
#include <windows.h>
#include <mmsystem.h>
#include <iostream>
#include <fstream>
#include <conio.h>

class Wave {

public:
	Wave() {};
	Wave(char * filename);
	~Wave();
	void play(bool async = true);
	void loop(bool async = true);
	bool isok();
	void setFile(char *filename);
private:
	char * buffer;
	bool ok;
	HINSTANCE HInstance;
};