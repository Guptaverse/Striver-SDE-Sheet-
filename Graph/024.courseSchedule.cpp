class Solution {
public:
    bool isCyclic(vector<int>adj[],int node,vector<bool>&visited, vector<bool>& dfsVisited){
        visited[node]=true;
        dfsVisited[node]=true;
        for(auto it: adj[node]){
            if(!visited[it]) {
                if(isCyclic(adj,it,visited,dfsVisited)) return true;
            }
            else if(dfsVisited[it]) return true;
        }
        dfsVisited[node]=false;
        return false;
    }
       
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
       vector<int>adj[numCourses];
        for(int i=0;i<prerequisites.size();i++){ //creating adjacency list
            adj[prerequisites[i][1]].push_back(prerequisites[i][0]);
        }
        vector<bool> visited(numCourses,false);
        vector<bool> dfsVisited(numCourses,false);
        for(int i=0; i<numCourses; i++){
            if(!visited[i] && isCyclic(adj,i,visited,dfsVisited) ) return false; //if graph is cyclic i.e. all courses cannot be finished
        }
        return true;
    }
};
