/*AUTHOR:Marian Witek
*The file is free for any usage
*https://infomaks.pl
*/


#define _CRT_SECURE_NO_WARNINGS

#include <string>
#include <iostream>
#include <fstream>

std::ofstream out;
std::ifstream in;

struct HeaderSaveData {
	char code[8];
	int version;
};

struct SaveData_10 {
	int experience;
	int energy;
};

struct SaveData_20 {
	int experience;
	int energy;
	int superPower;
};

void ReadHeader(std::ifstream& in, HeaderSaveData* header)
{
	in.read((char*)header, sizeof(HeaderSaveData));
}
template<class TData>
void ReadData(std::ifstream& in, TData* data)
{
	in.read((char*)data, sizeof(TData));
}

void PrintData_20(const SaveData_20* data);
void DeleteData();

HeaderSaveData header;
SaveData_10* data_10{ nullptr };
SaveData_20* data_20{ nullptr };


void main()
{

	in.open( "file.save", std::ios::binary);
	if (!in.is_open()) {
		std::cout << "File is not opened\n";
	}
	else
	{
		//read header
		ReadHeader(in, &header);
		if (std::strcmp(header.code, "sav") != 0) {
			std::cout << "saved file format is wrong\n";
			std::exit(0);
		}
		//read data
		switch (header.version)
		{
		case 10:
			data_10 = new SaveData_10();
			ReadData(in, data_10);
			break;
		case 20:
			data_20 = new SaveData_20();
			ReadData(in, data_20);
			break;
		}
		in.close();
	}

	PrintData_20(data_20);
	DeleteData();

	std::cin.get();

}

void PrintData_20(const SaveData_20* data)
{
	std::cout << "experience:" << data->experience << "\n";
	std::cout << "energy:" << data->energy << "\n";
	std::cout << "superPower:" << data->superPower << "\n";
}


void DeleteData()
{
	if (header.version == 10)
		delete data_10;
	if (header.version == 20)
		delete data_20;
}
