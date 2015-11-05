/*
Implement atoi to convert a string to an integer.

Hint: Carefully consider all possible input cases. If you want a challenge, please do not see below and ask yourself what are the possible input cases.

Notes: It is intended for this problem to be specified vaguely (ie, no given input specs). You are responsible to gather all the input requirements up front.

Update (2015-02-10):
The signature of the C++ function had been updated. If you still see your function signature accepts a const char * argument, please click the reload button  to reset your code definition.

spoilers alert... click to show requirements for atoi.

Subscribe to see which companies asked this question
*/

class Solution {
public:
    int myAtoi(string str) {
        int size = str.size();
        int sum = 0, cnt;
        bool is_minus = false;
        int limit = pow(2, 31);
        
        if (size == 0)
            return 0;
        
        
        for (cnt = 0; cnt < size; cnt++) {
            if (str[cnt] < '0' || str[cnt] > '9') {
                if (str[cnt] == '-') {
                    if (cnt == 0) {
                        is_minus = true;
                        continue;
                    }
                    else {
                        sum /= pow(10, size - cnt);
                        break;
                    }
                }
                else if (str[cnt] == '+') {
                    if (cnt == 0) {
                        continue;
                    }
                    else {
                        sum /= pow(10, size - cnt);
                        break;
                    }
                }
                else if (str[cnt] == ' ')
                    continue;
                //not a valid string
                else {
                    sum /= pow(10, size - cnt);
                    break;
                }
            }
            sum += (str[cnt] - '0') * pow(10, size - 1 - cnt);
            if (sum < 0) {
                sum = limit - 1;
                break;
            }
        }
        if (is_minus)
            return -sum;
        else
            return sum;
    }
};