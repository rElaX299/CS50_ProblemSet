BIN_PATH := $(CURDIR)/../../bin
OUTPUT_PATH := $(BIN_PATH)/Lesson01/mario

INC_DIRS := /usr/local/include
LIB_DIRS := /usr/local/lib
LIB := cs50

TARGET_1 := mario1
OUTPUT_TARGET_1 := $(OUTPUT_PATH)/$(TARGET_1)
SRC_FILES_1 := mario1.c

TARGET_2 := mario2
OUTPUT_TARGET_2 := $(OUTPUT_PATH)/$(TARGET_2)
SRC_FILES_2 := mario2.c

all: $(TARGET_1) $(TARGET_2)

$(TARGET_1): $(files)
	mkdir -p $(OUTPUT_PATH)
	cc $(SRC_FILES_1) -o $(OUTPUT_TARGET_1) -I $(INC_DIRS) -L $(LIB_DIRS) -l$(LIB)

$(TARGET_2): $(files)
	mkdir -p $(OUTPUT_PATH)
	cc $(SRC_FILES_2) -o $(OUTPUT_TARGET_2) -I $(INC_DIRS) -L $(LIB_DIRS) -l$(LIB)
