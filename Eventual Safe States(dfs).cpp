class Solution {
  public:
 bool dfs(int node,int vis[],int path[],vector<int>adj[],int check[]){
      vis[node]=1;
      path[node]=1;
      check[node]=0;
      for(auto it:adj[node]){
          if(!vis[it]){
              if(dfs(it,vis,path,adj,check)==true){
                  return true;
              }
          }
          else if(path[it]==1){
              return true;
          }
      }
      check[node]=1;
      path[node]=0;
      return false; 
  }
    vector<int> eventualSafeNodes(int V, vector<int> adj[]) {
        // code here
        int vis[V]={0};
        int path[V]={0};
        int check[V]={0};
        vector<int>safenode;
        for(int i=0;i<V;i++){
            if(!vis[i]){
                dfs(i,vis,path,adj,check);
        }
        }
        for(int i=0;i<V;i++){
            if(check[i]==1){
                safenode.push_back(i);
            }
        }
        return safenode;
    }
};
