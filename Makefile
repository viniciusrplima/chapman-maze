
OBJS = objs/main.o objs/Entity.o objs/EntityContainer.o objs/Maze.o objs/TextureHolder.o \
       objs/Camera.o

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

objs/TextureHolder.o: src/TextureHolder.h src/TextureHolder.cpp
	gcc -c src/TextureHolder.cpp -o objs/TextureHolder.o

objs/Camera.o: src/Camera.h src/Camera.cpp
	gcc -c src/Camera.cpp -o objs/Camera.o

clean:
	rm maze $(OBJS)

run: 
	./maze
