/*
Implement strStr().

Returns the index of the first occurrence of needle in haystack, or -1 if needle is not part of haystack.
*/

class Solution {
public:
    int strStr(string haystack, string needle) {
        int size1 = haystack.size();
        int size2 = needle.size();
        int cnt1, cnt2 = 0;
        char p, q;
        
        if (size1 < size2)
            return -1;
        
        if (size2 == 0)
            return 0;
            
        for (cnt1 = 0; cnt1 < size1 - size2 + 1; cnt1++) {
            for (cnt2 = 0; cnt2 < size2; cnt2++) {
                p = haystack[cnt1 + cnt2];
                q = needle[cnt2];
                if (p != q)
                    break;
                if (cnt2 == size2 -1)
                    return cnt1;
            }
        }
        return -1;
    }
};