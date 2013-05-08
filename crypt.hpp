/*
Copyright 2013 Zola Mahlaza
http://www.gnu.org/licenses/gpl-2.0.txt

"I saw `cout' being shifted "Hello world" times to the left and stopped right there."

-Steve Gonedes

*/


#ifndef _CRYPT
#define _CRYPT
#include<iostream>
#include "crypt_policy.hpp"
#include "crypt_trait.hpp"
namespace mhlzol004{
	//general crypt
	template<typename C, class P, class G>
	class crypt{
		public:
			typedef typename crypt_trait<C>::key_value_t T; //getting the appropriate type for the key
			T crypt_key; //defining the key with the Cipher specific type
			/*

			Implementations for the all the appropriate methods
			
			*/
			crypt(T x){
				crypt_key = x;
			};
			~crypt(){
			};
			void encode(std::istream &in, std::ostream &out){
				crypt_policy<C,P,G>::encode(in,out);
			};
			void decode(std::istream &in, std::ostream &out){
				crypt_policy<C,P,G>::encode(in,out);
			};
	};
/*
	//ceaser's cipher specilization
	template<class P, class G>
	class crypt<Ceaser, true , false>{
	class crypt<Ceaser, P, G>{
		public:
			int key;
			crypt(std::string k){
				std::stringstream ss(k);
				ss >> key;
				std::cout << "ceaser's crypt created!" << std::endl;
			};
			crypt(int k):key(k){
				std::cout << "ceaser's crypt really created!" << std::endl;
			}
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
			xor_funct *x_worker;
			crypt(std::string k){
				int key;
				std::stringstream ss(k);
				ss >> key;
				x_worker = new xor_funct(key);
				std::cout << "xor's crypt created!" << std::endl;
			};
			crypt(int32_t key){
				x_worker = new xor_funct(key);
                                std::cout << "xor's crypt really created!" << std::endl;
			};
			~crypt(){
				delete x_worker;
				std::cout << "xor's crypt destroyed!" <<std::endl;
			};
			void encode(std::istream &in, std::ostream &out){
				std::istream_iterator<char> curr_pos(in);
				std::istream_iterator<char> end_of_input;
				std::ostream_iterator<char> output_it(out,"");
				
				//applying the xor_funct functor
				std::transform(curr_pos,end_of_input,output_it,*x_worker);	
				std::cout << "xor's decode called!" << std::endl;
			};
			void decode(std::istream &in, std::ostream &out){
				encode(in,out);
				std::cout << "xor's decode called!" << std::endl;
			};
	};

	//vignere cipher specilization
	template<class P, class G>
	class crypt<Vignere, P, G>{
		public:
			std::string key;
			vig_encrypt *v;
			vig_decrypt *vd;
			crypt(std::string k):key(k){
				std::cout << "vignere's crypt created!" << std::endl;
				v = new vig_encrypt;
				vd = new vig_decrypt;
			};
			~crypt(){
				delete v; delete vd;
				std::cout << "vignere's crypt destroyed!" << std::endl;
			};
			void encode(std::istream &in, std::ostream &out){
				int key_size = key.size();
				int key_pos = 0; //position in key since we can wrap around
				std::istream_iterator<char> curr_pos(in);
				std::istream_iterator<char> end_of_istream;
				while(curr_pos!=end_of_istream){
					std::cout << (*v)(*curr_pos,key[key_pos%key_size]) << std::endl;
					++key_pos;
					++curr_pos;
				}
				std::cout << "vignere's encode called!" << std::endl;
			};
			void decode(std::istream &in, std::ostream &out){
				int key_size = key.size();
                                int key_pos = 0; //position in key since we can wrap around
                                std::istream_iterator<char> curr_pos(in);
                                std::istream_iterator<char> end_of_istream;
                                while(curr_pos!=end_of_istream){
                                        std::cout << (*vd)(*curr_pos,key[key_pos%key_size]);
                                        ++key_pos;
                                        ++curr_pos;
                                }

				std::cout << "vignere's decode called!" << std::endl;
			};
	};

*/
}
#endif
