class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        priority_queue<int>maxh;
        for(int i =0;i<nums.size();i++){
            maxh.push(nums[i]);
            if(maxh.size()>nums.size()-k+1){
                maxh.pop();
            }
        }
        return maxh.top();
    }
};