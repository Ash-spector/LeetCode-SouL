class Solution {
public:
    vector<int> maxDepthAfterSplit(string seq) {
        vector<int> a;
        int depth = 0;

        for ( char c : seq){
            if( c == '('){
                depth++;
                a.push_back(depth %2);
            }
            else{
                a.push_back(depth % 2);
                depth--;
            }
        }
        return a;
    }
};