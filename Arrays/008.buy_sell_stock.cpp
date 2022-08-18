// optimized : TC : O(N), SC: O(1)

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int mini = prices[0];
        int ans = 0;
        int i =0;
        for(auto x:prices){
            if(x<mini && i) mini = x;
            else if(x-mini>=0 && i) ans = max(ans,x-mini);
            i++;
        }
        return ans;
    }
};