/*
 * cmdline_parser.h
 *
 *  Created on: 22 Feb 2012
 *      Author: simon
 */

#ifndef CMDLINE_PARSER_H_
#define CMDLINE_PARSER_H_

#include <iostream>
#include <string>

#include <boost/program_options.hpp>

//---------------------------------------------------------------------------//
class cmdline_parser
{
public:
    //-----------------------------------------------------------------------//
	// Constructor
	cmdline_parser(void);

	// Member function that parses command line options
	bool process_cmdline(int argc, char * argv[]);
	// Getter for the db filename cmdline option
	std::string get_database_filename(void) const;
	// Member indicating whether cmdline help should be printed
	bool should_print_help(void) const;
	// Output help to the specified output stream
	void print_help(std::ostream & out) const;
	bool encode();
	bool decode();
	int enable_packing();
	int enable_grouping();
	std::string get_input_filename();
	std::string get_output_filename();
	template<typename T>
	T get_key(){
		if (vm.count("xor")){
                	//xor cipher
			T tmp = vm["xor"].as<T>();
			return tmp;
         	}
         	else if (vm.count("vignere")){
 			//vig
			T tmp = vm["vignere"].as<T>();
        		return tmp; 
		}
        	else if (vm.count("ceaser")){
 			//ceaser
			T tmp = vm["ceaser"].as<T>();
        		return tmp;
		}
		return T();		
		}
	std::string get_cipher();

private:
    //-----------------------------------------------------------------------//
	// Member variables
	boost::program_options::variables_map vm;
	boost::program_options::options_description od;
};

#endif /* CMDLINE_PARSER_H_ */
