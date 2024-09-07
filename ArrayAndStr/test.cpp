#include <stdio.h>
#include "ArrayAndStr.h"

void removeElementTest()
{
    vector<int> nums = {1,2,2,3,4};

    int ret = removeElement(nums, 2);
    printf("%d",ret);
}

void removeDuplicatesTest()
{
    vector<int> nums = {1};

    int ret = removeDuplicates(nums);
    printf("%d",ret);
}

void removeDuplicates2Test()
{
    vector<int> nums = {1,1,1,2,2,3,3,3};

    int ret = removeDuplicates2(nums);
    printf("%d",ret);
}

void majorityElementTest()
{
    vector<int> nums = {1,2,2,3,2,3,4};

    int ret = majorityElement(nums);
    printf("%d",ret);
}

void rotateTest()
{
    vector<int> nums;
    nums.push_back(1); 
    nums.push_back(2); 
    nums.push_back(3); 
    nums.push_back(4); 
    nums.push_back(5);
    nums.push_back(6); 
    nums.push_back(7); 

    rotate(nums,3);
    printf("-----");
}

void maxProfitTest()
{
    vector<int> nums = {7,30,2,5,3};

    int ret = maxProfit(nums);
    printf("%d",ret);
}

void maxProfitSumTest()
{
    vector<int> nums = {7,30,2,5,3};

    int ret = maxProfitSum(nums);
    printf("%d",ret);
}

void canJumpTest()
{
    // vector<int> nums = {2,3,1,1,4};
    vector<int> nums = {3,2,1,0,4};

    bool ret = canJump(nums);
    printf("%d",ret);
}

void jumpMinTimesTest()
{
    vector<int> nums = {2,3,1,1,4};

    int ret = jumpMinTimes(nums);
    printf("%d",ret);
}

void hIndexTest()
{
    // vector<int> nums = {3,0,6,1,5};
    vector<int> nums = {1,3,1};
    // vector<int> nums = {100};

    int ret = hIndex(nums);
    printf("%d",ret);
}

void RandomizedSetTest()
{
    int i = 0;
    RandomizedSet* rd = new RandomizedSet();
    rd->insert(0);
    rd->insert(1);
    rd->remove(0);
    rd->insert(2);
    rd->remove(1);
    while(i<100)
    {
        int ret = rd->getRandom();
        printf("%d",ret);
        i++;
    }
}

void productExceptSelfTest()
{
    vector<int> nums = {1,2,3,4};

    vector<int> tmp = productExceptSelf(nums);
    printf("----");
}

void canCompleteCircuitTest()
{
    vector<int> gas = {3,1,1};
    vector<int> cost = {1,2,2};

    int ret = canCompleteCircuit(gas, cost);
    printf("%d",ret);
}

void longestCommonPrefixTest()
{
    vector<string> strs = {"asd","asdf","as"};

    string s = longestCommonPrefix(strs);
    printf("%s",s.c_str());
}

void Test()
{
    string s1 = "11";
    string s2 = "222222222222222222222222asdasdasdav adasdasdasdasd";

    std::this_thread::sleep_for(std::chrono::seconds(1));
}

void strStrTest()
{
    string s1 = "sadbutsad";
    string s2 = "sad";

    int i = strStr(s1, s2);
    printf("%d",i);
}

void DiffAveTest()
{
    vector<string> strs = {"I","am","iron","man"};

    string s = DiffAve(strs, 21);
    printf("%s",s.c_str());
}

void isPalindromeTest()
{
    string s = "A man, a plan, a canal: Panama";

    bool b = isPalindrome(s);
    printf("------=%d", b);
}

void isSubsequenceTest()
{
    string s1 = "a";
    string s2 = "b";

    bool b = isSubsequence(s1, s2);
    printf("------=%d", b);
}

// void isSubsequenceTest()
// {
//     string s1 = "a";
//     string s2 = "b";

//     bool b = isSubsequence(s1, s2);
//     printf("------=%d", b);
// }

void minSubArrayLenTest()
{
    vector<int> nums = {2,3,1,2,4,3};

    int i = minSubArrayLen(7, nums);
    printf("%d", i);
}


void wordPatternTest()
{
    string s1 = "abba";
    string s2 = "dog cat cat dog";

    bool b = wordPattern(s1, s2);
    printf("%d", b);
}

int main() {
    
    // removeElementTest();    //2
    // removeDuplicatesTest(); //3
    // removeDuplicates2Test(); //4
    // majorityElementTest();  //5
    // rotateTest();        //6
    // maxProfitTest();        //7    
    // maxProfitSumTest();     //8   
    // canJumpTest();      //9
    // jumpMinTimesTest();     //10
    // hIndexTest();       //11
    // RandomizedSetTest();        //12
    // productExceptSelfTest();        //13
    // canCompleteCircuitTest();       //14
    // candyTest();        //分糖果

    // longestCommonPrefixTest();      //17 公共前缀

    // strStrTest();       // 子字符串
    // DiffAveTest();      //22 字符串居中

    // Test();  

    // isPalindromeTest(); // 23回文串
    // isSubsequenceTest();    // 24子串
    // minSubArrayLenTest();   // 28最小子数组

    // isIsomorphicTest();  //32 
    wordPatternTest();  //33)
}

