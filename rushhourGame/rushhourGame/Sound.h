#pragma once
#include <windows.h>
#include <mmsystem.h>
#include <iostream>
class Sound
{
public:
	Sound(char *file);
	~Sound();
	void play();
private:
	char *_buff;
	bool _ok;
	HINSTANCE _hinstance;
};

