/*
Given a non-negative number represented as an array of digits, plus one to the number.

The digits are stored such that the most significant digit is at the head of the list.
*/

class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        vector<int> result;
        stack<int> stk;
        int size = digits.size();
        int i, left;
        char ch;
        unsigned long sum = 0;
        
        for (i = 0; i < size; i++) {
            sum += (digits[size - 1 - i]) * pow(10, i);
        }
        sum += 1; //plus one
        printf("%d\n", sum);
        while (sum) {
            left = sum % 10;
            sum /= 10;
            stk.push(left);
        }
        
        size = stk.size();
        
        for (i = 0; i < size; i++) {
            ch = stk.top();
            result.push_back(ch);
            stk.pop();
        }

        return result;
    }
};