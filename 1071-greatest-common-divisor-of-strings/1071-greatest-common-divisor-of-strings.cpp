class Solution {
public:
    string gcdOfStrings(string str1, string str2) {
        // Check if a common "divisor" string can even exist
        if (str1 + str2 != str2 + str1) {
            return "";
        }
        int gcdLen = gcd((int)str1.size(), (int)str2.size());
        return str1.substr(0, gcdLen);
    }
};