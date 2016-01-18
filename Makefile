.PHONY: default

default: main.cpp
	g++ -std=c++11 -I. main.cpp
