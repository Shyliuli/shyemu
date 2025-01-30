CC = gcc
CFLAGS = -Wall -Wextra -Werror -g -Og -Wno-error=unused-parameter
SRC_DIR = src
BUILD_DIR = build
TARGET = $(BUILD_DIR)/shyemu
SRCS = $(wildcard $(SRC_DIR)/*.c)
OBJS = $(patsubst $(SRC_DIR)/%.c, $(BUILD_DIR)/%.o, $(SRCS))
all: $(BUILD_DIR) $(TARGET)

# 创建构建目录
$(BUILD_DIR):
	mkdir -p $@

# 链接目标文件生成可执行文件
$(TARGET): $(OBJS)
	$(CC) $(CFLAGS) $^ -o $@ $(LDFLAGS)

# 编译每个.c文件到.o文件
$(BUILD_DIR)/%.o: $(SRC_DIR)/%.c
	$(CC) $(CFLAGS) -c $< -o $@

# 清理生成文件
clean:
	rm -rf $(TARGET) $(BUILD_DIR)

# 伪目标声明
.PHONY: all clean

# 自动处理头文件依赖（可选）
-include $(OBJS:.o=.d)