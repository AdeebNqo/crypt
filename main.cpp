#include<iostream>
#include "crypt.hpp"
#include "cipher.hpp"
#include<string>
#include "cmdline_parser.h"
#include "helper.hpp"
#include<fstream>
int main(int args, char** argv){
	using namespace mhlzol004;
	/*

	Retrieving cmdline arguments

	*/
	cmdline_parser parser;
	parser.process_cmdline(args, argv);

	//pack or not to pack
	bool enable_packing = parser.enable_packing();
	//group or not to group
	bool enable_grouping = parser.enable_grouping();
	
	//retrieving the input and output file names
	std::string output_filename = parser.get_output_filename();
	std::string input_filename = parser.get_input_filename();

	//getting the type of cipher
	std::string cipher = parser.get_cipher();
	
	//encode or decode
	int encode = parser.encode();
	int decode = parser.decode();
	
	std::istream *in;
	std::ostream *out;

	
	if (cipher=="xor"){
		mhlzol004::crypt<Xor,bool,bool> enigma(parser.get_key<int32_t>());
		
		//initialise whether to pack and group
		if (enable_packing>0){
			crypt_trait<Xor>::pack = true;
		}
		else if (enable_packing<=0){
			crypt_trait<Xor>::pack = false;
		}
		if (enable_grouping>0){
			crypt_trait<Xor>::group = true;
		}
		else if (enable_grouping<=0){
			crypt_trait<Xor>::group = false;
		}

		//if input filename has not provided
		
		//if the input file option is not given as an cmd arg
		if (parser.input_file()<1){
			//input file will not be given
			in = &std::cin;
		}
		else{
			if (input_filename==""){
				in = &std::cin;
			}
			else if (input_filename!=""){
				std::ifstream* infile = new std::ifstream(input_filename);
				in = infile;
			}
		}

		//if input filename has not provided
		
		//if the output file option is not given as an cmd arg
		if (parser.output_file()<1){
			out = &std::cout;
		}
		else{
			if (output_filename==""){
				out = &std::cout;
			}
			else if (output_filename!=""){
				std::ofstream* outfile = new std::ofstream(output_filename);
				out = outfile;
			}
		}
		
		if (encode>0){
			enigma.encode(*in,*out);
		}
		if (decode >0){
			enigma.decode(*in, *out);
		}
			
	}
	else if (cipher=="ceaser"){
		mhlzol004::crypt<Ceaser,bool,bool> enigma(parser.get_key<int>());

		//initialise whether to pack and group
		if (enable_packing>0){
			crypt_trait<Ceaser>::pack = true;
		}
		else if (enable_packing<=0){
			crypt_trait<Ceaser>::pack = false;
		}
		if (enable_grouping>0){
			crypt_trait<Ceaser>::group = true;
		}
		else if (enable_grouping<=0){
			crypt_trait<Ceaser>::group = false;
		}

		//if input filename has not provided
		if (parser.input_file()<1){
			in = &std::cin;
		}
		else {
			if (input_filename==""){
				in = &std::cin;
			}
			else if (input_filename!=""){
				std::ifstream* infile = new std::ifstream(input_filename);
				in = infile;
			}
		}

		//if input filename has not provided
		if (parser.output_file()<1){
			out = &std::cout;
		}
		else{
			if (output_filename==""){
				out = &std::cout;
			}
			else if (output_filename!=""){
				std::ofstream* outfile = new std::ofstream(output_filename);
				out = outfile;
			}
		}
		if (encode>0){
			enigma.encode(*in,*out);
		}
		if (decode >0){
			enigma.decode(*in, *out);
		}
	}
	else if (cipher=="vignere"){
		mhlzol004::crypt<Vignere,bool,bool> enigma(parser.get_key<std::string>());

		//initialise whether to pack and group
		if (enable_packing>0){
			crypt_trait<Vignere>::pack = true;
		}
		else if (enable_packing<=0){
			crypt_trait<Vignere>::pack = false;
		}
		if (enable_grouping>0){
			crypt_trait<Vignere>::group = true;
		}
		else if (enable_grouping<=0){
			crypt_trait<Vignere>::group = false;
		}

		//if input filename has not provided
		if (parser.input_file()<1){
			in = &std::cin;
		}
		else{
			if (input_filename==""){
				in = &std::cin;
			}
			else if (input_filename!=""){
				std::ifstream* infile = new std::ifstream(input_filename);
				in = infile;
			}
		}

		//if input filename has not provided
		if (parser.output_file()){
			out = &std::cout;
		}
		else{
			if (output_filename==""){
				out = &std::cout;
			}
			else if (output_filename!=""){
				std::ofstream* outfile = new std::ofstream(output_filename);
				out = outfile;
			}
		}
		if (encode>0){
			enigma.encode(*in,*out);
		}
		if (decode >0){
			enigma.decode(*in, *out);
		}
	}
}
