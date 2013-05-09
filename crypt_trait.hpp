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
			static bool pack;
			static bool group;
	};
	template<class C> std::string crypt_trait<C>::key("");
	template<class C> bool crypt_trait<C>::pack = false;
	template<class C> bool crypt_trait<C>::group = false;
	/*

	The key type for the ceaser cipher
	
	*/
	template<>
	class crypt_trait<Ceaser>{
		public:
			typedef int key_value_t;
			static int key;
			static bool pack;
			static bool group;
	};
	int crypt_trait<Ceaser>::key = 0;
	bool crypt_trait<Ceaser>::pack = false;
	bool crypt_trait<Ceaser>::group = false;
	/*

	The key type for the Xor is int32_t	

	*/
	template<>
	class crypt_trait<Xor>{
		public:
			typedef int32_t key_value_t;
			static int32_t key;
			static bool pack;
			static bool group;
	};
	int32_t crypt_trait<Xor>::key = 0;
	bool crypt_trait<Xor>::pack = false;
	bool crypt_trait<Xor>::group = false;
	/*

	The key type for the Vignere cipher is std::string

	*/
	template<>
	class crypt_trait<Vignere>{
		public:
			typedef std::string key_value_t;
			static std::string key;
			static bool pack;
			static bool group;
	};
	std::string crypt_trait<Vignere>::key("");
	bool crypt_trait<Vignere>::pack = false;
	bool crypt_trait<Vignere>::group = false;
}
#endif
