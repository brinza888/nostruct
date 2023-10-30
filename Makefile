CC = gcc
CFLAGS = -Wall -g
LDFLAGS = 

BIN = bin/
SOURCES = main.c
OBJECTS = $(addprefix $(BIN), $(SOURCES:.c=.o))
EXE = main


.PHONY: all
all: $(EXE)


$(EXE): $(OBJECTS)
	$(CC) $(CFLAGS) $(OBJECTS) -o $(EXE) $(LDFLAGS)


$(BIN)%.o: %.c $(BIN)
	$(CC) $(CFLAGS) -c $< -o $@


$(BIN):
	@mkdir -p $(BIN)


.PHONY: clean
clean:
	@rm -rf $(BIN)
	@rm -f $(EXE)
