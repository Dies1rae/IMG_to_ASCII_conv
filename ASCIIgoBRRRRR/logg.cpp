#include "logg.h"

void logg::write_to_file() {
	std::ofstream log_file(this->logpath, std::ios::app);
	for (std::string ptr : this->logd) {
		log_file << ptr << '\n';
	}
	log_file << "Finishing" << '\n';
	log_file.close();
	this->logd.clear();
}


void logg::add_log_string(std::string L) {
	time_t now = std::time(NULL);
	time(&now);
	L.insert(0,":::::");
	L.insert(0,ctime(&now));
	this->logd.push_back(L);
}