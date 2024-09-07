#include <vector>
#include <set>
#include <string>
#include <algorithm>
#include <stack>
#include <sstream>
#include <thread>
#include <cctype> 

using namespace std;

// class ArraySolution 
// {
// public:
// void test();

//     // // 合并两个有序数组
//     // void mergeSortedVector(vector<int>& nums1, int m, vector<int>& nums2, int n);

//     // // 删除数组指定元素
//     // int removeElement(vector<int>& nums, int val);
// };

//  合并两个有序数组
void mergeSortedVector(vector<int>& nums1, int m, vector<int>& nums2, int n);
//  删除数组指定元素
int removeElement(vector<int>& nums, int val);
//  删除数组中重复元素
int removeDuplicates(vector<int>& nums); 
//  删除数组中重复元素保留两个
int removeDuplicates2(vector<int>& nums); 
// 查找数组中的过半元素（一定有）
int majorityElement(vector<int>& nums);
// 顺时针移动元素
void rotate(vector<int>& nums, int k) ;
// 找数组最大拉抬波段
int maxProfit(vector<int>& prices);
// 数组所有拉抬波段
int maxProfitSum(vector<int>& prices);
// 数组跳跃
bool canJump(vector<int>& nums);
// 最少跳跃次数
int jumpMinTimes(vector<int>& nums); 
// n个大于等于n的数
int hIndex(vector<int>& citations);
// random 类
class RandomizedSet {
public:
    RandomizedSet() 
    {

    }
    
    bool insert(int val) 
    {
        bool bRet = false;

        auto iter = m_hash.find(val);
        if(iter == m_hash.end())
        {
            m_vec.push_back(val);
            m_hash[val] = m_vec.size() - 1;
            bRet = true;
        }

        return bRet;
    }
    
    bool remove(int val) 
    {
        bool bRet = false;

        auto iter = m_hash.find(val);
        if(iter != m_hash.end())
        {
            int iLast = m_vec.size()-1;
            int iDel = m_hash[val];
            m_vec[iDel] = m_vec[iLast];
            m_vec.pop_back();
            m_hash[m_vec[iDel]] = iDel;
            m_hash.erase(val);
            bRet = true;
        }

        return bRet;
    }
    
    int getRandom() 
    {
        int iSize = m_vec.size();
        int iRandom = rand()%iSize;
        return m_vec[iRandom];
    }
private:
    unordered_map<int, int> m_hash;
    vector<int> m_vec; 
};
// 数组除自己外的乘积
vector<int> productExceptSelf(vector<int>& nums);
// 加油站
int canCompleteCircuit(vector<int>& gas, vector<int>& cost) ;
// 分配糖果
int candy(vector<int>& ratings);
// 最后一个字符串的长度
int lengthOfLastWord(string s);
// 最长的公共前缀
string longestCommonPrefix(vector<string>& strs) ;
// 翻转字符串的单词
string reverseWords(string s) ;
// 接雨水
int trap(vector<int>& height);
// z字型变换
string convertZ(string s, int numRows);
// 字符串子串
int strStr(string haystack, string needle) ;
// 居中字符串
string DiffAve(vector<string> strVec, int width);
// 回文串
bool isPalindrome(string s);
// 判断子序列
bool isSubsequence(string s, string t) ;
// 两数之和
vector<int> twoSum(vector<int>& numbers, int target) ;
// 最大面积
int maxArea(vector<int>& height) ;
// 3数之和
vector<vector<int>> threeSum(vector<int>& nums) ;
// 【滑动窗口】长度最小子数组
int minSubArrayLen(int target, vector<int>& nums) ;
// 【滑动窗口】最长无重复子串
int lengthOfLongestSubstring(string s) ;
// 【滑动窗口】最小包含子串
string minWindow(string s, string t);
// 【哈希表】字符串重新构建
bool canConstruct(string ransomNote, string magazine) ;
// 【哈希表】同构字符串
bool isIsomorphic(string s, string t);
// 【哈希表】字符串匹配
bool wordPattern(string pattern, string s);