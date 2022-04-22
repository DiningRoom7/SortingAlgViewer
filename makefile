SOURCE = ./src/*.cpp
INCLUDE = ./include
LIBS = ./lib

build: $(Source)
	export LD_LIBRARY_PATH="/usr/local/lib/SFML"
	g++ -c -I$(INCLUDE) $(SOURCE)
	g++ -o main *.o -L $(LIBS) -lpthread -lsfml-graphics -lsfml-window -lsfml-system -lsfml-audio
	rm -f *.o

run: build
	./main

clean:
	rm -rf main *.o /*/*.gch
