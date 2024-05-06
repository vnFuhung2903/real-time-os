main:
	g++ -o main main.cpp EdfAlgorithm.cpp 

testedf:
	g++ -o testedf test.cpp EdfAlgorithm.cpp 

testNEDF:
	g++ -o testNEDF test.cpp EdfAlgorithm.cpp

test:
	g++ -o test test.cpp