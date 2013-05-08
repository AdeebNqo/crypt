/*
Policies for the crypt class
Copyright 2013 Zola Mahlaza
http://www.gnu.org/licenses/gpl-2.0.txt


Funny Stackoverflow question:

http://stackoverflow.com/questions/5508110/why-is-this-program-erroneously-rejected-by-three-c-compilers

-James McNellis 

*/
#ifndef _CRYPT_POLICY
#define	_CRYPT_POLICY
#include<iterator>
#include<iostream>
#include "functor.hpp"
#include "cipher.hpp"
#include "crypt_trait.hpp"
namespace mhlzol004{
	//default policy
	template<class C, class P, class G>
	class crypt_policy{
		public:
			static void encode(std::istream &in, std::ostream &out);
			static void decode(std::istream &in, std::ostream &out);
	};
	//ceaser policy
	template<class P,class G>
	class crypt_policy<Ceaser,P,G>{
		public:
			static void encode(std::istream &in, std::ostream &out){

				std::istream_iterator<char> end;
				std::istream_iterator<char> curr_pos(in);
				std::ostream_iterator<char> output(out, "");
				in.unsetf(std::ios::skipws);

				int key = crypt_trait<Ceaser>::key;
				std::transform(curr_pos,end,output,
					[&key](char c)->char{
						int ascci_code = (unsigned char) c;
						char curr_char = c;
						if (curr_char==' '){
							return ' ';
						}
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
			//decoding ceaser's cipher
			static void decode(std::istream &in, std::ostream &out){
				std::istream_iterator<char> end;
				std::istream_iterator<char> curr_pos(in);
				std::ostream_iterator<char> output(out, "");
				in.unsetf(std::ios::skipws);

				int key = crypt_trait<Ceaser>::key;
				std::transform(curr_pos,end,output,
					[&key](char c)->char{
						int ascci_code = (unsigned char) c;
						char curr_char = c;
						//space
						if (curr_char==' '){
							return ' ';
						}
						//upper case
						if (ascci_code<91 && ascci_code > 64){
							ascci_code-=65;
							ascci_code+= -key;
							ascci_code%=26; ascci_code +=65;
							curr_char = ascci_code;
						}
						//lower case
						else if (ascci_code>96 && ascci_code<123){
							ascci_code -= 97;
							ascci_code += -key;
							ascci_code%=26; ascci_code +=97;
							curr_char = ascci_code;
						}
						return curr_char;
					}
				);
			};
	};
	//xor policy
	template<class P, class G>
	class crypt_policy<Xor, P, G>{
		public:
			static void encode(std::istream &in, std::ostream &out){

			};
			static void decode(std::istream &in, std::ostream &out){
				
			};
	};
	//vignere policy
	template<class P, class G>
	class crypt_policy<Vignere, P, G>{
		public:
			static void encode(std::istream &in, std::ostream &out){
				
			};
			static void decode(std::istream &in, std::ostream &out){

			};
	};
}
#endif
