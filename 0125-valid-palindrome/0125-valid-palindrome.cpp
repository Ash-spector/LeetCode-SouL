class Solution {
public:
    bool isPalindrome(string s) {
        string remove = "";
        for (char c : s)
        {
            if(isalnum(c))//(alnum) its is c builtin function that checks whether a character is aplhanumric a-z; A-Z 0-9 
            {
                remove += tolower(c);
            }
        }
        string rev = remove;
        reverse(rev.begin(), rev.end());
        return remove == rev;
    }
};