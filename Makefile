CC         = gcc
CFLAGS     = -g -Werror
LIBS       = -lm
SOURCES    = main.c
EXECUTABLE = calculator

all:
	$(CC) $(CFLAGS) $(SOURCES) $(LIBS) -o $(EXECUTABLE)

clean:
	find . -name '*.o' -type f -delete
	rm $(EXECUTABLE)
