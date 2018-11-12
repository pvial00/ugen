CC=gcc
CFLAGS=-O3 -std=c99
TARGET=ugen
all: $(TARGET)

$(TARGET): ugen_main.c
	$(CC) ugen_main.c $(CFLAGS) -o $(TARGET)

clean:
	$(RM) $(TARGET)
