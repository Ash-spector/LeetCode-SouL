// class Solution {
// public:
//     int majorityElement(vector<int>& nums) {  //compare the different and cancel them out and the rest is remain the maximum count majority 
//         int candy = 0;
//         int count = 0;
//         for (int num : nums) {
//             if (count == 0) {
//                 candy = num;
//             }
//             if (num == candy) {
//                 count++;
//             } else {
//                 count--;
//             }
//         }
//         return candy;
//     }
// };

class Solution {
public:
    int majorityElement(vector<int>& nums) {

        unordered_map<int, int> freq;
        for (int num : nums) {
            freq[num]++;
        }

        for (auto it : freq) {
            if (it.second > nums.size() / 2) {
                return it.first;
            }
        }

        return -1;
    }
};
