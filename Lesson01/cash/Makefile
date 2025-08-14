BIN_PATH := $(CURDIR)/../../bin
OUTPUT_PATH := $(BIN_PATH)/Lesson01/cash

INC_DIRS := /usr/local/include
LIB_DIRS := /usr/local/lib
LIB := cs50

TARGET_1 := cash
OUTPUT_TARGET_1 := $(OUTPUT_PATH)/$(TARGET_1)
SRC_FILES_1 := cash.c

all: $(TARGET_1)

$(TARGET_1): $(files)
	mkdir -p $(OUTPUT_PATH)
	cc $(SRC_FILES_1) -o $(OUTPUT_TARGET_1) -I $(INC_DIRS) -L $(LIB_DIRS) -l$(LIB)
