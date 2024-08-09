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
extern char _end[];
int main() {
    
    // removeElementTest();    //2
    // removeDuplicatesTest(); //3



}

