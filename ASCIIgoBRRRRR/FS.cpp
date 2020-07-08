#include "FS.h"
#include <iostream>
#include <string>
#include <filesystem>
#include <vector>
#include <Windows.h>
namespace fs = std::filesystem;

void FS::set_state(int PTR, bool S) {
	this->files[PTR].set_state(S);
}
bool FS::get_state(int PTR) {
	return this->files[PTR].get_state();
}
std::string FS::get_name(int PTR) {
	return this->files[PTR].get_name();
}
void FS::set_name(int PTR, std::string N) {
	this->files[PTR].set_name(N);
}

void FS::delete_file() {
	std::vector<file>::iterator ptrIT;
	for (ptrIT = this->files.begin(); ptrIT != this->files.end();) {
		if (ptrIT->get_state() == 0) {
			ptrIT = this->files.erase(ptrIT);
		}
		else {
			++ptrIT;
		}
	}
}

void FS::collect_files() {
	for (auto& F : fs::recursive_directory_iterator(this->path_in)) {
		std::string tmpF = F.path().string();
		if (tmpF.find(this->mask) != std::string::npos) {
			file tmpFile(tmpF, 1);
			if (find(tmpFile)) {
				this->files.push_back(tmpFile);
			}
		}
	}
}

bool FS::find(file N) {
	for (auto ptrF : this->files) {
		if (ptrF.get_name() == N.get_name() && ptrF.get_state() == N.get_state()) {
			return false;
		}
	}
	return true;
}

void FS::run() {
	while (true) {
		Sleep(1000);
		if (this->files.size() > 0) {
			Sleep(2000);
			std::cout << "Collected from in: " << std::endl;
			for (auto ptr : this->files) { std::cout << ptr.get_name() << ':' << ptr.get_state() << std::endl; }
			convert_to_ascii(&this->files[0]);
			Sleep(2000);
		}
		else {
			std::cout << "**Waiting for files**" << std::endl;
			Sleep(2000);
			collect_files();
		}
		Sleep(1000);
		delete_file();
		system("CLS");
	}
}


void FS::convert_to_ascii(file* N) {
	Sleep(2000);
	std::cout << " **CONVERTING FUCK YOURSELF** " << std::endl;
	N->set_state(false);
	Sleep(3000);
}