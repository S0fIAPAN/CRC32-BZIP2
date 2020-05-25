#include <iostream>
#include <iomanip>
#include <string>
#include "CRC32.h"
int main()
{
	try {
		CRC32 crc32;
		string path;
		fstream file("/home/sofa/Workspace/crc/test", ios::in | ios::out | ios::binary);
		if(!file) {
			while(!file) {
				cout<<"This path is wrong. Enter again: ";
				cin>>path;
				fstream file(path, ios::in | ios::out | ios::binary);
				if(file) break;
			}
		}
		cout<<"CRC32: "<<hex<<crc32.stray(file)<<endl;
	} catch (const cipher_error& e) {
		cerr<<"Error: "<<e.what()<<endl;
	}
	return 0;
}
