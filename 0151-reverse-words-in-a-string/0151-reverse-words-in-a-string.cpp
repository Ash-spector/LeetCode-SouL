class Solution {
public:
    string reverseWords(string s) {
        string word = "";
        vector<string> words;

        for (int i = 0; i < s.length(); i++) {
            if (s[i] != ' ') {
                word += s[i];
            } else {
                if (word != "") {
                    words.push_back(word);
                    word = "";
                }
            }
        }
        if (word != "") {
            words.push_back(word);
        }
        string answer = "";

        for (int i = words.size() - 1; i >= 0; i--) {
            answer += words[i];

            if (i != 0) {
                answer += " ";
            }
        }
        return answer;
    }
};