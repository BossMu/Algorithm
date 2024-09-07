/*
--------- 一些cpp的公共方法 -----------
*/

#include <vector>
#include <set>
#include <string>
#include <algorithm>
#include <stack>
#include <sstream>
#include <thread>
#include <cctype> 

using namespace std;

class stringUtils
{
public:
    // 去除字符串两侧空格
    static void trim(std::string& str);
    // 字符串按照分隔符分隔，支持中间多个分割符
    static void splitStr(string& s, vector<string>& vec, char c);
};