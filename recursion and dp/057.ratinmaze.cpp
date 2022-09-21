class Solution{
    public:
    void findAllPaths(int cr,int cc,int n,vector<vector<int>>&grid,vector<string>&ans,string curr){
      if(cr==n-1 and cc==n-1){
          ans.push_back(curr);
          return;
      }
      
      if(cr<0 or cc<0 or cr>n-1 or cc>n-1 or grid[cr][cc] != 1){
          return;
      }
      
      grid[cr][cc]=0; // now change the value to 0 so that we will not come to this cordinate again repetatively
      
       if(cr-1>=0 and grid[cr-1][cc]==1){
       //move up
        curr.push_back('U');
        findAllPaths(cr-1,cc,n,grid,ans,curr);
        curr.pop_back();
       }
       
       if(cc+1<=n-1 and grid[cr][cc+1]==1){
       //move right
       curr.push_back('R');
       findAllPaths(cr,cc+1,n,grid,ans,curr);
       curr.pop_back();
       }
       
       if(cr+1<=n-1 and grid[cr+1][cc]==1){
       //move down
       curr.push_back('D');
       findAllPaths(cr+1,cc,n,grid,ans,curr);
       curr.pop_back();
       }
     
      if(cc-1>=0 and grid[cr][cc-1]==1){
        //move left
       curr.push_back('L');    
       findAllPaths(cr,cc-1,n,grid,ans,curr);
       curr.pop_back();
       }
      
      grid[cr][cc]=1; // change the value to back as previous so this can be taken in any other paths
      
    }
    vector<string> findPath(vector<vector<int>> &grid, int n) {
        vector<string>ans;
        string curr="";
        findAllPaths(0,0,n,grid,ans,curr);
        sort(ans.begin(),ans.end());
        return ans;
    }
};