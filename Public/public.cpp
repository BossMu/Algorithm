#include "public.h"

void stringUtils::trim(std::string& str) 
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

void stringUtils::splitStr(string& s, vector<string>& vec, char c)
{
    int size = s.size();
    int wordStart = 0;  // 单词的起点索引
    int wordEnd = 0;    // 单词的终点索引（边界或指向空格），不包含

    while(wordEnd < size)
    {
        while (wordEnd < size && s[wordEnd] == c) wordEnd++;  // 跳过连续的分隔符
        wordStart = wordEnd;  // 设置下一个单词的起点
        while (wordEnd < size && s[wordEnd] != c) wordEnd++; // 找这次的字符串直到分隔符
        if (wordStart < wordEnd) 
        {
            vec.push_back(s.substr(wordStart, wordEnd - wordStart));
        }
    }
}