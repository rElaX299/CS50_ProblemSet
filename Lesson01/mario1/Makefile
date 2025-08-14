TARGET := lesson1_mario1
OUTPUT_PATH := $(CURDIR)/../../bin/
OUTPUT_TARGET := $(OUTPUT_PATH)$(TARGET)
files := mario1.c
INC_DIRS := /usr/local/include
LIB_DIRS := /usr/local/lib
LIB := cs50

$(TARGET): $(files)
	mkdir -p $(OUTPUT_PATH)
	cc $(files) -o $(OUTPUT_TARGET) -I $(INC_DIRS) -L $(LIB_DIRS) -l$(LIB)
