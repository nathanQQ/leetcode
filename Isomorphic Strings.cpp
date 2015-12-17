/*
Given two strings s and t, determine if they are isomorphic.

Two strings are isomorphic if the characters in s can be replaced to get t.

All occurrences of a character must be replaced with another character while preserving the order of characters. No two characters may map to the same character but a character may map to itself.

For example,
Given "egg", "add", return true.

Given "foo", "bar", return false.

Given "paper", "title", return true.

*/

class Solution {
public:
    bool isIsomorphic(string s, string t) {
        //test result shows unordered_map is 2X faster than map.
        unordered_map<char, char> ht;
        unordered_map<char, char>::iterator it; 
        int size_s = s.size();
        int size_t = t.size();
        int cnt = 0;
        
        if (size_s != size_t)
            return false;
        
        for (; cnt < size_s; cnt++) {
            if (ht.find(s[cnt]) == ht.end()) {
                for (it = ht.begin(); it != ht.end(); it++) {
                    if (it->second == t[cnt]) {
                        return false;
                    }
                }
                ht[s[cnt]] = t[cnt];
            }
            else if (ht[s[cnt]] != t[cnt]) { 
                return false;
            }
        }
        return true;
    }
};