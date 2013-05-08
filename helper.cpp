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

