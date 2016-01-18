.PHONY: default

default: main.cpp
	clang++ -std=c++11 -I. main.cpp
