# 编译器
CXX = g++

# 编译选项
CXXFLAGS = -g -Wall -std=c++11

# 目标可执行文件
TARGET = test

# 源文件
SRCS = test.cpp ArrayAndStr.cpp

# 目标文件路径
OBJDIR = build
OBJS = $(SRCS:%.cpp=$(OBJDIR)/%.o)

# 代码签名证书名称（仅在 macOS 上使用）
CODESIGN_CERT = lldb-cert

# 识别操作系统
UNAME_S := $(shell uname -s)

# 规则：生成可执行文件
$(TARGET): $(OBJS)
	$(CXX) $(OBJS) -o $(TARGET)

# mac签名，防止权限问题 
ifeq ($(UNAME_S), Darwin)
	@echo "正在对 $(TARGET) 进行代码签名..."
	codesign -s "$(CODESIGN_CERT)" $(TARGET)
	@echo "代码签名完成"
endif

# 规则：生成目标文件
$(OBJDIR)/%.o: %.cpp
	@mkdir -p $(OBJDIR)
	$(CXX) $(CXXFLAGS) -c $< -o $@

# 清理生成的文件
clean:
	rm -f $(OBJS) $(TARGET)
