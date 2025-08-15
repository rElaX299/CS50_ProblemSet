BIN_PATH := $(CURDIR)/../../bin
OUTPUT_PATH := $(BIN_PATH)/Lesson02/readability

INC_DIRS := /usr/local/include
LIB_DIRS := /usr/local/lib
LIB := cs50

TARGET_1 := readability
OUTPUT_TARGET_1 := $(OUTPUT_PATH)/$(TARGET_1)
SRC_FILES_1 := readability.c

all: $(TARGET_1)

$(TARGET_1): $(SRC_FILES_1)
	mkdir -p $(OUTPUT_PATH)
	cc $(SRC_FILES_1) -g -o $(OUTPUT_TARGET_1) -I $(INC_DIRS) -L $(LIB_DIRS) -l$(LIB)
