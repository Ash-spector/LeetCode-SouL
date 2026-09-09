class Solution {
public:
    long long countCommas(long long n) {
        long long a = 0;
        for (long long x = 1000; x<=n; x *= 1000){
            a += n-x+1;
        }
        return a;
    }
};