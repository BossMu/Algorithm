#include "public.h"

void trimTest()
{
    string s = "   hello mjh    ";
    stringUtils::trim(s);

    printf("%s", s.c_str());
}

int main() 
{
    trimTest();      

}