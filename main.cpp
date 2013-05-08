#include<iostream>
#include "crypt.hpp"
#include "cipher.hpp"
#include<string>
#include<fstream>
#include "functor.hpp"
#include "cmdline_parser.h"
int main(int args, char** argv){
	using namespace mhlzol004;
	std::cout << "Hello World!" << std::endl;

	/*

	Retrieving cmdline arguments

	*/
	cmdline_parser parser;
	parser.process_cmdline(args, argv);

	//pack or not to pack
	bool enable_packing = parser.enable_packing();
	//group or not to group
	bool enable_grouping = parser.enable_grouping();
	if (enable_packing){
		std::cout << "packing enabled!" << std::endl;
	}
	if (enable_grouping){
		std::cout << "grouping enabled!" << std::endl;
	}
	
	//retrieving the input and output file names
	std::string output_filename = parser.get_output_filename();
	std::string input_filename = parser.get_input_filename();

	//getting the type of cipher
	std::string cipher = parser.get_cipher();
	
	//encode or decode
	int encode = parser.encode();
	int decode = parser.decode();
	
	if (cipher=="xor"){
		mhlzol004::crypt<Xor,bool,bool> enigma(parser.get_key<int32_t>());
		//if input filename has not provided
		std::istream *in;
		if (input_filename==""){
			in = &std::cin;
		}
		else if (input_filename!=""){
			std::ifstream* infile = new std::ifstream(input_filename);
			in = infile;
		}

		//if input filename has not provided
		std::ostream *out;	
		if (output_filename==""){
			out = &std::cout;
		}
		else if (output_filename!=""){
			std::ofstream* outfile = new std::ofstream(output_filename);
			out = outfile;
		}
		
	}
	else if (cipher=="ceaser"){
		mhlzol004::crypt<Ceaser,bool,bool> enigma(parser.get_key<int>());	
	}
	else if (cipher=="vignere"){
		mhlzol004::crypt<Vignere,bool,bool> enigma(parser.get_key<std::string>());
	}
}
