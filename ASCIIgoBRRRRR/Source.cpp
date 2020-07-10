#include <iostream>
#include "FS.h"
#include "file.h"
#include "opencv2/opencv.hpp"


int main(int argc, char* argv[]) {
	std::string dir_in = "C:\\Users\\n.poltavskiy\\Source\\Repos\\ASCIIgoBRRRRR\\x64\\Release\\in";
	std::string dir_out = "C:\\Users\\n.poltavskiy\\Source\\Repos\\ASCIIgoBRRRRR\\x64\\Release\\out";
	
	//std::string dir_in = "C:\\Users\\Vergilius\\source\\repos\\IMG_to_ASCII_conv\\x64\\Release\\in";
	//std::string dir_out = "C:\\Users\\Vergilius\\source\\repos\\IMG_to_ASCII_conv\\x64\\Release\\out";
	std::string mask = "jpg";
	logg *Nlog = new logg("Begin");
	FS main_serv(dir_in, dir_out, mask);
	main_serv.init(Nlog);
	main_serv.run();
	return 0;
}