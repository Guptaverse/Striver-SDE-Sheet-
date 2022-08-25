bool checkcycle(vector<int> adj[],vector<bool>&vis,int sv,int n){
    vis[sv]= true;
    queue<pair<int,int>>q;
    q.push({sv,-1});
    while(!q.empty()){
        auto it = q.front();
        int curr= it.first;
        int par = it.second;
        q.pop();
        for(auto child:adj[curr]){
            if(!vis[child]){
                vis[child]= true;
                q.push({child,curr});
            }
            else if(child!=par) return true; 
        }
    }
    return false;
}
// Function to detect cycle in an undirected graph.
bool isCycle(int n, vector<int> adj[]) {
    // Code here
    vector<bool>vis(n+1,0);
    for(int i = 1;i<=n;i++){
        if(!vis[i]){
            if(checkcycle(adj,vis,i,n)) return true;
        }
    }
    return false;
}