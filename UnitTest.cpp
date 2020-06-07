#include <unittest++/UnitTest++.h>
#include <stdexcept>
#include "CRC32.h"

struct CRC {
	CRC32 crc;
	fstream file_1;
	fstream file_2;
	fstream file_3;
	fstream file_4;
	fstream file_5;
	fstream file_6;
	fstream file_7;
	fstream file_8;
	fstream file_9;
	CRC() {
		file_1.open("/home/sofa/Workspace/crc/digits", ios::in | ios::binary);
		file_2.open("/home/sofa/Workspace/crc/english", ios::in | ios::binary);
		file_3.open("/home/sofa/Workspace/crc/russian", ios::in | ios::binary);
		file_4.open("/home/sofa/Workspace/crc/empty", ios::in | ios::binary);
		file_5.open("/home/sofa/Workspace/crc/uppereng", ios::in | ios::binary);
		file_6.open("/home/sofa/Workspace/crc/punctmarks", ios::in | ios::binary);
		file_7.open("/home/sofa/Workspace/crc/mix", ios::in | ios::binary);
		file_8.open("/home/sofa/Workspace/crc/one", ios::in | ios::binary);
		file_9.open("/home/sofa/Workspace/crc/repeat", ios::in | ios::binary);
	}
	~CRC() {
		file_1.close();
		file_2.close();
		file_3.close();
		file_4.close();
		file_5.close();
		file_6.close();
		file_7.close();
		file_8.close();
		file_9.close();
	}
};

SUITE(FileTests)
{
	TEST_FIXTURE(CRC, CheckNumText) {
		CHECK_EQUAL(0xfc891918, crc.stray(file_1));
	}
	TEST_FIXTURE(CRC, CheckEngText) {
		CHECK_EQUAL(0x44f71378, crc.stray(file_2));
	}
	TEST_FIXTURE(CRC, UpCaseEngText) {
		CHECK_EQUAL(0x1248aa6a, crc.stray(file_5));
	}
	TEST_FIXTURE(CRC, PunctEngText) {
		CHECK_EQUAL(0x16b836ff, crc.stray(file_6));
	}
	TEST_FIXTURE(CRC, EngMixText) {
		CHECK_EQUAL(0x631e8613, crc.stray(file_7));
	}
	TEST_FIXTURE(CRC, OneEngSymbol) {
		CHECK_EQUAL(0x81b02d8b, crc.stray(file_8));
	}
	TEST_FIXTURE(CRC, RepeatEngSym) {
		CHECK_EQUAL(0x33cf0fc5, crc.stray(file_9));
	}
	TEST_FIXTURE(CRC, CheckRusText) {
		CHECK_THROW(crc.stray(file_3), error);
	}
	TEST_FIXTURE(CRC, CheckEmptyFile) {
		CHECK_THROW(crc.stray(file_4), error);
	}
}

int main(int argc, char **argv)
{
	return UnitTest::RunAllTests();
}
