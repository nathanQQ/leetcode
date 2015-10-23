/*
Given a column title as appear in an Excel sheet, return its corresponding column number.

For example:

    A -> 1
    B -> 2
    C -> 3
    ...
    Z -> 26
    AA -> 27
    AB -> 28 
*/

class Solution {
public:
    int titleToNumber(string s) {
        int lens = s.size();
        int i, sum = 0;
        
        //valid the input string
        
        for (i = 0; i < lens; i++) {
            sum += (s[lens - 1 - i] - 'A' + 1) * pow(26, i);
        }
        return sum;
    }
};    