#include <vector>
#include <set>
#include <string>
#include <algorithm>
#include <stack>
#include <sstream>
#include <thread>
#include <cctype> 
#include <unordered_set>
#include <queue>

using namespace std;


struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Node 
{
    public:
        int val;
        Node* left;
        Node* right;
        Node* next;
    
        Node() : val(0), left(NULL), right(NULL), next(NULL) {}
    
        Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}
    
        Node(int _val, Node* _left, Node* _right, Node* _next)
            : val(_val), left(_left), right(_right), next(_next) {}
};
  
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
     ListNode() : val(0), next(nullptr) {}
     ListNode(int x) : val(x), next(nullptr) {}
     ListNode(int x, ListNode *next) : val(x), next(next) {}
};
bool hasCycle(ListNode *head);
// [链表]两个链表表示的数字相加
ListNode* addTwoNumbers(ListNode* l1, ListNode* l2);
// [链表]合并两个有序链表
ListNode* mergeTwoLists(ListNode* list1, ListNode* list2);
// [链表]逆转部分链表
ListNode* reverseBetween(ListNode* head, int left, int right);
// 【链表】删除链表倒数第n个
ListNode* removeNthFromEnd(ListNode* head, int n);
// 【链表】删除链表中的重复元素
ListNode* deleteDuplicates(ListNode* head) ;
// [链表]向右平移后重新拼接
ListNode* rotateRight(ListNode* head, int k) ;
// [链表+哈希表]LRU
class LRUNode
{
public:
    LRUNode(int k = 0, int v = 0) : key(k), value(v) 
    {

    } 

public:
    int key;
    int value;
    LRUNode* prev;
    LRUNode* next;
};
class LRUCache {
public:
    LRUCache(int capacity) : capacity(capacity), dummy(new LRUNode())
    {
        dummy->prev = dummy;
        dummy->next = dummy;
    }
    
    int get(int key) 
    {
        LRUNode* node = get_node(key);
        return node ? node->value : -1;
    }
    
    void put(int key, int value) 
    {
        LRUNode* node = get_node(key);
        if(node)
        {
            node->value = value;
            return;
        }

        // 插入操作
        node = new LRUNode(key, value);
        map[key] = node;
        push_front(node);
        // 超出容量，删除最后一个
        if(map.size() > capacity)
        {
            LRUNode* tailNode = dummy->prev;
            map.erase(tailNode->key);   // 哈希表释放
            remove(tailNode);   // 从双链表中释放
            delete tailNode;    // 内存释放
        }
    }

private:
    LRUNode* get_node(int key)
    {
        auto iter = map.find(key);
        if(iter == map.end())
        {
            return nullptr;
        }

        LRUNode* node = iter->second;
        // 访问过 抽出来放到前面
        remove(node);   
        push_front(node);

        return node;
    }

    void remove(LRUNode* node)
    {
        if(node == nullptr)
        {
            return;
        }

        node->prev->next = node->next;
        node->next->prev = node->prev;
    }

    void push_front(LRUNode* node)
    {
        if(node == nullptr)
        {
            return;
        }

        node->prev = dummy;
        node->next = dummy->next;
        node->prev->next = node;
        node->next->prev = node;
    }

private:
    int capacity;
    LRUNode* dummy;  // 双链表的哨兵
    unordered_map<int, LRUNode*> map;   // 哈希表
};

// [二叉树]数最大高度
int maxDepth(TreeNode* root);
// [二叉树]相同的树
bool isSameTree(TreeNode* p, TreeNode* q) ;
// [二叉树]翻转二叉树
TreeNode* invertTree(TreeNode* root) ;
// [二叉树]判断对称二叉树
bool isSymmetric(TreeNode* root);
// [二叉树]从前序和中序遍历中构建二叉树
TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder);
// [二叉树]从中序和后序遍历中构建二叉树
TreeNode* buildTree2(vector<int>& inorder, vector<int>& postorder);
// [二叉树]路径长度
bool hasPathSum(TreeNode* root, int targetSum);
// [二叉树]节点个数
int countNodes(TreeNode* root);
// [二叉树]填充二叉树的next
Node* connect(Node* root);
// [二叉树]二叉树先序遍历展开为链表
void flatten(TreeNode* root);
// [二叉树]根节点到叶子节点数字拼接之和
int sumNumbers(TreeNode* root);
// [二叉树]最近公共祖先
TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q);