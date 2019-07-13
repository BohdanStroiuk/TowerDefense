CC = g++ -o
INC = -ID:/SFML-2.4.0/include
LIBS = -LD:/SFML-2.4.0/lib -lsfml-graphics -lsfml-window -lsfml-system


all: cl

cl: main.o Game.o Cache.o Map.o Level.o Menu.o Button.o BottomMenu.o PathFinder.o Enemy.o Tower.o EndMenu.o
	$(CC)  cl Obj/main.o Obj/Game.o Obj/Cache.o Obj/Map.o Obj/Level.o Obj/Menu.o Obj/Button.o Obj/BottomMenu.o Obj/PathFinder.o Obj/Enemy.o Obj/Tower.o Obj/EndMenu.o

EndMenu.o:
	$(CC)  Obj/EndMenu.o -c Source/EndMenu.cpp $(INC)

Tower.o:
	$(CC)  Obj/Tower.o -c Source/Tower.cpp $(INC)

Enemy.o:
	$(CC)  Obj/Enemy.o -c Source/Enemy.cpp $(INC)

PathFinder.o:
	$(CC)  Obj/PathFinder.o -c Source/PathFinder.cpp $(INC)

BottomMenu.o:
	$(CC)  Obj/BottomMenu.o -c Source/BottomMenu.cpp $(INC)

Button.o:
	$(CC)  Obj/Button.o -c Source/Button.cpp $(INC)

Menu.o:
	$(CC)  Obj/Menu.o -c Source/Menu.cpp $(INC)
Game.o: 
	$(CC)  Obj/Game.o -c Source/Game.cpp $(INC)

Cache.o:
	$(CC)  Obj/Cache.o -c Source/Cache.cpp $(INC)

Level.o:
	$(CC)  Obj/Level.o -c Source/Level.cpp $(INC)

Map.o:
	$(CC)  Obj/Map.o -c Source/Map.cpp $(INC)



main.o:
	$(CC)   Obj/main.o -c main.cpp $(INC)



game: main.o Game.o Cache.o Map.o Level.o Menu.o Button.o BottomMenu.o PathFinder.o Enemy.o Tower.o EndMenu.o
	$(CC)  game.exe Obj/main.o Obj/Game.o Obj/Cache.o Obj/Map.o Obj/Level.o Obj/Menu.o Obj/Button.o Obj/BottomMenu.o  Obj/PathFinder.o Obj/Enemy.o Obj/Tower.o Obj/EndMenu.o $(LIBS)

clean: cl
	rm -rf *.o  cl