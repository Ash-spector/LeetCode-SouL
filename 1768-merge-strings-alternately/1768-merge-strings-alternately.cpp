#include <algorithm>
class Solution {
public:
    string mergeAlternately(string word1, string word2) {
        std::string res="";
        int n = word1.length();
        int m = word2.length();
        int i =0 ,j = 0 ;
        while (i < n || j < m) {
         if (i < n){
            res+= word1[i++];
         }
         if (j < m )
         {
            res+= word2[j++];
         }

        }

         return res;
        }
    };
       
