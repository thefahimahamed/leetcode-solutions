class Solution {
public:
    int carFleet(int target, vector<int>& position, vector<int>& speed) {
       
       vector < pair < int , int > > v;
       for(int i = 0; i < position.size(); i++)
       v.push_back({position[i],speed[i]});
       sort(v.begin(),v.end());
       stack < double > fleet;
       for(int i = position.size()-1; i >= 0; i--)
       {
        double current = (double)(target - v[i].first)/v[i].second;
        if(fleet.empty())
        fleet.push(current);
        else if(current > fleet.top())
        fleet.push(current);
        else
        continue;
       }
       return fleet.size();
    }
};