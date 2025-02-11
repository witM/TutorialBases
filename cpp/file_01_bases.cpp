/*AUTHOR:Marian Witek
*The file is free for any usage
*https://infomaks.pl
*/



#include <vector>
#include <iostream>
#include <print>
#include <array>

#include <fstream>


struct Point2D {
	float x;
	float y;
};


void main()
{
	Point2D data;

	std::ofstream file{ "test.bin", std::ios::out | std::ios::binary };
	//std::ifstream file{ "test.bin", std::ios::in | std::ios::binary };

	if (!file.is_open()) {
		std::cout << "file is not opened\n";
	}
	else {
		file.write((char*)&data, sizeof(data));
		//file.read((char*)&data, sizeof(data));
		file.close();
	}

	//std::cout << "x:" << data.x << "\n";
	//std::cout << "y:" << data.y << "\n";

	std::cin.get();
}
