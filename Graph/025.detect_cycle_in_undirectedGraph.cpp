bool dfs(vector<vector<int>>&g,vector<bool>& vis,int sv, int par)
{
    vis[sv] = true;
    for (int child : g[sv]){
        if (vis[child] == false){
            if (dfs(g,vis,child,sv)){
                return true;
            }
        }
        else if (child != par)
        {
            return true;
        }
    }
    return false;
}

string cycleDetection(vector<vector<int>>& edges, int n, int m){
    vector<bool> vis(n+1,false);
    vector<vector<int>>g(n+1,vector<int>());
    for (int i=0; i<m; i++){
        g[edges[i][1]].push_back(edges[i][0]);
        g[edges[i][0]].push_back(edges[i][1]);
    }

    for (int i = 1; i <= n; i++){
        if (vis[i] == false){
            if (dfs(g,vis,i,-1)){
                return "Yes";
            }
        }
    }
    return "No";
}