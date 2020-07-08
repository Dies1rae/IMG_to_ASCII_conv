#pragma once
#include <iostream>
#include <string>
class file{
private:
	std::string name;
	bool state;
public:
	//build
	file():name(), state(0){}
	file(std::string N, bool S) :name(N), state(S) {}
	~file() {}
	//inits
	void set_state(bool S);
	void set_name(std::string N);
	bool get_state();
	std::string get_name();
};

