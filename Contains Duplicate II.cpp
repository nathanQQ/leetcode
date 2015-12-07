/*
Given an array of integers and an integer k, find out whether there are two distinct indices i and j in the array such that 
nums[i] = nums[j] and the difference between i and j is at most k.
*/

class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        int size = nums.size();
        int cnt, tmp;
        
        if (size < 2)
            return false;
            
        if (k <= 0)
            return false;
        
        map<int, int> ht;
        
        for (cnt = 0; cnt < size; cnt++) {
            if (ht.find(nums[cnt]) == ht.end()) {
               //new number, put it in the hash table
               ht[nums[cnt]] = cnt;
            }
            else {
                //found it! Check the distance.
                if (cnt - ht[nums[cnt]] <= k) 
                    return true;
                else
                    ht[nums[cnt]] = cnt;
            }
        }

        return false;
    }
};