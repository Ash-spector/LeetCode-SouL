class Solution {
public:

    set<string> multiply(set<string>& a, set<string>& b) {
        set<string> result;

        for (string x : a) {
            for (string y : b) {
                result.insert(x + y);
            }
        }

        return result;
    }

    // Handles expressions like:
    // a{b,c}d
    set<string> parse(string& s, int& i) {

        set<string> result = {""};

        while (i < s.size() && s[i] != '}' && s[i] != ',') {

            set<string> current;

            if (s[i] == '{') {
                i++;  // skip '{'

                current = parseGroup(s, i);

                i++;  // skip '}'
            }
            else {
                current.insert(string(1, s[i]));
                i++;
            }

            result = multiply(result, current);
        }

        return result;
    }

    // Handles everything inside {...}
    // Example: a,b,c
    // or     a,{b,c}
    set<string> parseGroup(string& s, int& i) {

        set<string> result;

        while (true) {

            set<string> current = parse(s, i);

            // UNION
            result.insert(current.begin(), current.end());

            if (s[i] == ',') {
                i++;          // skip ','
                continue;
            }

            // s[i] == '}'
            break;
        }

        return result;
    }

    vector<string> braceExpansionII(string expression) {

        int i = 0;

        set<string> result = parse(expression, i);

        return vector<string>(result.begin(), result.end());
    }
};