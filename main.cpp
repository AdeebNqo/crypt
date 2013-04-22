#include<iostream>
#include "crypt.hpp"
#include "cipher.hpp"
#include<string>
int main(int args, char** argv){
	using namespace mhlzol004;
	std::string key("1");
	crypt<Ceaser, bool, bool> c(key);
	c.encode(std::cin, std::cout);
}
