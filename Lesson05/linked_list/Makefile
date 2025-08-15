CC := gcc
TARGET := linked_list

BIN_PATH := $(CURDIR)/../../bin
OUTPUT_PATH := $(BIN_PATH)/Lesson05/linked_list

INC_DIRS := /usr/local/include
LIB_DIRS := /usr/local/lib
LIB := cs50

LOCAL_COMMON_PATH := $(CURDIR)/common
LOCAL_INC_PATH := $(CURDIR)/inc
LOCAL_SRC_PATH := $(CURDIR)/src
LOCAL_LIB_PATH := $(OUTPUT_PATH)/bin

# 所有当前目录的.c文件都放在SRC里面
SRC = $(wildcard $(LOCAL_SRC_PATH)/*.c)
# 把SRC里面的.c文件替换为.o文件
OBJ = $(patsubst %.c, %.o,$(SRC))

CLAGS = -c -Wall -I$(INC_DIRS) -I$(LOCAL_INC_PATH) -I$(LOCAL_COMMON_PATH)
 
$(TARGET): $(OBJ)
	mkdir -p $(OUTPUT_PATH) 
	$(CC) -o $(OUTPUT_PATH)/$@ $^ -L $(LIB_DIRS) -l$(LIB)
 
%.o: %.c
	$(CC) $(CLAGS) $< -o $@ 
 
.PHONY: clean
clean:
	rm -f *.o $(TARGET)