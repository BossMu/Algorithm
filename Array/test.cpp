#include <stdio.h>
#include "ArraySolution.h"

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

int main() {
    
    // removeElementTest();    //2
    // removeDuplicatesTest(); //3
    // removeDuplicates2Test(); //4
    // majorityElementTest();  //5
    // rotateTest();        //6
    // maxProfitTest();        //7    
    // maxProfitSumTest();     //8   
    // canJumpTest();      //9
    jumpMinTimesTest();     //10

}

