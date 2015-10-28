/*
Determine whether an integer is a palindrome. Do this without extra space.
*/

class Solution {
public:
    bool isPalindrome(int x) {
        int left;
        int sum = 0;
        int level = 0;
        int org = x;
        
        if (x < 0)
            return false;
        
        while (x > 9) {
            x /= 10;
            level += 1;
        }
        
        x= org;
        
        while (x) {
            left = x % 10;
            x /= 10;
            sum += left * pow(10, level);
            level -= 1;
        }
        //printf("%d\n", sum);
        if (sum == org)
            return true;
        else
            return false;
            
    }
};