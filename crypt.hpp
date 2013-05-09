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
#include "helper.hpp"
#include<sstream>
namespace mhlzol004{
	//general crypt
	template<typename C, class P, class G>
	class crypt{
		public:
			std::ostream* output_ptr;
			typedef typename crypt_trait<C>::key_value_t T; //getting the appropriate type for the key
			T crypt_key; //defining the key with the Cipher specific type
			/*

			Implementations for the all the appropriate methods
			
			*/
			crypt(T x){
				crypt_key = x;
				crypt_trait<C>::key = x;
			};
			~crypt(){
				output_ptr->flush();	
			};
			void encode(std::istream &in, std::ostream &out){
				output_ptr = &out;
				std::stringstream new_in;
				//grouping
				if (crypt_trait<C>::group){
					group(in, new_in);
				}
				//packing
				if (crypt_trait<C>::pack){
					pack(new_in, new_in);
				}
				//encode
				crypt_policy<C,P,G>::encode(in,out);
			};
			void decode(std::istream &in, std::ostream &out){
				crypt_policy<C,P,G>::encode(in,out);
			};
	};
}
#endif
