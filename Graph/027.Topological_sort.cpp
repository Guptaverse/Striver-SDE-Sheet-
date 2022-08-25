
void topologicalSortUtil(vector<vector<int>> &adj, vector<bool> &visited, stack<int> &stk, int src) {
    // Mark current vertex visited
    visited[src] = true;  

    // Iterating over adjacent vertices.
    for(int node : adj[src]) {
        if(!visited[node]) {
            topologicalSortUtil(adj, visited, stk, node);
        }
    }
    // Push vertex in stack after pushing all its adjacent (and their adjacent and so on) verices.
    stk.push(src);
}

vector<int> topologicalSort(vector<vector<int>> &edges, int v, int e) {
    // Creating adjacency list.
    vector<vector<int>> adj(v);
    for(int i = 0; i < e; i++) {
        adj[edges[i][0]].push_back(edges[i][1]);
    } 

    vector<bool> visited(v);
    stack<int> stk;

    // Recursively finding topological sorting.
    for(int i = 0; i < v; i++) {
        if(!visited[i]) {
            topologicalSortUtil(adj, visited, stk, i);
        }
    }

    // vector 'result' will keep topological sort of given graph.
    vector<int> result;
    while(!stk.empty()) {
        result.push_back(stk.top());
        stk.pop();
    }

    return result;
}