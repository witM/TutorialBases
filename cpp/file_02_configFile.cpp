/*AUTHOR:Marian Witek
*The file is free for any usage
*https://infomaks.pl
*/



#include <vector>
#include <iostream>
#include <print>
#include <array>

#include <fstream>


struct Configuration {
	bool isFullscreen;
};

std::ifstream in;
std::ofstream out;

void CreateDefaultConfigFile(Configuration* config);

void main()
{
	Configuration config;
	
	in.open("file.config", std::ios::in | std::ios::binary);
	if (!in.is_open()) {
		CreateDefaultConfigFile(&config);
	}
	else
	{
		in.read((char*)&config, sizeof(config));
		in.close();
	}


	std::cin.get();
}

void CreateDefaultConfigFile(Configuration* config)
{
	config->isFullscreen = false;
	//
	out.open("file.config", std::ios::out | std::ios::binary);
	if (!out.is_open()) {
		std::cout << "can't create default configuration file\n";
	}
	else
	{
		out.write((char*)config, sizeof(Configuration));
		out.close();
	}
}

