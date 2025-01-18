#include <vector>
#include <set>
#include <string>
#include <algorithm>
#include <stack>
#include <sstream>
#include <thread>
#include <cctype> 
#include <unordered_set>

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
// 【哈希表】字符串异位
bool isAnagram(string s, string t);
// 【哈希表】字符串异位分组
vector<vector<string>> groupAnagrams(vector<string>& strs);
// 【哈希表】快乐数
bool isHappy(int n);
// 【哈希表】重复数字间隔
bool containsNearbyDuplicate(vector<int>& nums, int k);
// 【双链表】最长连续序列
int longestConsecutive(vector<int>& nums);
// 【双链表】汇总区间
vector<string> summaryRanges(vector<int>& nums);
// [双指针+贪心] 区间合并
vector<vector<int>> merge(vector<vector<int>>& intervals);
// [双指针+贪心] 插入后区间合并
vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval);
// [贪心] 射气球最少箭
int findMinArrowShots(vector<vector<int>>& points);
// [栈]有效的括号
bool isValid(string s);
// [栈]最小栈
class MinStack 
{
public:
    MinStack() 
    {
        stMin.push(INT_MAX);
    }
    
    void push(int val) 
    {
        st.push(val);
        stMin.push(min(stMin.top(), val));
    }
    
    void pop() 
    {
        st.pop();
        stMin.pop();
    }
    
    int top() 
    {
        return st.top();
    }
    
    int getMin() 
    {
        return stMin.top();
    }
private:
    stack<int> st;
    stack<int> stMin;
};
// [栈]逆波兰表达式
int evalRPN(vector<string>& tokens);
// [栈]加减运算器
int calculate(string s) ;
// [快慢指针]判断环形链表
struct ListNode 
{
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};
bool hasCycle(ListNode *head);
// 两个链表表示的数字相加
ListNode* addTwoNumbers(ListNode* l1, ListNode* l2);



