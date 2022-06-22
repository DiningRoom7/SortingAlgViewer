SOURCE = ./src/*.cpp
LIBS = ./lib

build: $(Source)
	g++ -c -I./include $(SOURCE)
	g++ -o main *.o -L $(LIBS) -lpthread -lsfml-graphics -lsfml-window -lsfml-system -lsfml-audio
	rm -f *.o

run: build
	./main

clean:
	rm -rf main *.o /*/*.gch
