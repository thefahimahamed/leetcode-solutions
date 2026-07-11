class Solution {
public:
    void calc(vector < int > &height,int i,int l,int mx,stack < pair < int,int > > &s)
{
    pair < int , int > p;
    p.first = l; p.second = i;
    while(!s.empty())
        {
            pair < int ,int > temp = s.top();
            if(height[i] > height[temp.second] && height[l] <= height[temp.first])
                {
                    p.first = temp.first;
                    l = temp.first;
                    s.pop();
                }
            else
                    break;
        }
    s.push(p);
    return;
}

int trap(vector<int>& height) {
        int n = height.size();

        int l;
        for(int i = 1; i < n; i++)
        if(height[i] < height[i-1])
        {
            l = i;
            break;
        }
        int r;
        for(int i = n-1; i >= 1; i--)
        if(height[i] > height[i-1])
        {
            r = i;
            break;
        }
        l = l - 1;
        
        int mx = height[l];
        if(l >= r)
        return 0;
        
        stack < pair < int , int > > s;
        for(int i = l+1; i <= r; i++)
        {
            
            if(mx <= height[i])
            {
                calc(height,i,l,mx,s);
                l = i;
                mx = max(height[i],mx);
            }
            else if(i == r)
            {
                calc(height,i,l,mx,s);
                break;
            }
            else if(height[i] > height[i+1])
            {
                calc(height,i,l,mx,s);
                l = i;
                mx = max(height[i],mx);
            }
            else
            continue;
        }
        int ans = 0;
        while(!s.empty())
        {
            auto it = s.top();
            int mn = min(height[it.first],height[it.second]);
            if(it.second - it.first > 1)
            {
                int total = 0;
                for(int i = it.first+1; i < it.second; i++)
                total += height[i];
                ans += mn*(it.second - it.first - 1) - (total);
            }
            s.pop();
        }
        return ans;
    }
};