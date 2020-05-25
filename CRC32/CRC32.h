#pragma once
#include <fstream>
using namespace std;
class CRC32
{
private:
	int crc32_table[0xFF];
	unsigned int i, j, bytes;
	unsigned long crc = 0xFFFFFFFF;
	std::string s;
	std::wstring ws;
public:
	unsigned int stray(std::fstream& file);
	unsigned int GetCRC32(const char* buffer, int len);
};
class cipher_error: public std::invalid_argument 
{
public:
	explicit cipher_error (const std::string& what_arg):
		std::invalid_argument(what_arg) {}
	explicit cipher_error (const char* what_arg):
		std::invalid_argument(what_arg) {}
};