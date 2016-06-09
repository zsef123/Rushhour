#include "Wave.h"
using namespace std;

Wave::Wave(char * filename)
{
	ok = false;
	buffer = 0;
	HInstance = GetModuleHandle(0);

	ifstream infile(filename, ios::binary);

	if (!infile)
	{
		std::cout << "Wave::file error: " << filename << std::endl;
		return;
	}

	infile.seekg(0, ios::end);   // get length of file
	int length = infile.tellg();
	buffer = new char[length];    // allocate memory
	infile.seekg(0, ios::beg);   // position to start of file
	infile.read(buffer, length);  // read entire file

	infile.close();
	ok = true;
}

Wave::~Wave()
{
	PlaySound(NULL, 0, 0); // STOP ANY PLAYING SOUND
	delete[] buffer;      // before deleting buffer.
}
void Wave::play(bool async)
{
	if (!ok)
		return;

	if (async)
		PlaySound((LPCWSTR)buffer, HInstance, SND_MEMORY | SND_ASYNC);
	else
		PlaySound((LPCWSTR)buffer, HInstance, SND_MEMORY);
}
void Wave::loop(bool async) {
	if (!ok)
		return;

	if (async)
		PlaySound((LPCWSTR)buffer, HInstance, SND_MEMORY | SND_ASYNC | SND_LOOP);
	else
		PlaySound((LPCWSTR)buffer, HInstance, SND_MEMORY | SND_LOOP);
}
bool Wave::isok()
{
	return ok;
}
void Wave::setFile(char *filename)
{
	ok = false;
	buffer = 0;
	HInstance = GetModuleHandle(0);

	ifstream infile(filename, ios::binary);

	if (!infile)
	{
		std::cout << "Wave::file error: " << filename << std::endl;
		return;
	}

	infile.seekg(0, ios::end);   // get length of file
	int length = infile.tellg();
	buffer = new char[length];    // allocate memory
	infile.seekg(0, ios::beg);   // position to start of file
	infile.read(buffer, length);  // read entire file

	infile.close();
	ok = true;
}
