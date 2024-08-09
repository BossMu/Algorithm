# Makefile

# 编译器
CXX = g++

# 编译选项
CXXFLAGS = -g -Wall

# 目标可执行文件
TARGET = test

# 源文件
SRCS = main.cpp ArraySolution.cpp

# 目标文件路径
OBJDIR = build
OBJS = $(SRCS:%.cpp=$(OBJDIR)/%.o)

# 规则：生成可执行文件
$(TARGET): $(OBJS)
	$(CXX) $(OBJS) -o $(TARGET)

# 规则：生成目标文件
$(OBJDIR)/%.o: %.cpp
	@mkdir -p $(OBJDIR)
	$(CXX) $(CXXFLAGS) -c $< -o $@

# 清理生成的文件
clean:
	rm -f $(OBJDIR)/*.o $(TARGET)
