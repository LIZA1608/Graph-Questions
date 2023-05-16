class Solution {
  public:
  bool dfs(int node,vector<int>adj[],int pathvis[],int vis[]){
      vis[node]=1;
      pathvis[node]=1;
      for(auto it:adj[node]){
          if(!vis[it]){
              if(dfs(it,adj,pathvis,vis)==true){
                  return true;
              }
          }
          else if(pathvis[it]==1){
              return true;
          }
      }
     pathvis[node]=0;
     return false;
  }
    // Function to detect cycle in a directed graph.
    bool isCyclic(int V, vector<int> adj[]) {
        // code here
        int vis[V]={0};
        int pathvis[V]={0};
        for(int i=0;i<V;i++){
            if(!vis[i] ){
                if(dfs(i,adj,pathvis,vis)==true){
                    return true;
                }
            }
        }
        return false;
    }
};
