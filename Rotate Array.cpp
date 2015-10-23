/*
Rotate an array of n elements to the right by k steps.

For example, with n = 7 and k = 3, the array [1,2,3,4,5,6,7] is rotated to [5,6,7,1,2,3,4].

Note:
Try to come up as many solutions as you can, there are at least 3 different ways to solve this problem.
*/

class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        int size = nums.size();
        int tmp, tmp_h, idx, idx_next, idx_init, cnt;
        
        if (size <= 0 || k <= 0)
            return;
        if ((k = k % size) == 0)
            return;
            
        tmp = nums[0];
        idx_init = 0;
        
        for (cnt = 0, idx = 0; cnt < size; cnt++) {
            idx_next = (idx + k) % size; 
            tmp_h = nums[idx_next]; //hold the value to be placed
            nums[idx_next] = tmp; //replace
            tmp = tmp_h;
            idx = idx_next;
            if (idx == idx_init) {
                tmp = nums[++idx];
                idx_init = idx;
            }
        }
        
    }
};