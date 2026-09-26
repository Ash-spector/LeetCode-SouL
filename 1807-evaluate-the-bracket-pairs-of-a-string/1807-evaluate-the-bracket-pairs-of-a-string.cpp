class Solution {
public:
    string evaluate(string s, vector<vector<string>>& knowledge) {
        map<string, string> mp;
        for (auto x : knowledge) {
            mp[x[0]] = x[1];
        }
        string a;

        for (int i = 0; i < s.size(); i++) {
            if (s[i] == '(') {
                string key = "";
                i++; 

                while (s[i] != ')') {
                    key += s[i];
                    i++;
                }

                if (mp.find(key) != mp.end()) {
                    a+= mp[key];
                }
                else {
                    a += '?';
                }

            }
            else {
                a += s[i];
            }
        }
        return a;
    }
};