/*
Given an array of numbers nums, in which exactly two elements appear only once and all the other elements appear exactly twice. 
Find the two elements that appear only once.

For example:

Given nums = [1, 2, 1, 3, 2, 5], return [3, 5].

Note:
The order of the result is not important. So in the above example, [5, 3] is also correct.
Your algorithm should run in linear runtime complexity. Could you implement it using only constant space complexity?
*/

class Solution {
public:
    vector<int> singleNumber(vector<int>& nums) {
        int sum = 0;
        int i = 0;
        vector<int> result(2,0);
        
        for (; i < nums.size(); i++) {
            sum ^= nums[i];
        }
        
        //Get the minumum bit of sum, and assign it to sum
        sum &= (-sum);
        
        for (i = 0; i < nums.size(); i++) {
            if (sum & nums[i]) {
                result[0] ^= nums[i];
            }
            else {
                result[1] ^= nums[i];
            }
        }
        return result;
    }
};
