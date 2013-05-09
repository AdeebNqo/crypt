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
#include "helper.hpp"
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
				//iterators for input stream
				std::istream_iterator<char> curr_pos(in);
				std::istream_iterator<char> end;
				//iterator for output stream
				std::ostream_iterator<char> output_pos(out,"");

				//fancy stuff
				int key = crypt_trait<Ceaser>::key;
				std::transform(curr_pos,end,output_pos,
					[&key](char c)->char{
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
	//xor policy
	template<class P, class G>
	class crypt_policy<Xor, P, G>{
		public:
			static void encode(std::istream &in, std::ostream &out){
				int pos = 0;
				std::ostream_iterator<char> out_it(out, "");
				std::istream_iterator<char> end;
				std::istream_iterator<char> curr_pos(in);
				std::bitset<32> key_bits(crypt_trait<Xor>::key);

				transform(curr_pos, end, out_it,
					[&pos, &key_bits] (char plain_char)->char{
						std::bitset<8> plain_bits(plain_char);
						
						int len = pos+8;
						int j=0;
						for (int i=pos;i<len;++i, ++j, ++pos){
							if (i>=32){
								i%=32;
							}
							plain_bits[j] = plain_bits[j] ^ key_bits[i];
						}
						pos %= 32;
						char ciphered_char = (unsigned) plain_bits.to_ulong();
					}
				);
			};
			static void decode(std::istream &in, std::ostream &out){
				encode(in,out);
			};
	};
	//vignere policy
	template<class P, class G>
	class crypt_policy<Vignere, P, G>{
		public:
			static void encode(std::istream &in, std::ostream &out){
				std::istream_iterator<char> end;
				std::istream_iterator<char> curr_pos(in);
				std::ostream_iterator<char> output(out, "");
				in.unsetf(std::ios::skipws);

				std::string key = crypt_trait<Vignere>::key;
				int key_size = key.size();
				int pos = -1;
				vig_encrypt vig_enc;

				std::transform(curr_pos,end,output,
				[&key, &pos, &key_size, &vig_enc] (char plain_char)->char{
						if (is_letter(plain_char)){
							++pos; pos %= key_size;
							return vig_enc(plain_char,key[pos]);
						}
						else{
							return plain_char;
						}
					}
				);

			};
			static void decode(std::istream &in, std::ostream &out){
				std::istream_iterator<char> end;
				std::istream_iterator<char> curr_pos(in);
				std::ostream_iterator<char> output(out, "");
				in.unsetf(std::ios::skipws);

				std::string key = crypt_trait<Vignere>::key;
				int key_size = key.size();
				int pos = -1;
				vig_decrypt vig_de;

				std::transform(curr_pos,end,output,
				[&key, &pos, &key_size, &vig_de] (char encr_char)->char{
						if (is_letter(encr_char)){
							++pos; pos %= key_size;
							return vig_de(encr_char,key[pos]);
						}
						else{
							return encr_char;
						}
					}
				);
			};
	};
}
#endif
