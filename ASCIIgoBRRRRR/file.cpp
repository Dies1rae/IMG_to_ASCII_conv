#include "file.h"

void file::set_state(bool S) {
	this->state = S;
}
void file::set_name(std::string N) {
	this->name = N;
}
bool file::get_state() {
	return this->state;
}
std::string file::get_name() {
	return this->name;
}
