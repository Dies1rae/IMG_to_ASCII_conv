#pragma once
#include "file.h"
#include "logg.h"
#include <iostream>
#include <string>
#include <filesystem>
#include <vector>
namespace fs = std::filesystem;

class FS{
private:
	std::string path_in; //path to look for
	std::string path_out;//path to output
	std::string mask; //what files look
	std::vector<file> files;
	logg* main_log;
public:
	//build
	FS(std::string P_in, std::string P_out, std::string M):path_in(P_in), path_out(P_out), mask(M), files(), main_log() {}

	void run();
	//server methods
	void delete_file();
	void collect_files();
	void convert_to_ascii(file* N);
	//server methods to separate file class elem in vector of file
	void set_state(int PTR, bool S);
	bool get_state(int PTR);
	std::string get_name(int PTR);
	void set_name(int PTR, std::string N);
	bool find(file N);
};

