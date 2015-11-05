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
            int num = 0;  
            int sign =1;  
            int len = str.size();  
            int i = 0;  
            
            while (str[i] == ' ' && i < len) 
                i++;
                
            if (str[i] == '+') 
                i++;
            else if (str[i] == '-') {
                sign = -1; 
                i++;
            }
            
            for (; i < len; i++) {  
                 if (str[i] == ' ') 
                    break;  
                 if (str[i] < '0' || str[i] > '9') 
                    break;  
                 if ((INT_MAX / 10 < num) || 
                    (INT_MAX / 10 == num && INT_MAX % 10 < (str[i] -'0'))) {  
                      return sign == -1 ? INT_MIN : INT_MAX;  
                      break;  
                 }  
                 num = num * 10 + str[i] -'0';  
            }  
            return num * sign;  
       }  
};