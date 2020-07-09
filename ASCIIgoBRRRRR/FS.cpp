#include "FS.h"
#include <iostream>
#include <string>
#include <filesystem>
#include <vector>
#include <Windows.h>
#include <fstream>
#include "opencv2/opencv.hpp"


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
			for (auto& F : fs::recursive_directory_iterator(this->path_in)) {
				fs::remove(ptrIT->get_name());
			}
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
		collect_files();
		if (this->files.size() > 0) {
			std::cout << "Collected from *in*: " << std::endl;
			for (auto ptr : this->files) { std::cout << ptr.get_name() << ':' << ptr.get_state() << std::endl; }
			Sleep(3000);
			convert_to_ascii(&this->files[0]);
		}
		else {
			std::cout << "**Waiting for files**" << std::endl;
			Sleep(2000);
		}
		Sleep(1000);
		system("CLS");
	}
}


void FS::convert_to_ascii(file* N) {
	std::cout << " **CONVERTING** " << std::endl;
	std::string txtfilename = this->path_out;
	txtfilename += N->get_name().substr(N->get_name().find_last_of("/\\"),N->get_name().find_last_of(".") - N->get_name().find_last_of("/\\"));
	txtfilename += ".txt";
	std::ofstream convouttxt(txtfilename);
	
	cv::Mat ph = cv::imread(N->get_name(), cv::IMREAD_GRAYSCALE);
	cv::Mat resized;
	if (ph.cols < ph.rows) {
		resize(ph, resized, cv::Size(int(ph.cols / 5), int(ph.rows / 5)));
	}
	else if (ph.cols > ph.rows) {
		resize(ph, resized, cv::Size(int(ph.cols / 5), int(ph.rows / 5)));
	}
	else {
		resize(ph, resized, cv::Size(int(ph.cols / 5), int(ph.rows / 5)));
	}
	for (int ptrROW = 0; ptrROW < resized.rows; ptrROW++) {
		for (int ptrCOL = 0; ptrCOL < resized.cols; ptrCOL++) {
			cv::Scalar pix = resized.at<uchar>(cv::Point(ptrCOL, ptrROW));
			//cout << pix[0]<< ':' << pix[1] << ':' << pix[2] << ' ';
			//cout << pix.val[0]<< ':' << pix.val[1] << ':' << pix.val[2] << ' ';
			if (pix[0] >= 0 && pix[0] <= 25) {
				convouttxt << '@';
			}
			if (pix[0] >= 26 && pix[0] <= 51) {
					convouttxt << '%'; 
			}
			if (pix[0] >= 52 && pix[0] <= 77) {
				convouttxt << '#'; 
			}
			if (pix[0] >= 78 && pix[0] <= 103) {
				convouttxt << '*'; 
				}
			if (pix[0] >= 104 && pix[0] <= 129) {
				convouttxt << '+'; 
			}
			if (pix[0] >= 130 && pix[0] <= 155) {
				convouttxt << '='; 
				}
			if (pix[0] >= 156 && pix[0] <= 181) {
				convouttxt << '-'; 
			}
			if (pix[0] >= 182 && pix[0] <= 207) {
				convouttxt << ':'; 
				}
			if (pix[0] >= 208 && pix[0] <= 233) {
				convouttxt << '.'; 
			}
			if (pix[0] > 233) {
				convouttxt << ' '; 
			}
		}
		convouttxt << '\n';
	}

	convouttxt.close();
	N->set_state(false);
	delete_file();
	std::cout << " **CONVERTING DONE** " << std::endl;
	Sleep(3000);
}
