#include "Sound.h"

Sound::Sound(char *file) {
	_ok = false;
	_buff = 0;
	_hinstance = GetModuleHandle(0);

	ifstream infile(file, ios::binary);

	if (!infile) {
		std::cout << "Wave::file error: " << file << std::endl;
		return;
	}

	infile.seekg(0, ios::end);   // get length of file
	int length = infile.tellg();
	_buff = new char[length];    // allocate memory
	infile.seekg(0, ios::beg);   // position to start of file
	infile.read(_buff, length);  // read entire file

	infile.close();
	_ok = true;
}


Sound::~Sound() {
	PlaySound(NULL, 0, 0); // STOP ANY PLAYING SOUND
	delete[] _buff;      // before deleting buffer.
}


void Sound::play(bool async)
{
	if (!_ok)
		return;

	if (async)
		PlaySound(_buff, _hinstance, SND_MEMORY | SND_ASYNC);
	else
		PlaySound(_buff, _hinstance, SND_MEMORY);
}
