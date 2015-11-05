/*
Given a non-negative number represented as an array of digits, plus one to the number.

The digits are stored such that the most significant digit is at the head of the list.
*/

class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        vector<int>::iterator itr;
        int carry = 0;
        int sum = 0;
        int plus_one = 1;
        
        for (itr = digits.end() - 1; itr >= digits.begin(); itr--) {
            sum = *itr + carry + plus_one;
            
            if (sum > 9) {
                *itr = sum - 10;
                carry = 1;
                plus_one = 0;
                continue;
            }
            else {
                *itr = sum;
                return digits;
            }
        }
        //reach here means overflow.
        digits.insert(digits.begin(), 1);
        return digits;
    }
};