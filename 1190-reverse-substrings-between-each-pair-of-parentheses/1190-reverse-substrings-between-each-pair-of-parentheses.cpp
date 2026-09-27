class Solution {
public:
    string reverseParentheses(string s) {
        stack<string> st;
        string c = "";

        for (char ch : s) {
            if (ch == '(') {
                st.push(c);
                c = "";
            }
            else if (ch == ')') {
                reverse(c.begin(), c.end());

                c = st.top() + c;
                st.pop();
            }
            else {
                c += ch;
            }
        }

        return c;
    }
};