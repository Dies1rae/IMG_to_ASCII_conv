#include <iostream>
#include "FS.h"
#include "file.h"


int main(int argc, char* argv[]) {
	std::string dir_in = "C:\\Users\\n.poltavskiy\\Source\\Repos\\ASCIIgoBRRRRR\\Debug\\in";
	std::string dir_out = "C:\\Users\\n.poltavskiy\\Source\\Repos\\ASCIIgoBRRRRR\\Debug\\out";
	std::string mask = "jpg";
	FS main_serv(dir_in, dir_out, mask);
	main_serv.collect_files();
	main_serv.run();
	return 0;
}