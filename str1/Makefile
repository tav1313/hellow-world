# Make standard vars
CC = gcc-12
CFLAGS = -fPIC
VPATH = src:build

# Paths
BUILD_DIR = build
BIN_DIR = $(BUILD_DIR)/bin

# Libs
LIBS = gtk4

# Specify paths to headers
INCLUDES = $(shell pkg-config --cflags $(LIBS))

# Specify paths to the libraries
LDFLAGS = $(shell pkg-config --libs-only-L $(LIBS))

# Specify the link libraries
LLIBS = $(shell pkg-config --libs-only-l $(LIBS))

# TODO: add the rule to compile ALL .c files
# and pass them as a prerequsites to build the output executable

$(BIN_DIR)/main : main.o rs1.o
	mkdir -p $(BIN_DIR)
	$(CC) -g $(LDFLAGS) $(LLIBS) $? -o $@

$(BUILD_DIR)/main.o : main.c
	mkdir -p $(BUILD_DIR)
	$(CC) -g -c -pthread $(CFLAGS) $(INCLUDES) $? -o $@

$(BUILD_DIR)/rs1.o : rs1.c
	$(CC) -g -c -pthread $(CFLAGS) $(INCLUDES) $? -o $@

.PHONY := clean
clean:
	rm -rvf $(BUILD_DIR)

.PHONY := run
run: $(BIN_DIR)/main
	$(BIN_DIR)/main