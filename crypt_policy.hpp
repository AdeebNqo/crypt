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
				std::cout << "encode called!" << std::endl;

				std::istream_iterator<char> end;
				std::istream_iterator<char> curr_pos(in);
				std::ostream_iterator<char> output(out, "");
				
				shift shifter(crypt_trait<Ceaser>::key);
				transform(curr_pos, end, output, shifter);
			};
			//decoding ceaser's cipher
			static void decode(std::istream &in, std::ostream &out){
				std::istream_iterator<char> end;
				std::istream_iterator<char> curr_pos(in);
				std::ostream_iterator<char> output(out, "");

				shift shifter(-crypt_trait<Ceaser>::key);
				transform(curr_pos, end, output, shifter);
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
