#include<iostream>
#include "crypt.hpp"
#include "cipher.hpp"
#include<string>
#include<fstream>
int main(int args, char** argv){
	using namespace mhlzol004;
	std::string key("1");
	crypt<Ceaser, bool, bool> c(key);
	std::ofstream output("decode.txt");
	c.decode(std::cin, output);
}
