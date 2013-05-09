/*

Copyright 2013 Zola Mahlaza
http://www.gnu.org/licenses/gpl-2.0.txt

"There are only two kinds of programming languages: those people always bitch about and those nobody uses.”
-Bjarne Stroustrup

*/
#ifndef _FUNCTOR
#define _FUNCTOR
#include<locale>
#include<bitset>
#include<sstream>
#include<algorithm>
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
				std::cout << "(" << value << ")" << std::endl;
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
	class vig_encrypt{
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
			char operator()(const char &plain,const char &key){
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
					y -= 97;
				}
				if (upper_case==0){
					return tolower(vig_matrix[x][y]);		
				}
				return vig_matrix[x][y];
			}
	};
	
	/*
	Functor for decrypting the Vignere cipher
	
	*/
	class vig_decrypt{
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
			int x; int y;
			char operator()(const char &ciphertext,const char &key){
				x = ciphertext;
                                y = key;
                                int upper_case  = 1;
				int bit = 0;
                                if (x<91 && x>64){
                                         x -= 65;
					++bit;
                                }
                                else if (x>96 && x< 123){
                                        upper_case = 0;
                                        x -= 97;
					++bit;
                                }
                                if (y>64 && y<91){
                                        y -= 65;
					++bit;
                                }
                                else if (y>96 && y< 123){
                                        y -= 97;
					++bit;
                                }
				
				x -= y;
				while(x<0){
					x+=26;
				}
				//change x the value of x -- it must point to the plain text char
                                if (upper_case==0){
                                        return tolower(vig_matrix[x][0]);
                                }
				if (bit==0){
					return ciphertext;
				}
				return vig_matrix[x][0];
			}
	};

	/*
	Functor for the XOR cipher
	-deprecated--
	Not what was needed, this was too simple
	*/
	class xor_funct{
		public:
			int key;
			xor_funct(int k):key(k){}
			char operator()(const char &plain){
				int plain_int = plain;
				char tmp(key xor plain_int);
				char* char_ptr = &tmp;
				return *char_ptr;
			}
	};
	/*
	xor_it
	Functor for the xor cipher
	-deprecated--
	I used lambdas
	*/
	class xor_it{
		public:
			int curr_pos;
			std::bitset<32> key;
			xor_it(int32_t p_key):curr_pos(0){
				std::cout <<"public key: " <<p_key << std::endl;
				std::stringstream stream;
				while(1){
					if (p_key==1){
						stream << 1 ;
						break;
					}
					else{
						stream << p_key%2 ;
						p_key /= 2;
					}
				}
				std::string key_string;
				stream >> key_string;
				std::reverse(key_string.begin(), key_string.end());
				key = std::bitset<32>(key_string);
				std::cout << "key:      " << key << std::endl;
			}
			char operator()(const char &plain){
				std::bitset<8> char_bits(plain);
				for (int i=0;i<8;(++curr_pos)%32, ++i){
					char_bits[i] = char_bits[i] ^ key[curr_pos];
				}
				curr_pos %= 32;
				/*

				Converting the bitset to the encoded char
				*/
				unsigned long tmp_long= char_bits.to_ulong();
				char tmp_char  = tmp_long;
				return tmp_char;
			}	
	};
}
#endif
