/*
Write a function to find the longest common prefix string amongst an array of strings.
*/

class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        string cmn;
        
        if (!strs.size())
            return cmn;
            
        int str_idx = 0, vect_idx;
        char tmp;
        int max_size = strs[0].size();
        
        for (vect_idx = 0; vect_idx < strs.size(); vect_idx++) {
            if (strs[vect_idx].size() < max_size)
                max_size = strs[vect_idx].size();
        }
        
        
        for (str_idx = 0; str_idx < max_size; str_idx++) {
            for (vect_idx = 0, tmp = strs[0][str_idx]; vect_idx < strs.size(); vect_idx++) {
                if (strs[vect_idx][str_idx] != tmp)
                    goto done;
            }
            cmn += tmp;
        }
    done:
        return cmn;
    }
};