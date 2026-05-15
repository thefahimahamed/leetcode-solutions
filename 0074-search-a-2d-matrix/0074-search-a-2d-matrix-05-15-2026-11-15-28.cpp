class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int row = matrix.size()-1;
        int left = 0;
        int right = matrix.size()-1;
        while(left <= right)
        {
            int mid = left + (right - left) / 2;
            if(matrix[mid][0] > target)
            right = mid - 1;
            else if(matrix[mid][0] == target)
            return true;
            else
            {
                row = mid;
                left = mid + 1;
            }
        }
        left = 0;
        right = matrix[row].size()-1;
        while(left <= right)
        {
            int mid = left + (right - left) / 2;
            if(matrix[row][mid] > target)
            right = mid - 1;
            else if(matrix[row][mid] == target)
            return true;
            else
            left = mid + 1;
        }
        return false;
    }
};