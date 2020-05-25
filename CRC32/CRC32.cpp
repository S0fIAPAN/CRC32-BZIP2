#include "CRC32.h"
#include <locale>
#include <codecvt>
std::locale loc("ru_RU.UTF-8");
std::wstring_convert<std::codecvt_utf8<wchar_t>, wchar_t> codec;
unsigned int CRC32::stray(fstream& file)
{
	file.seekg(0, ios::end);
	int fsize = file.tellg();
	if(fsize == 0)
		throw cipher_error("empty file");
	file.seekg(0, ios::beg);
	char* buf = new char[fsize];
	file.read(buf, fsize);
	for(int i = 0; i < fsize; i++)
		s += buf[i];
	ws = codec.from_bytes(s);
	for(auto c:ws) {
		if((c >= L'А' && c <= L'я') || c == L'Ё')
			throw cipher_error("invalid text");
	}
	return GetCRC32(buf, fsize);
	delete[] buf;
}
unsigned int CRC32::GetCRC32(const char* buffer, int len)
{
	for (i = 0; i < 0xFF; i++) {
		for (bytes = i << 24, j = 8; j > 0; --j)
			bytes = bytes & 0x80000000 ? (bytes << 1) ^ 0x04C11DB7 : (bytes << 1);
		crc32_table[i] = bytes;
	}
	while (len--) {
		crc = (crc << 8) ^ crc32_table[((crc >> 24) ^ *buffer) & 0xFF];
		buffer++;
	}
	return crc^0xFFFFFFFF;
}