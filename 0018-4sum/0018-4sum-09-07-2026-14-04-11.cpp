class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& v, int x) {
    set < vector < int > > ans;
    int n = v.size();

    sort(v.begin(),v.end());
    for(int i = 0; i < n-3; i++)
    {
        for(int j = i+1; j < n-2; j++)
        {
            for(int k = j+1; k < n-1; k++)
            {
                long long sum = (long long)v[i] + (long long)v[j] + (long long)v[k];
                long long need = (long long)x - sum;
                int l = k + 1;
                int r = n - 1;
                while(l <= r)
                {
                    int mid = (l + r) >> 1;
                    if(v[mid] > need)
                    r = mid - 1;
                    else if(v[mid] < need)
                    l = mid + 1;
                    else
                    {
                        vector < int > faltu = {v[i],v[j],v[k],v[mid]};
                        ans.insert(faltu);
                        break;
                    }
                }
            }
        }
    }
    return vector < vector < int > >(ans.begin(),ans.end());

    }
};