#pragma once
#include <iostream>
#include <time.h>
#include <string>
#include <vector>
class logg{
private:
	std::vector<std::string> logd;
public:
	logg(){
		this->logd = { "begin" };
	}
	logg(std::string S) { logd.push_back(S); }
	~logg(){}

	void write_to_file(std::string filepath);
};

