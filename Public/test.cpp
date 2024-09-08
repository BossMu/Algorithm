#include "public.h"

void trimTest()
{
    string s = "   hello mjh    ";
    stringUtils::trim(s);

    printf("%s", s.c_str());
}

void splitStrTest()
{
    string s = "   hello   mjh  abc  ";
    vector<string> vec;
    stringUtils::splitStr(s, vec, ' ');

    printf("%s", s.c_str());
}

int main() 
{
    trimTest();      
    splitStrTest();
}