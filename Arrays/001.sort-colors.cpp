# brute force Time complexity :  N^2
class Solution {
public:
    void sortColors(vector<int>& nums) {
        int n = nums.size();
        
        for(int i = 0 ;i<n;i++){
            for(int j = i+1 ;j<n;j++){
                if(nums[j]<nums[i]){
                    swap(nums[i],nums[j]);
                }
                // cout<<"nums[i]: "<<nums[i] << "  nums[j] : "<<nums[j]<<endl;
            }
        }
        
    }
};

# Optimized : Dutch National flag Algorithm O(N)

class Solution {
public: 
    void sortColors(vector<int>& nums){
        int n = nums.size();
        int low = 0,mid =0 ,high = n-1;
        
        while(mid<=high){
            if(nums[mid]==0){
                swap(nums[mid],nums[low]);
                mid++,low++;
            }
            else if(nums[mid]==1){
                mid++;
            }
            else if(nums[mid]==2){
                swap(nums[mid],nums[high]);
                high--;
            }
        }
    }
};