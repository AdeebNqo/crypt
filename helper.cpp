/*

File for my helper functions
Copyright 2013 Zola Mahlaza

"You're posting to a Scheme group. Around here, arguing that Java
is better than C++ is like arguing that grasshoppers taste better than tree bark."

-Thant Tessman, comp.lang.scheme 

*/
namespace mhlzol004{
	/*
	Function for determining if char is a letter
	*/
	bool is_letter(char &some_char){
		int asci = (unsigned) some_char;
		if (asci>= 65 && asci <=90){
			return true;
		}
		else if(asci>=97 && asci<=122){
			return true;
		}
		return false;
	}
}

