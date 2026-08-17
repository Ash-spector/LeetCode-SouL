class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        //make a unordered map
        unordered_map<int, int >count;
        vector<vector<int>>buckets(nums.size() +1); // create bucket acc on frequency 
        for (int num : nums)
        {
            count[num]++;
        }
        for(auto& [num, freq] : count)
        {
            buckets[freq].push_back(num);
        }
        vector<int> result;
      for (int i = buckets.size() -1 ; i>=1; i--)
      {
        for(int num : buckets[i])
        {result.push_back(num);
        
        if(result.size() == k){
            return result;
        }
        
      }
    }
    return result;
    }
};