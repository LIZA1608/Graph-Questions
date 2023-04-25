/*https://practice.geeksforgeeks.org/problems/detect-cycle-in-an-undirected-graph/1?utm_source=youtube&utm_medium=collab_striver_ytdescription&utm_campaign=detect-cycle-in-an-undirected-graph*/

class Solution {
  public:
  bool detect(int src,vector<int>adj[],int vis[]){
     vis[src]=1;
     queue<pair<int,int>>q;
     q.push({src,-1});
     while(!q.empty()){
         int node=q.front().first;
         int pa=q.front().second;
         q.pop();
         
         for(auto it:adj[node]){
             if(!vis[it]){
                 vis[it]=1;
                 q.push({it,node});
             }
             else if(pa!=it){
                 return true;
             }
         }
     }
     return false;
  }
    // Function to detect cycle in an undirected graph.
    bool isCycle(int V, vector<int> adj[]) {
        // Code here
        int vis[V]={0};
        for(int i=0;i<V;i++){
            if(!vis[i]){
                if(detect(i,adj,vis)){
                    return true;
                }
            }
        }
        return false;
    }
};
