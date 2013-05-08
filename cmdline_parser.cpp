/*
 * cmdline_parser.cpp
 *
 *  Created on: 22 Feb 2012
 *      Author: simon
 */
#include<cstdint>
#include "cmdline_parser.h"
#include<string>
//-------------------------------------------------------------------------//
// Constructor, initialise the variables_map object with default
// constructor, options_descriptor with the name "Options"
//-------------------------------------------------------------------------//
cmdline_parser::cmdline_parser(void) : vm(), od("Options")
{
	// Shorter alias for the boost::program_options namespace
	namespace po = boost::program_options;

	/* Add cmdline options
	 *--help or -? for producing help
	 * --encode or -e for choosing encode option
	 * --decode or -d for choosign decode option
	 * --input or -i for entering input filename
	 */
	od.add_options()
		("help,?", "produce help message")
		("encode,e","encode option")
		("decode,d","decode option")
		("input,i",po::value<std::string>(),"input filename")
		("output,o",po::value<std::string>(),"output filename")
		("xor,x",po::value<int32_t>(),"xor cipher option followed by key")
		("vignere,v",po::value<std::string>(),"vignere cipher followed by key")
		("ceaser,c",po::value<int>(),"ceaser's cipher option followed by shift key")
		("group,g","enable grouping")
		("pack,p","enable packing");
};

//-------------------------------------------------------------------------//
// Process the cmdline
//-------------------------------------------------------------------------//
bool cmdline_parser::process_cmdline(int argc, char * argv[])
{
	// Shorter alias for the boost::program_options namespace
	namespace po = boost::program_options;

	// Clear the variable map
	vm.clear();

	// Parse the cmdline arguments defined by argc and argv,
	// looking for the options defined in the od variable,
	// and store them in the vm variable.
	po::store(po::parse_command_line(argc, argv, od), vm);
	po::notify(vm);

	// Assume processing always succeeds
	return true;
}

//-----------------------------------------------------------------------//
// Return the database filename
//-------------------------------------------------------------------------//
std::string cmdline_parser::get_database_filename(void) const
{
	// Return whatever value is stored in database-file as a string
	return vm["database-file"].as<std::string>();
}
std::string cmdline_parser::get_cipher(){
	if (vm.count("xor")>0){
		//xor cipher is envoked
		return std::string("xor");
	}
	else if (vm.count("vignere")>0){
		//vignere cipher is envoked
		return std::string("vignere");
	}
	else if (vm.count("ceaser")>0){
		//ceaser is envoked
		return std::string("ceaser");
	}
	return "";
}

bool cmdline_parser::encode(){
	return vm.count("encode");
}
bool cmdline_parser::decode(){
	return vm.count("decode");
}
int cmdline_parser::input_file(){
	return vm.count("input");
}
int cmdline_parser::output_file(){
	return vm.count("output");
}
int cmdline_parser::enable_packing(){
	return vm.count("pack");
}
int cmdline_parser::enable_grouping(){
	return vm.count("group");
}
std::string cmdline_parser::get_input_filename(){
	if (vm.count("input")){
		return vm["input"].as<std::string>();
	}
	return std::string("");
}
std::string cmdline_parser::get_output_filename(){
	if (vm.count("output")){
		return vm["output"].as<std::string>();
	}
	return std::string("");
}
//-----------------------------------------------------------------------//
// Should we print cmdline help?
//-------------------------------------------------------------------------//
bool cmdline_parser::should_print_help(void) const
{
	// Are there instances of the help option stored in the variable map
	return vm.count("help") > 0;
}

//-------------------------------------------------------------------------//
// Print out the options_descriptor to the supplied output stream
//-------------------------------------------------------------------------//
void cmdline_parser::print_help(std::ostream & out) const
{
	out << od;
}
