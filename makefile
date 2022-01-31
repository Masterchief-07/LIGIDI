params = -Wall -Wextra -pedantic -lstdc++ -Og -g
CC = clang

main: main.cpp
	${CC} ${params} $^ -o $@

clean:
	rm -rf main
