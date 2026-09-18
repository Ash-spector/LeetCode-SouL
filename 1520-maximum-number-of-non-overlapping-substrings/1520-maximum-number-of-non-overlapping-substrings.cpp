class Solution {
public:
    vector<string> maxNumOfSubstrings(string s) {
        int n = s.size();
        // First and last occurrence of every character
        vector<int> first(26, n);
        vector<int> last(26, -1);

        for (int i = 0; i < n; i++) {
            int c = s[i] - 'a';
            first[c] = min(first[c], i);
            last[c] = i;
        }
        vector<pair<int, int>> intervals;
        // Try to create a valid substring starting
        // from the first occurrence of each character
        for (int c = 0; c < 26; c++) {
            if (last[c] == -1)
                continue;
            int l = first[c];
            int r = last[c];
            bool valid = true;
            for (int i = l; i <= r; i++) {
                int x = s[i] - 'a';
                // This character appeared before l,
                // so we cannot make a valid substring starting at l.
                if (first[x] < l) {
                    valid = false;
                    break;
                }
                // Expand the interval to include
                // all occurrences of this character.
                r = max(r, last[x]);
            }
            if (valid) {
                intervals.push_back({l, r});
            }
        }
        sort(intervals.begin(), intervals.end(),   // Choose maximum number of non-overlapping intervals.
        // Sort by ending position.
             [](const pair<int, int>& a, const pair<int, int>& b) {
                 return a.second < b.second;
             });
        vector<string> ans;
        int prevEnd = -1;
        for (auto [l, r] : intervals) {
            if (l > prevEnd) {
                ans.push_back(s.substr(l, r - l + 1));
                prevEnd = r;
            }
        }

        return ans;
    }
};