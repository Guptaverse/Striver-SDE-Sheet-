// TC : O(V+E) , SC : O(V+E)

class Solution {
  public:
    vector<int> bfsOfGraph(int V, vector<int> adj[]) {
       // Code here
       vector<int> v;
       vector<int> vis(V,0);
       queue<int> q;
       q.push(0);
       while(q.size()>0){
           int val=q.front();
           q.pop();
           if(vis[val]==1){
               continue;
           }
           vis[val]=1;
           v.push_back(val);
            for(auto it:adj[val]){
               if(vis[it]==0){
                   q.push(it);
               }
           }
       }
       return v;
   }
};







