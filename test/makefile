CC = clang
params = -Wall -Wextra -pedantic -Werror -lstdc++ -std=c++17
source = ../src
include = ../include
alltest = testSHA testUIntBase testRandom

all: $(alltest)


testSHA: testSHA.cpp $(source)/sha256.cpp
	$(CC) $(params) -I$(include) $^ -o $@

testUIntBase: testUIntBase.cpp 
	$(CC) $(params) -I$(include) $^ -o $@

testRandom: testRandom.cpp
	$(CC) $(params) -I$(include) $^ -o $@

clean:
	rm -rf $(alltest) 
