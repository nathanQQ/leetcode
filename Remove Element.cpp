/*
Given an array and a value, remove all instances of that value in place and return the new length.

The order of elements can be changed. It doesn't matter what you leave beyond the new length.
*/

class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        int size = nums.size();
        int i, cur = 0;
        
        for (i = 0; i < size; i++ ) {
            if (nums[i] == val) {
                continue;
            }
            nums[cur] = nums[i];
            cur++;
        }
        return cur;
    }
};