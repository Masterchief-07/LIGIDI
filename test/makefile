CC = clang
params = -Wall -Wextra -pedantic -Werror -lstdc++ -std=c++17


all: testSHA


testSHA: testSHA.cpp
	$(CC) $(params) -I../include ../src/sha256.cpp testSHA.cpp -o testSHA

clean:
	rm -rf testSHA
