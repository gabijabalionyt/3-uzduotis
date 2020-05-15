main:	funkcijos.o
	g++ -o output main.cpp funkcijos.o
prog:
	g++ -c funkcijos.cpp
clean:
	rm *.o output.exe File1000.txt File10000.txt File100000.txt File1000000.txt File10000000.txt Failed.txt Passed.txt
