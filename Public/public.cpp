#include "public.h"

void trim(std::string& str) 
{
    // 找到第一个非空白字符的位置
    auto start = std::find_if_not(str.begin(), str.end(), [](unsigned char ch) {
        return std::isspace(ch);
    });

    // 找到最后一个非空白字符的位置
    auto end = std::find_if_not(str.rbegin(), str.rend(), [](unsigned char ch) {
        return std::isspace(ch);
    }).base();      // 转正向迭代器

    // 如果 `start` 小于 `end`，截取子字符串；否则，返回空字符串
    str = (start < end) ? std::string(start, end) : std::string();
}