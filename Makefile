OBJS = main.cpp game.cpp

OBJ_NAME = balloonacy

CC = g++

#COMPILER FLAGS are the compiler flags
#-w suppresses all warnings
COMPILER_FLAGS = -Wall -Wextra -pedantic

#LINKER_FLAGS specifies the libraries to link/load
LINKER_FLAGS = -lSDL2 -lSDL2_image -lSDL2_ttf

all: $(OBJS)
	$(CC) $(OBJS) $(COMPILER_FLAGS) $(LINKER_FLAGS) -o $(OBJ_NAME)
