
OBJS = objs/main.o objs/Entity.o objs/EntityContainer.o objs/Maze.o objs/TextureHolder.o \
       objs/Camera.o objs/Player.o objs/Animation.o objs/AnimationSet.o objs/Block.o \
       objs/HUD.o

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

objs/Player.o: src/Player.h src/Player.cpp
	gcc -c src/Player.cpp -o objs/Player.o

objs/Animation.o: src/Animation.h src/Animation.cpp
	gcc -c src/Animation.cpp -o objs/Animation.o

objs/AnimationSet.o: src/AnimationSet.h src/AnimationSet.cpp
	gcc -c src/AnimationSet.cpp -o objs/AnimationSet.o

objs/Block.o: src/Block.h src/Block.cpp
	gcc -c src/Block.cpp -o objs/Block.o

objs/HUD.o: src/HUD.h src/HUD.cpp
	gcc -c src/HUD.cpp -o objs/HUD.o

clean:
	rm maze $(OBJS)

run: 
	./maze
