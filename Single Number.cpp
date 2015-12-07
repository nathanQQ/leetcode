/*
Given an array of integers, every element appears twice except for one. Find that single one.

Note:
Your algorithm should have a linear runtime complexity. Could you implement it without using extra memory?

*/

class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int result = 0;
        
        vector<int>::iterator itr;
        
        for (itr = nums.begin(); itr < nums.end(); itr++) {
            result ^= *itr;
        }
        
        return result;
    }
};