all: ttt

%: %.cpp
	g++ -std=c++11 $< -o $@.out

