/*
traits for the crypt class
Copyright 2013 Zola Mahlaza
http://www.gnu.org/licenses/gpl-2.0.txt

"I have always wished for my computer to be as easy to use as my telephone;
my wish has come true because I can no longer figure out how to use my telephone.”

-Bjarne Stroustrup

*/
#ifndef _CRYPT_TRAITS
#define _CRYPT_TRAITS
#include<string>
#include<cstdint>
#include "cipher.hpp"
namespace mhlzol004{
	/*

	The key type for the general cipher is a string	

	*/
	template<class C>
	class crypt_trait{
		public:
			typedef std::string key_type_t;
			static std::string key;
	};
	template<class C> std::string crypt_trait<C>::key("");
	/*

	The key type for the ceaser cipher
	
	*/
	template<>
	class crypt_trait<Ceaser>{
		public:
			typedef int key_value_t;
			static int key;
	};
	int crypt_trait<Ceaser>::key = 0;
	/*

	The key type for the Xor is int32_t	

	*/
	template<>
	class crypt_trait<Xor>{
		public:
			typedef int32_t key_value_t;
			static int32_t key;
	};
	int32_t crypt_trait<Xor>::key = 0;
	/*

	The key type for the Vignere cipher is std::string

	*/
	template<>
	class crypt_trait<Vignere>{
		public:
			typedef std::string key_value_t;
			static std::string key;
	};
	std::string crypt_trait<Vignere>::key("");
}
#endif
