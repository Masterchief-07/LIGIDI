CC = clang
params = -Wall -Wextra -pedantic -Werror -lstdc++ -std=c++17
source = ../src
include = ../include

all: testSHA testUIntBase


testSHA: testSHA.cpp $(source)/sha256.cpp
	$(CC) $(params) -I$(include) $^ -o $@

testUIntBase: testUIntBase.cpp 
	$(CC) $(params) -I$(include) $^ -o $@

clean:
	rm -rf testSHA
