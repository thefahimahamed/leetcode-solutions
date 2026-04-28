class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
  
        map < int , int > m;
        sort(nums.begin(),nums.end());
        for(auto it : nums)
        m[it]++;
        vector < pair < int , int > > vector_of_pairs(m.begin(),m.end());
        m.clear();
        vector < int > ans;
        sort(vector_of_pairs.begin(),vector_of_pairs.end(),[](auto &a,auto &b) { return a.second > b.second; });
        
        for(auto it : vector_of_pairs)
        {
          if(k == 0)
          break;
          ans.push_back(it.first);
          k--;
        }
      
        return ans;

}
};