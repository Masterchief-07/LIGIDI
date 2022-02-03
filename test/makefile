CC = clang
params = -Wall -Wextra -pedantic -Werror -lstdc++ -std=c++17
source = ../src
include = ../include


all: testSHA


testSHA: testSHA.cpp $(source)/sha256.cpp
	$(CC) $(params) -I$(include) $(source)/sha256.cpp testSHA.cpp -o testSHA

clean:
	rm -rf testSHA
