/*
Given an integer n, return the number of trailing zeroes in n!.

Note: Your solution should be in logarithmic time complexity.
*/

/*
find the number of prime factor - 5 (eg: 5, 10, 15, 20 ect).
numbers such 25, 50, 75, 100, 125 has more 5s.
*/

class Solution {
public:
    int trailingZeroes(int n) {
        int nr_five = 0;
        int x = 5;
        
        if (n <= 0)
            return 0;
        
        while (n / x) {
            nr_five += n / x;
            x *= 5; 
        }
        return nr_five;
    }
};