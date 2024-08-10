#include <stdio.h>
#include "ArraySolution.h"

void removeElementTest()
{
    vector<int> nums;
    nums.push_back(1);
    nums.push_back(2);
    nums.push_back(2);
    nums.push_back(3);
    nums.push_back(4);

    int ret = removeElement(nums, 2);
    printf("%d",ret);
}

void removeDuplicatesTest()
{
    vector<int> nums;
    nums.push_back(1);
    // nums.push_back(2);
    // nums.push_back(2);
    // nums.push_back(3);
    // nums.push_back(3);
    // nums.push_back(3);
    // nums.push_back(4);

    int ret = removeDuplicates(nums);
    printf("%d",ret);
}

void removeDuplicates2Test()
{
    vector<int> nums;
    nums.push_back(1); 
    nums.push_back(1);
    nums.push_back(1);
    nums.push_back(2); 
    nums.push_back(2); 
    nums.push_back(3); 
    nums.push_back(3);
    nums.push_back(3); 

    int ret = removeDuplicates2(nums);
    printf("%d",ret);
}

void majorityElementTest()
{
    vector<int> nums;
    nums.push_back(1); 
    nums.push_back(2); 
    nums.push_back(2); 
    nums.push_back(3); 
    nums.push_back(2);
    nums.push_back(3); 
    nums.push_back(4); 

    int ret = majorityElement(nums);
    printf("%d",ret);
}

int main() {
    
    // removeElementTest();    //2
    // removeDuplicatesTest(); //3
    // removeDuplicates2Test(); //4
    majorityElementTest();  //5

}

