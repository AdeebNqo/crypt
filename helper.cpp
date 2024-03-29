/*

File for my helper functions
Copyright 2013 Zola Mahlaza

"You're posting to a Scheme group. Around here, arguing that Java
is better than C++ is like arguing that grasshoppers taste better than tree bark."

-Thant Tessman, comp.lang.scheme 

*/
#include "helper.hpp"
namespace mhlzol004{
	/*
	Function for determining if char is a letter
	*/
	bool is_letter(char &some_char){
		int asci = (unsigned) some_char;
		if (asci>= 65 && asci <=90){
			return true;
		}
		else if(asci>=97 && asci<=122){
			return true;
		}
		return false;
	}
	/*
	Function for grouping characters
	*/
	void group(std::istream &in, std::ostream &out){
		int count = 0;
		std::ostream_iterator<char> out_it(out,"");
		
		std::istream_iterator<char> in_end;
		std::istream_iterator<char> in_curr(in);
		out.unsetf(std::ios::skipws);
		in.unsetf(std::ios::skipws);
		while(in_curr!=in_end){
			if (*in_curr == ' '){
				++in_curr;
			}
			else{
				if (count != 0 && count%5==0){
					*out_it = ' ';
					++out_it;
					count = -1;
				}
				else{
					*out_it = *in_curr;
					++in_curr;
					++out_it;
				}
				++count;
			}
		}
	}
	/*
	function for packing characters
	*/
	void pack(std::istream &in, std::ostream &out){
		std::istream_iterator<char> end;
		std::istream_iterator<char> curr_pos(in);
		std::ostream_iterator<char> out_it(out);
		std::vector<char> bytes;
		while(curr_pos!=end){
			char tmp = *curr_pos;
			std::bitset<8> bits(tmp);
			for (int i=0;i<8;i++){
				if (i+3==8){
					break;
				}
				bits[i+3] = bits[i]; bits[i] = 0;
			}
			//writing byte to ostream
			char new_char = bits.to_ulong();
			bytes.push_back(new_char);
			++curr_pos;
		}
		std::for_each(bytes.rbegin(), bytes.rend(), 
			[&out](char &param){
				out << param;
			}
		);
	}
}
