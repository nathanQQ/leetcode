/*
Given two strings s and t, write a function to determine if t is an anagram of s.

For example,
s = "anagram", t = "nagaram", return true.
s = "rat", t = "car", return false.

Note:
You may assume the string contains only lowercase alphabets.
*/

class Solution {
public:
    bool isAnagram(string s, string t) {
        vector<int> array(26, 0);
        int size = s.size();
        int tmp;
        
        if (s.size() != t.size())
            return false;
            
        for (tmp = 0; tmp < size; tmp++) {
            array[s[tmp] - 'a']++;
        }
        
        for (tmp = 0; tmp < size; tmp++) {
            if (--array[t[tmp] - 'a'] < 0)
                return false;
        }
        return true;

    }
};