/*

Copyright 2013 Zola Mahlaza
http://www.gnu.org/licenses/gpl-2.0.txt

"There are only two kinds of programming languages: those people always bitch about and those nobody uses.”
-Bjarne Stroustrup

*/
#ifndef _FUNCTOR
#define _FUNCTOR
#include<locale>
namespace mhlzol004{
	/*

	Functor for shifting chars
	Ceaser's cipher
	
	-deprecated-
	Ceaser's cipher now uses a Lambda function
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

	/*
	Functor for the Vignere cipher
	
	*/
	class confuse{
		public:
			char vig_matrix[26][26] = {

			{'A','B','C','D','E','F','G','H','I','J','K','L','M','N','O','P','Q','R','S','T','U','V','W','X','Y','Z'},
			{'B','C','D','E','F','G','H','I','J','K','L','M','N','O','P','Q','R','S','T','U','V','W','X','Y','Z','A'},
			{'C','D','E','F','G','H','I','J','K','L','M','N','O','P','Q','R','S','T','U','V','W','X','Y','Z','A','B'},
			{'D','E','F','G','H','I','J','K','L','M','N','O','P','Q','R','S','T','U','V','W','X','Y','Z','A','B','C'},
			{'E','F','G','H','I','J','K','L','M','N','O','P','Q','R','S','T','U','V','W','X','Y','Z','A','B','C','D'},
			{'F','G','H','I','J','K','L','M','N','O','P','Q','R','S','T','U','V','W','X','Y','Z','A','B','C','D','E'},
			{'G','H','I','J','K','L','M','N','O','P','Q','R','S','T','U','V','W','X','Y','Z','A','B','C','D','E','F'},
			{'H','I','J','K','L','M','N','O','P','Q','R','S','T','U','V','W','X','Y','Z','A','B','C','D','E','F','G'},
			{'I','J','K','L','M','N','O','P','Q','R','S','T','U','V','W','X','Y','Z','A','B','C','D','E','F','G','H'},
			{'J','K','L','M','N','O','P','Q','R','S','T','U','V','W','X','Y','Z','A','B','C','D','E','F','G','H','I'},
			{'K','L','M','N','O','P','Q','R','S','T','U','V','W','X','Y','Z','A','B','C','D','E','F','G','H','I','J'},
			{'L','M','N','O','P','Q','R','S','T','U','V','W','X','Y','Z','A','B','C','D','E','F','G','H','I','J','K'},
			{'M','N','O','P','Q','R','S','T','U','V','W','X','Y','Z','A','B','C','D','E','F','G','H','I','J','K','L'},
			{'N','O','P','Q','R','S','T','U','V','W','X','Y','Z','A','B','C','D','E','F','G','H','I','J','K','L','M'},
			{'O','P','Q','R','S','T','U','V','W','X','Y','Z','A','B','C','D','E','F','G','H','I','J','K','L','M','N'},
			{'P','Q','R','S','T','U','V','W','X','Y','Z','A','B','C','D','E','F','G','H','I','J','K','L','M','N','O'},
			{'Q','R','S','T','U','V','W','X','Y','Z','A','B','C','D','E','F','G','H','I','J','K','L','M','N','O','P'},
			{'R','S','T','U','V','W','X','Y','Z','A','B','C','D','E','F','G','H','I','J','K','L','M','N','O','P','Q'},
			{'S','T','U','V','W','X','Y','Z','A','B','C','D','E','F','G','H','I','J','K','L','M','N','O','P','Q','R'},
			{'T','U','V','W','X','Y','Z','A','B','C','D','E','F','G','H','I','J','K','L','M','N','O','P','Q','R','S'},
			{'U','V','W','X','Y','Z','A','B','C','D','E','F','G','H','I','J','K','L','M','N','O','P','Q','R','S','T'},
			{'V','W','X','Y','Z','A','B','C','D','E','F','G','H','I','J','K','L','M','N','O','P','Q','R','S','T','U'},
			{'W','X','Y','Z','A','B','C','D','E','F','G','H','I','J','K','L','M','N','O','P','Q','R','S','T','U','V'},
			{'X','Y','Z','A','B','C','D','E','F','G','H','I','J','K','L','M','N','O','P','Q','R','S','T','U','V','W'},
			{'Y','Z','A','B','C','D','E','F','G','H','I','J','K','L','M','N','O','P','Q','R','S','T','U','V','W','X'},
			{'Z','A','B','C','D','E','F','G','H','I','J','K','L','M','N','O','P','Q','R','S','T','U','V','W','X','Y'}

			};
			int x;
			int y;
			char operator()(char plain, char key){
				x = plain;
				y = key;
				int upper_case  = 1;
				if (x<91 && x>64){
					x -= 65;
				}
				else if (x>96 && x< 123){
					upper_case = 0;
					x -= 97;
				}
				if (y>64 && y<91){
					y -= 65;
				}
				else if (y>96 && y< 123){
					upper_case = 0;
					y -= 97;
				}
				if (upper_case==0){
					return tolower(vig_matrix[x][y]);		
				}
				return vig_matrix[x][y];
			}
	};
}
#endif
