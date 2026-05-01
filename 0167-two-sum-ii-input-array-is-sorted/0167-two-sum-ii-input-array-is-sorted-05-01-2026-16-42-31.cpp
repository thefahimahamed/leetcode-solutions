class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) 
    {
        vector < int > v;
        for(int i = 0; i < numbers.size(); i++)
        {
            auto jt = lower_bound(numbers.begin()+i+1,numbers.end(),target - numbers[i]);
            if(jt == numbers.end())
            continue;
            if(*jt + numbers[i] == target)
            {
            
            int j = jt - numbers.begin();
            v.push_back(i+1);
            v.push_back(j+1);
            break;
            }
        }
        return v;
}
};