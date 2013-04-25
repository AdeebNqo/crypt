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
#include "cipher.hpp"
#include "crypt_trait.hpp"
namespace mhlzol004{
	//default policy
	template<class C, class P, class G>
	class crypt_policy{
		public:
			typedef typename crypt_trait<C>::key_value_t key_type;
			key_type key;
			static void encode(std::istream &in, std::ostream &out);
			static void decode(std::istream &in, std::ostream &out);
	};
	//ceaser policy
	template<class P,class G>
	class crypt_policy<Ceaser,P,G>{
		public:
			static void encode(std::istream &in, std::ostream &out);
			//decoding ceaser's cipher
			static void decode(std::istream &in, std::ostream &out);
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
			static void encode(std::istream &in, std::ostream &out);
			static void decode(std::istream &in, std::ostream &out);
	};
}
#endif
