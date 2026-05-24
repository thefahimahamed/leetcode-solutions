class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int one = 0;
        int two = 0;
        vector < int > total;
        // auto new_end = unique(nums1.begin(), nums1.end());
        // nums1.erase(new_end, nums1.end());
        // new_end = unique(nums2.begin(), nums2.end());
        // nums2.erase(new_end, nums2.end());
        while(one < nums1.size() && two < nums2.size())
        {
            if(nums1[one] < nums2[two])
            {
                total.push_back(nums1[one]);
                one++;
            }
            else if(nums1[one] > nums2[two])
            {
                total.push_back(nums2[two]);
                two++;
            }
            else
            {
                total.push_back(nums2[two]);
                total.push_back(nums2[two]);
                one++;
                two++;
            }
        }
        if(one == nums1.size() && two < nums2.size())
        total.insert(total.end(), nums2.begin()+two, nums2.end());
        if(two == nums2.size() && one < nums1.size())
        total.insert(total.end(), nums1.begin()+one, nums1.end());
        
        if(total.size() & 1)
        {
          int index = (total.size() + 1)/2;
          double value = total[index-1];
          return value;
        }
        else
        {
          int index = total.size()/2;
          double sum = (total[index] + total[index-1])*1.0;
          sum /= 2.0;
          return sum;
        }
        
    }
};