/*
Given an array of integers, every element appears three times except for one. Find that single one.

Note:
Your algorithm should have a linear runtime complexity. Could you implement it without using extra memory?
*/

class Solution {
public:
    int singleNumber(vector<int>& nums) {
        vector<int> bits(32, 0);
        int result = 0;
        int i = 0, j = 0, mask = 0;
        
        for (; i < 32; i++) {
            mask = 1 << i;
            for (j = 0; j < nums.size(); j++) {
                bits[i] += ((nums[j] & mask) >> i);
            }
            bits[i] %= 3;
            result |= (bits[i] << i);
        }
        return result;
    }
};