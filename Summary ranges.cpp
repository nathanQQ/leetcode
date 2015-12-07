/*
Given a sorted integer array without duplicates, return the summary of its ranges.

For example, given [0,1,2,4,5,7], return ["0->2","4->5","7"].

Credits:
Special thanks to @jianchao.li.fighter for adding this problem and creating all test cases.
*/

class Solution {
public:
    vector<string> summaryRanges(vector<int>& nums) {
        vector<string> ret;
        string s;
        unsigned int size = nums.size();
        int cnt = 0, prv, cur;
        bool need_array = false;
        
        if (size == 0) {
            return ret;
        }
        
        prv = nums[0];
        s = to_string(prv);

        if (size == 1) {
            ret.push_back(s);
            return ret;
        }
        
        for (cnt = 1 ; cnt < size; cnt++) {
            cur = nums[cnt];
            if (cur != prv + 1) {
                //push prv to array
                if (need_array)
                    s += "->" + to_string(prv);
                ret.push_back(s);
                s = to_string(cur);
                need_array = false;
            }
            else {
                //continue counting
                need_array = true;
            }
            prv = cur;
        }
        //deal with the last one
        ret.push_back(need_array? s + "->" + to_string(prv) : to_string(prv));
        
        return ret;
    }
};