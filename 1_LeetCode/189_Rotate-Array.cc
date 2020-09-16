/*
  2020/09/16
*/

class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        
        int n = (int)nums.size();
        
        k = k % n;
        
        reverse(nums.begin(),nums.end());
        reverse(nums.begin(),nums.begin()+k);
        reverse(nums.begin()+k, nums.end());
    }
};
