/*
Given an array containing n distinct numbers taken from 0, 1, 2, ..., n, find the one that is missing from the array.

For example,
Given nums = [0, 1, 3] return 2.

Note:
Your algorithm should run in linear runtime complexity. Could you implement it using only constant extra space complexity?
*/

class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int size = nums.size();
        int cnt = 0;
        int sum = ((0 + size) * (size + 1)) / 2;  //miss 1 item, so size should plus 1
        
        for (; cnt < size; cnt++) { 
            sum -= nums[cnt];
        }
        
        return sum;
        
    }
};