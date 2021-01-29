TARGET = bin/$(shell basename $(CURDIR))
CC = gcc
LIBS= -lm -L./lib 
INCLUDE = -I./include
CFLAGS = -Wall -g 
HEADER = $(wildcard include/*.h)
SRC = $(shell ls src)
OBJ = $(patsubst %.c,%.o,$(SRC))

.PHONY: default all clean

default: $(TARGET)
	@ printf "Build Successful!\n"

all: default 

%.o: src/%.c $(HEADER)
	@ printf "Compling: %s\n" $<
	@ $(CC) $(CFLAGS) -c $< $(INCLUDE)

.PRECIOUS: $(TARGET) $(OBJ)

$(TARGET): $(OBJ)
	@ printf "Linking:  %s\n" $^
	@ mkdir bin -p
	@ $(CC) $^ -Wall $(LIBS) -o $@ 

run: $(TARGET)
	@ printf "=============================== Runing %s ===============================\n" $(TARGET)
	./$(TARGET)


clean:
	@ printf "Cleaing %s\n" $(TARGET)
	@ printf "Cleaing %s\n" $(OBJ)
	@ rm -rf $(TARGET) $(OBJ)
	@ printf "Cleaned!\n"


