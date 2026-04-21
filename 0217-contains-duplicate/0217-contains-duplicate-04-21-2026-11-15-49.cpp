class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        int temp = nums.size();
        set < int > st;
        for(auto it : nums)
        st.insert(it);

        if(st.size() == nums.size())
        return false;
        else
        return true;
    }
};