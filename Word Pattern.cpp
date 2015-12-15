/*
Given a pattern and a string str, find if str follows the same pattern.

Here follow means a full match, such that there is a bijection between a letter in pattern and a non-empty word in str.

Examples:
pattern = "abba", str = "dog cat cat dog" should return true.
pattern = "abba", str = "dog cat cat fish" should return false.
pattern = "aaaa", str = "dog cat cat dog" should return false.
pattern = "abba", str = "dog dog dog dog" should return false.
Notes:
You may assume pattern contains only lowercase letters, and str contains lowercase letters separated by a single space.
*/

class Solution {
public:
    bool wordPattern(string pattern, string str) {
        map<char, string> hash;
        //break str
        istringstream str_split(str);
        string s;
        int size = pattern.size();
        int cnt = 0;
        char ch;
        
        for (; str_split >> s; cnt++) {
            //str is bigger than pattern string
            if (cnt == size) {
                return false;
            }
            ch = pattern[cnt];
            //not in hash table KEY
            if (hash.find(ch) == hash.end()) {
                //the VALUE is already associated with other KEY, should return false
                for (map<char, string>::iterator it = hash.begin(); it != hash.end(); it++ ) {
                    if (it->second == s) {
                        return false;
                    }
                }
                hash[ch] = s;
            }
            else if (s != hash[ch]) {
                return false;
            }
        }
        // in case str is empty. for loop won't be running
        // in case pattern string is longer than str
        if (cnt == size)
            return true;
        else
            return false;
    }
};