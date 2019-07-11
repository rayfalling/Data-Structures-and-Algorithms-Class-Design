CC=g++
CLAGS=-g -ansi -pedantic -std=c++11
MKDIR = mkdir -p

Source-Dirs := $(shell find ./src -maxdepth 5 -type d)

Sourece-Cpp-Files := $(foreach dir,$(Source-Dirs),$(wildcard $(dir)/*.cpp))
Sourece-C-Files := $(foreach dir,$(Source-Dirs),$(wildcard $(dir)/*.c))

Sourece-Cpp-INC := $(patsubst %.cpp,%.hpp, $(Sourece-Cpp-Files))
Sourece-C-INC := $(patsubst %.c,%.h, $(Sourece-C-Files))

Sourece-Obj := $(patsubst %.cpp,%.o, $(Sourece-Cpp-Files)) $(patsubst %.c,%.o, $(Sourece-C-Files))

BuildDir := ./build
ObjDir := $(BuildDir)/obj

all: directories server 

server: $(Sourece-C-INC) $(Sourece-Cpp-INC) $(Sourece-Obj) 
	$(CC) $(Sourece-C-Files) $(Sourece-Cpp-Files) $(CFLAGS) -o $(BuildDir)/main

directories: $(BuildDir) $(ObjDir)

$(BuildDir):
	$(MKDIR) $(BuildDir)

$(ObjDir):
	$(MKDIR) $(ObjDir)

.PHONY: directories
clean: 
	rm $(ObjDir)/*.o
	rm $(BuildDir)/main

%.o: %.cpp
	$(CC) $(CFLAGS) -c $< -o $(ObjDir)/$(notdir $@)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $(ObjDir)/$(notdir $@)