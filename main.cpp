#include<iostream>
#include "crypt.hpp"
#include "cipher.hpp"
#include<string>
#include<fstream>
#include "functor.hpp"
int main(int args, char** argv){
	using namespace mhlzol004;
	std::string key("LEMON");
	crypt<Vignere, bool, bool> c(key);
	//std::ofstream output("decode.txt");
	c.decode(std::cin, std::cout);
	//vig_encrypt k;
	//std::cout << k('T','E') << std::endl;
}
