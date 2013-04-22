/*

Copyright 2013 Zola Mahlaza
http://www.gnu.org/licenses/gpl-2.0.txt

"There are only two kinds of programming languages: those people always bitch about and those nobody uses.”
-Bjarne Stroustrup

*/
#ifndef _FUNCTOR
#define _FUNCTOR
namespace mhlzol004{
	/*

	Functor for shifting chars
	Ceaser's cipher
	
	*/
	class shift{
		public:
			int shift_k;
			char *x;
			shift(int shift_key):shift_k(shift_key){}
			char operator()(const char & value){
				int ascci_code = (unsigned char) value;
				//if the letter is upper case
				if (ascci_code<91 && ascci_code > 64){
					ascci_code-=65;
					ascci_code+=shift_k;
					ascci_code%=25; ascci_code +=65;
					x = new char(ascci_code);
				}
				//if the letter is lower case
				else if (ascci_code>96 && ascci_code<123){
					ascci_code -= 97;
					ascci_code += shift_k;
					ascci_code%=25; ascci_code +=97;
					x = new char(ascci_code);
				}
				return *x;
			}
	};
}
#endif
