#include <vector>
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
