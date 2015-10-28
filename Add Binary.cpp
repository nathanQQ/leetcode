/*
Given two binary strings, return their sum (also a binary string).

For example,
a = "11"
b = "1"
Return "100".

Subscribe to see which companies asked this question
*/

class Solution {
public:
    string addBinary(string a, string b) {
        if (a.empty())
            return b;
        if (b.empty())
            return a;
            
        int a_size, b_size, result_size, cnt, carry = 0;
        
        a_size = a.size();
        b_size = b.size();
        result_size = max(a_size, b_size);
        
        string result_s (result_size, '0');
        string tmp_s (abs(a_size - b_size), '0');
        
        if (a_size > b_size) {
            tmp_s.append(b);
        }
        else if (a_size < b_size) {
            tmp_s.append(a);
        }
        else {
            //NOTHING
        }
        
        
        for (cnt = result_size - 1; cnt >= 0; cnt--) {
            if (a_size > b_size) {
                result_s[cnt] = tmp_s[cnt] + a[cnt] - '0' + carry;
            }
            else if (a_size < b_size) {
                result_s[cnt] = tmp_s[cnt] + b[cnt] - '0' + carry;
            }
            else {
                result_s[cnt] = a[cnt] + b[cnt] - '0' + carry;
            }
            if (result_s[cnt] == '2') {
                result_s[cnt] = '0';
                carry = 1;
            } 
            else if (result_s[cnt] == '3') {
                result_s[cnt] = '1';
                carry = 1;
            }
            else
                carry = 0;
            printf("result[%d] = %c\n", cnt, result_s[cnt]);                
        }
        if (carry == 1)
            return "1" + result_s;
        else
            return result_s;
    }
};