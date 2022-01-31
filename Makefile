CFLAGS= -c -std=c99
LDFLAGS=

SOURCES= $(wildcard src/*.c)
OBJECTS= $(SOURCES:.c=.o)
EXECUTABLE = QAdventure3

all: $(SOURCES) $(EXECUTABLE)

run: all
	./$(EXECUTABLE)

$(EXECUTABLE): $(OBJECTS)
		$(CC) $(LDFLAGS) $(OBJECTS) -o $@

.c.o:
		$(CC) $(CFLAGS) $< -o $@

clean:
	rm -f $(OBJECTS) $(EXECUTABLE)
	rm -f core.* vgcore.* callgrind.out.*
