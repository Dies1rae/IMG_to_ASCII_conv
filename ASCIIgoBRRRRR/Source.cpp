#include <iostream>
#include "FS.h"
#include "file.h"
#include "opencv2/opencv.hpp"
#include "Menu.h"


int main(int argc, char* argv[]) {
	
	if (argc == 1) {
		std::cout << "Starting" << std::endl;
		std::cout << "**default folder and filetypes**" << std::endl;
		std::string dir_in = ".\\in";
		std::string dir_out = ".\\out";
		std::string mask = "jpg";
		logg* Nlog = new logg("Begin");
		FS main_serv(dir_in, dir_out, mask);
		main_serv.init(Nlog);
		main_serv.run();
	}
	if (argc == 2 && (argv[1][0] == '/' && argv[1][1] == 'm')) {
		man_menu_view();
	}
	if (argc == 2 && (argv[1][0] == '/' && argv[1][1] == '?')) {
		help_menu_view();
	}
	if (argc == 2 && (argv[1][0] == '/' && argv[1][1] == 's')) {
		std::cout << "Starting" << std::endl;
		std::cout << "**default folder and filetypes**" << std::endl;
		std::string dir_in = ".\\in";
		std::string dir_out = ".\\out";
		std::string mask = "jpg";
		logg* Nlog = new logg("Begin");
		FS main_serv(dir_in, dir_out, mask);
		main_serv.init(Nlog);
		main_serv.run();
	}
	if ((argc >2 && argc < 6) && (argv[1][0] == '/' && argv[1][1] == 's')) {
		if (argc == 3) {
			std::string dir_in = argv[2];
			std::string dir_out = ".\\out";
			std::string mask = "jpg";
			logg* Nlog = new logg("Begin");
			FS main_serv(dir_in, dir_out, mask);
			main_serv.init(Nlog);
			main_serv.run();
		}
		if (argc == 4) {
			std::string dir_in = argv[2];
			std::string dir_out = argv[3];
			std::string mask = "jpg";
			logg* Nlog = new logg("Begin");
			FS main_serv(dir_in, dir_out, mask);
			main_serv.init(Nlog);
			main_serv.run();
		}
		if (argc == 5) {
			std::string dir_in = argv[2];
			std::string dir_out = argv[3];
			std::string mask = argv[4];
			logg* Nlog = new logg("Begin");
			FS main_serv(dir_in, dir_out, mask);
			main_serv.init(Nlog);
			main_serv.run();
		}
	}

	return 0;
}