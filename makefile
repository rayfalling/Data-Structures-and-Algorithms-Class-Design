CC=g++
CCFLAGS=-ansi -pedantic -std=c++11
MKDIR = mkdir -p

Source-Dirs := $(shell find ./src -maxdepth 5 -type d)

Sourece-Cpp-Files := $(foreach dir,$(Source-Dirs),$(wildcard $(dir)/*.cpp))
Sourece-C-Files := $(foreach dir,$(Source-Dirs),$(wildcard $(dir)/*.c))

Sourece-INC :=  $(foreach dir,$(Source-Dirs),$(wildcard $(dir)/*.hpp)) $(foreach dir,$(Source-Dirs),$(wildcard $(dir)/*.h))

Sourece-Obj := $(patsubst %.cpp,%.o, $(Sourece-Cpp-Files)) $(patsubst %.c,%.o, $(Sourece-C-Files))

BuildDir := build
ObjDir := $(BuildDir)/obj

all: directories server 

debug: CCFLAGS += -DDEBUG -g
debug: server

server: $(Sourece-INC) $(Sourece-Obj) 
	$(CC) $(Sourece-C-Files) $(Sourece-Cpp-Files) $(CCFLAGS) -o $(BuildDir)/main

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
	$(CC) $(CCFLAGS) -c $< -o $(ObjDir)/$(notdir $@)

%.o: %.c
	$(CC) $(CCFLAGS) -c $< -o $(ObjDir)/$(notdir $@)