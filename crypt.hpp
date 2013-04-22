/*
Copyright 2013 Zola Mahlaza
http://www.gnu.org/licenses/gpl-2.0.txt

"I saw `cout' being shifted "Hello world" times to the left and stopped right there."

-Steve Gonedes

*/


#ifndef _CRYPT
#define _CRYPT
#include<iostream>
#include "cipher.hpp"
#include<string>
#include<sstream>
#include<iterator>
#include<algorithm>
namespace mhlzol004{
	//general crypt
	template<class C, class P, class G>
	class crypt{
		public:
			std::string key;
			crypt(std::string k):key(k){
				std::cout << "crypt created!" <<std::endl;
			};
			~crypt(){
				std::cout << "crypt destroyed!" << std::endl;
			};
			void encode(std::istream &in, std::ostream &out){
				std::cout << "encode() called!" << std::endl;
			};
			void decode(std::istream &in, std::ostream &out){
				std::cout << "decode() called!" << std::endl;
			};
	};

	//ceaser's cipher specilization
	template<class P, class G>
	class crypt<Ceaser, P, G>{
		public:
			int key;
			crypt(std::string k){
				std::stringstream ss(k);
				ss >> key;
				std::cout << "ceaser's crypt created!" << std::endl;
			};
			~crypt(){
				std::cout << "ceaser's crypt destroyed!" << std::endl;
			};
			void encode(std::istream &in, std::ostream &out){
				//iterators for input stream
				std::istream_iterator<char> curr_pos(in);
				std::istream_iterator<char> end;
				//iterator for output stream
				std::ostream_iterator<char> output_pos(out,"");
				//fancy algorithm
				std::transform(curr_pos,end,output_pos,
					[this](char c)->char{
						int ascci_code = (unsigned char) c;
						char curr_char = c;
						//upper case
						if (ascci_code<91 && ascci_code > 64){
							ascci_code-=65;
							ascci_code+=key;
							ascci_code%=26; ascci_code +=65;
							curr_char = ascci_code;
						}
						//lower case
						else if (ascci_code>96 && ascci_code<123){
							ascci_code -= 97;
							ascci_code += key;
							ascci_code%=26; ascci_code +=97;
							curr_char = ascci_code;
						}
						return curr_char;
					}
				);
			};
			void decode(std::istream &in, std::ostream &out){
				//iterators for input stream
                                std::istream_iterator<char> curr_pos(in);
                                std::istream_iterator<char> end;
                                //iterator for output stream
                                std::ostream_iterator<char> output_pos(out,"");
                                //fancy algorithm
                                std::transform(curr_pos,end,output_pos,
                                        [this](char c)->char{
                                                int ascci_code = (unsigned char) c;
                                                char curr_char = c;
                                                //upper case
                                                if (ascci_code<91 && ascci_code > 64){
                                                        ascci_code-=65;
                                                        ascci_code+=(-key);
							while(ascci_code<0){
								ascci_code += 26;
							}
                                                        ascci_code +=65;
                                                        curr_char = ascci_code;
                                                }
                                                //lower case
                                                else if (ascci_code>96 && ascci_code<123){
							ascci_code -= 97;
                                                        ascci_code += (-key);
							while(ascci_code < 0){
								ascci_code += 26;
							}
                                                        ascci_code +=97;
                                                        curr_char = ascci_code;
                                                }
                                                return curr_char;
                                        }
                                );

			};
	};

	//xor's cipher specilization
	template<class P, class G>
	class crypt<Xor, P, G>{
		public:
			std::string key;
			crypt(std::string k):key(k){
				std::cout << "xor's crypt created!" << std::endl;
			};
			~crypt(){
				std::cout << "xor's crypt destroyed!" <<std::endl;
			};
			void encode(std::istream &in, std::ostream &out){
				std::cout << "xor's decode called!" << std::endl;
			};
			void decode(std::istream &in, std::ostream &out){
				std::cout << "xor's decode called!" << std::endl;
			};
	};

	//vignere cipher specilization
	template<class P, class G>
	class crypt<Vignere, P, G>{
		public:
			std::string key;
			crypt(std::string k):key(k){
				std::cout << "vignere's crypt created!" << std::endl;
			};
			~crypt(){
				std::cout << "vignere's crypt destroyed!" << std::endl;
			};
			void encode(std::istream &in, std::ostream &out){
				std::cout << "vignere's encode called!" << std::endl;
			};
			void decode(std::istream &in, std::ostream &out){
				std::cout << "vignere's decode called!" << std::endl;
			};
	};
}
#endif