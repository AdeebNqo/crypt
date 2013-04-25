# Makefile for crypt project
# Zola Mahlaza
#
options = -std=c++11 -W
headers = crypt.hpp functor.hpp crypt_trait.hpp crypt_policy.hpp
app_name = crypt
com = g++
$(app_name): main.cpp $(headers)
	@$(com) $(options) -o crypt main.cpp
run:
	@./$(app_name)
clean:
	@rm -f $(app_name)
