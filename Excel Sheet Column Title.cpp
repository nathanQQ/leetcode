/*
Given a positive integer, return its corresponding column title as appear in an Excel sheet.

For example:

    1 -> A
    2 -> B
    3 -> C
    ...
    26 -> Z
    27 -> AA
    28 -> AB 
*/

class Solution {
public:
    string convertToTitle(int n) {
        string s;
        int left;
        
        while (n) {
            left = n % 26;
            n /= 26;
            //Need to handle special numbers like 26, 52 ...
            if (left == 0) {
                n -= 1;
                left = 26;
            }
            s.push_back(left + 'A' - 1);
        }
        //reverse string.
        std::reverse(s.begin(), s.end());
        return s;
    }
};