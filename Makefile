all:
	g++ -Wall -O3 -std=c++11 ./loss/loss.cpp ./model/model.cpp ./optimizer/sgd.cpp test.cpp -o test

clean:
	rm test
