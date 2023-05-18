class Solution {
  public:
    vector<int> eventualSafeNodes(int V, vector<int> adj[]) {
        // code here
    vector<int>adjrev[V];
    for(int i=0;i<V;i++){
        for(auto it:adj[i]){
            adjrev[it].push_back(i);
        }
    }
        int indegree[V]={0};
        for(int i=0;i<V;i++){
            for(auto it:adjrev[i]){
                indegree[it]++;
            }
        }
        queue<int>q;
        for(int i=0;i<V;i++){
            if(indegree[i]==0){
                q.push(i);
            }
        }
        vector<int>topo;
        while(!q.empty()){
            int node=q.front();
            q.pop();
            topo.push_back(node);
            for(auto it:adjrev[node]){
                indegree[it]--;
                if(indegree[it]==0){
                    q.push(it);
                }
            }
        }
        sort(topo.begin(),topo.end());
            return topo;
    }
        
    
};
