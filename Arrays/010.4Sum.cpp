// Optimized : TC : O(N^3) , SC : O(1)
// nested two pointer with 2 nested loops

#define ll long long
class Solution {        
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {   
       
       int n = nums.size();
       vector<vector<int>> ans;   
       if(n<4) return ans;     // check 
       sort(nums.begin(),nums.end());
    
       for(int i=0;i<n-3;i++){              // loop 1        
           if(i>0 && nums[i]==nums[i-1]) continue;     // avoid duplicates
           for(int j = i+1;j<n-2 ;j++){       // loop 2
               if(j>i+1 && nums[j]==nums[j-1])continue;    // avoid duplicate
               int l=j+1;       // 2 pointer from j+1 to n-1
               int r=n-1;
               ll sum=nums[i]+nums[j];  // to avoid overflow
               while(l<r){    
                   ll temp =sum+ (ll)nums[l]+(ll) nums[r]; // to avoid overflow
                   if(temp == (ll)target){    
                       ans.push_back({nums[i],nums[j],nums[l],nums[r]});
                       while(l<r && nums[l]==nums[l+1]) l++;  // to avoid duplicates
                       while(l<r && nums[r]==nums[r-1]) r--;  // to avoid duplicates
                       l++;
                       r--;
                   }
                   else if(sum+nums[l]+nums[r]<target){   // if sum < target increase lower limit
                       l++;
                   }
                   else{                                  // else decrease upper limit
                       r--; 
                   }
               }
           }
       }
        return ans;
    }
};