// TC : O(V+E) , SC : O(V+E)

class Solution {
  public:
    // Function to return a list containing the DFS traversal of the graph.
    vector<int> ans;
    vector<int> dfsOfGraph(int V, vector<int> adj[]) {
        // Code here
        vector<bool> visited(V+1, false);
        
        for(int i=0;i<V;i++){
            if(visited[i]==false)
                dfsrec(i, adj, visited);
        }
        return ans;
    }
    
    void dfsrec(int v, vector<int> adj[], vector<bool>& visited){
        visited[v]=true;
        ans.push_back(v);
        for(int u: adj[v]){
            if(visited[u]==false)
                dfsrec(u, adj, visited);
        }
    }
};