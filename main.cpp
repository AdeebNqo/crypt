#include<iostream>
#include "crypt.hpp"
#include "cipher.hpp"
#include<string>
#include<fstream>
#include "functor.hpp"
int main(int args, char** argv){
	using namespace mhlzol004;
	std::cout << "Hello World!" << std::endl;
	int32_t x = 156;
	xor_it X(x);
	//std::string key("LEMON");
	//crypt<Xor, bool, bool> c(1);
	//std::ofstream output("decode.txt");
	//c.decode(std::cin, std::cout);
	//vig_encrypt k;
	//std::cout << k('T','E') << std::endl;
}
