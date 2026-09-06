class Solution {
public:
    int numDistinct(string s, string t) {
        int a = t.size();
        vector<unsigned long long > dp(a+1,0);

        dp[0] = 1;
        for(char c : s)
        {
            for (int i = a; i >=1; --i)
            {
                if(c == t[i -1]) 
                {
                    dp[i]+= dp[i-1];
                }
            }
        }
        return dp[a];
    }
};