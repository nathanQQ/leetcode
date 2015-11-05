/*
Given a string containing just the characters '(', ')', '{', '}', '[' and ']', determine if the input string is valid.

The brackets must close in the correct order, "()" and "()[]{}" are all valid but "(]" and "([)]" are not.

Subscribe to see which companies asked this question
*/

class Solution {
public:
    bool isValid(string s) {
        stack<char> stk;
        int size = s.size();
        char top;
        
        string::iterator it;
        for (it = s.begin(); it < s.end(); it++) {
            if (*it == '(' || *it == '[' || *it == '{') {
                stk.push(*it);
            }
            else if (*it == ')' || *it == ']' || *it == '}') {
                if (stk.empty())
                    return false;
                else
                    top = stk.top();
                
                if ((*it == ')' && top != '(') ||
                    (*it == ']' && top != '[') ||
                    (*it == '}' && top != '{'))
                    return false;
                else 
                    stk.pop();
            }      
            else {
                continue;
            }
        }
        return stk.empty()? true:false; 
    }
};