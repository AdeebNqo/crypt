# Makefile for crypt project
# Zola Mahlaza
#
options = -std=c++11 -W -L/usr/include/ -lboost_program_options
headers = crypt.hpp functor.hpp crypt_trait.hpp crypt_policy.hpp cmdline_parser.h
objects = cmdline_parser.o helper.o
app_name = crypt
com = g++
$(app_name): main.cpp $(headers) $(objects)
	@$(com) -o crypt $(objects) main.cpp $(options)
run:
	@./$(app_name)
cmdline_parser.o: cmdline_parser.cpp
	@g++ -std=c++11 cmdline_parser.cpp -c
helper.o: helper.cpp
	@g++ -std=c++11 helper.cpp -c
clean:
	@rm -f $(app_name) $(objects)
