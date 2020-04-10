
OBJS = objs/main.o objs/Entity.o objs/EntityContainer.o objs/Maze.o objs/Vector.o objs/Block.o

LIBS = -lstdc++ -lm -lsfml-graphics -lsfml-window -lsfml-system -lGL

maze: $(OBJS)
	gcc $(OBJS) -o maze $(LIBS)

objs/main.o: main.cpp
	gcc -c main.cpp -o objs/main.o

objs/Entity.o: src/Entity.h src/Entity.cpp
	gcc -c src/Entity.cpp -o objs/Entity.o

objs/EntityContainer.o: src/EntityContainer.h src/EntityContainer.cpp
	gcc -c src/EntityContainer.cpp -o objs/EntityContainer.o

objs/Maze.o: src/Maze.h src/Maze.cpp
	gcc -c src/Maze.cpp -o objs/Maze.o

objs/Vector.o: src/Vector.h src/Vector.cpp
	gcc -c src/Vector.cpp -o objs/Vector.o

objs/Block.o: src/Block.h src/Block.cpp
	gcc -c src/Block.cpp -o objs/Block.o

clean:
	rm maze $(OBJS)
