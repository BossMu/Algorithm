#include "ArraySolution.h"

void test()
{

}

void mergeSortedVector(vector<int>& nums1, int m, vector<int>& nums2, int n) 
{
    // 逆序遍历，3个指针，两个数组中的较小者与遍历指针交换
    int i = nums1.size() - 1;
    m--;
    n--;

    while(n >= 0)
    {
        // 只有m还有，并且更大的时候一直自身交换，直到m没了或是n更大
        while(m >= 0 && nums1[m] > nums2[n])
        {
            swap(nums1[m--], nums1[i--]);
        }   
        // m没了但n还有，交换n；m还有但是n更大
        swap(nums2[n--], nums1[i--]);
    }

}

int removeElement(vector<int>& nums, int val) 
{
    int iBegin = 0;
    int iEnd = nums.size() - 1;

    while(iBegin <= iEnd)
    {
        // 左边找到第一个val
        while(iBegin <= iEnd && nums[iBegin] != val)
        {
            iBegin++;
        }
        
        while(iBegin <= iEnd && nums[iEnd] == val)
        {
            iEnd--;
        }

        if(iBegin <= iEnd)
        {
            nums[iBegin] = nums[iEnd];
            iBegin++;
            iEnd--;
        }
    }

    return iBegin;
}

int removeDuplicates(vector<int>& nums) 
{
    int32_t i = 0;
    int32_t j = 0;
    int32_t iLen = nums.size();

    while(j < iLen)
    {
        while(j < iLen && nums[i] == nums[j])
        {
            ++j;
        }

        if(j < iLen)
        {
            i++;
            nums[i] = nums[j];
        }
    }      

    return i + 1;  
}

int removeDuplicates2(vector<int>& nums) 
{ 
    int i = 2;
    int j = 2;
    int ilen = nums.size(); 

    if(ilen <= 2)
    {
        return ilen;
    }

    for(j = 2; j < ilen; j++)
    {
        // i-当前被替换位置 j-下一个新元素
        // i-2 == j 时表示中间的都是相同元素，直接跳过
        if(nums[i-2] != nums[j])
        {
            nums[i] = nums[j];
            i++;
        }
    }

    return i;
}

int majorityElement(vector<int>& nums) 
{
    int iLen = nums.size();
    if(iLen <= 0)
    {
        return -1;
    }

    int maxNum = nums[0];
    int count = 1;

    for(int i = 1; i < iLen; i++)
    {
        if(nums[i] == maxNum)
        {
            count++;
        }
        else
        {
            count--;
        }

        if(count <= 0)
        {
            maxNum = nums[i];
            count = 1;
        }
    }

    return maxNum;
}

void rotate(vector<int>& nums, int k) 
{
    auto reverse = [&](int i, int j)
    {
        while (i < j)
        {
            swap(nums[i++], nums[j--]);
        }
    };

    int size = nums.size();
    k %= size;
    
    reverse(0, size-1);
    reverse(0, k-1);
    reverse(k, size-1);
}

int maxProfit(vector<int>& prices)
{
    int iMinPrice = INT_MAX;
    int iMaxRange = 0;

    for(int price : prices)
    {
        iMinPrice = min(iMinPrice, price);
        iMaxRange = max(iMaxRange,(price - iMinPrice));
    }

    return iMaxRange; 
}

int maxProfitSum(vector<int>& prices) 
{
    int iTodayRange = 0;
    int sum = 0;
    int size = prices.size();

    if(size <= 1)
    {
        return 0;
    }

    for(int i = 1; i < size; i++)
    {
        iTodayRange = prices[i] - prices[i-1];
        if(iTodayRange > 0)
        {
            sum += iTodayRange;
        }
    }

    return sum;
}

bool canJump(vector<int>& nums) 
{
    int size = nums.size();
    int iRoad = 0;

    for(int i = 0; i < size; i++)
    {
        if(iRoad < i) return false;     // 当前的路已经追不上人了

        iRoad = max(iRoad, i + nums[i]);
    }

    // 全部遍历完说明走到最后
    return true;
}

int jumpMinTimes(vector<int>& nums) 
{
    int iMax = 0;
    int iTmpEnd = 0;
    int iTimes = 0;
    int sizeIndex = nums.size() - 1;

    for(int i = 0;i <= sizeIndex; i++)
    {       
        // 走到本轮结束位置每次先+1 因此本轮能到终点至退出就好
        if(iTmpEnd >= sizeIndex) break;

        // 到达当前位置时次数才+1
        iMax = max(iMax, i + nums[i]);
        if(i == iTmpEnd)
        {
            iTimes++;
            iTmpEnd = iMax;
        }
    }

    return iTimes;
}