// Optimized : TC : O(N*N) , SC : O(N*N)

class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> ans;
        vector<int> first(1,1);
        ans.push_back(first);
        for(int i = 1;i<numRows;i++){
            vector<int> this_level(i+1,1);
            for(int j = 1;j<i;j++){
                this_level[j] = ans[i-1][j-1] + ans[i-1][j];
            }
            ans.push_back(this_level);
        }
        return ans;
    }
};