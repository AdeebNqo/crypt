Ciphers and Templates?
======================

> Zola Mahlaza

> Assignment 4 of c++

> May 2013


Compiling
----------
The rules are as follows:

####compiling:

    make

####running:

    make run
    
####running with options:

    ./crypt --some_options
    
Sample
--------
A test file named `test.txt` is used to illutrate the ceaser's cipher:

####string input

        abcdefghijklmnopqrstuvwxyz

####program commands

        ./crypt -e -c 2 -i test.txt
        
####output

        cdefghijklmnopqrstuvwxyzab
        
Assumptions and General remarks
-------------------------------

1.

I did not understand the point of the `packing` option. I did as the spec said:

        You can do this by shifting the second chars bits right by 3 places
        ,the third chars right by 6 places, the fourth chars right by 9 
        places and so on.
    
The problem, however, with doing this is that it results to characters which seem not to be writable onto a ostream object.

To confirm that they actually exist, open `helper.cpp`. Change line 81 from
`out << param;` to `std::cout << param`.


2.

My program works for both lower and uppercase. I was unaware that we have to worry about upper case letters only.

3.

The spec also states that:
    
        Give the markers an example of both
        
This is refering to lambdas and functors. I have a file named `functor.hpp`.
This file contains all functors I have used (and not used). The lambdas can be found in `crypt_policy.hpp`
