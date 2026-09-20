class Solution {
public:
    int reverseDegree(string s) {
        int a = 0;
        for (int i = 0; i < s.size(); i++) {
            int value = 'z' - s[i] + 1;
            a += value * (i + 1);
        }
        return a;
    }
};