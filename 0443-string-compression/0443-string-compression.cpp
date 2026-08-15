class Solution {
public:
    int compress(vector<char>& chars) {
        int t = 0 ;
        int i = 0;
        while (i < chars.size())
        {
            char current = chars[i];
            int count = 0;
            
            while ( i < chars.size() && chars[i] == current)
            {
                count++;
                i++;
            }
            chars[t]=current;
            t++;
            if (count > 1)
            {
                string s = to_string(count);
                for (char c: s){
                    chars[t] = c;
                    t++;
                }
            }
            
        }
        return t;

    }
};