.PHONY: default

default: main.cpp
	clang++ -std=c++11 -I. main.cpp

dynaarray: dynamic_array.t.cpp
	clang++ -std=c++11 -Werror -Wall -I. dynamic_array.t.cpp
