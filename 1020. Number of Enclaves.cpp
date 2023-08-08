
class Solution {
public:
    int numEnclaves(vector<vector<int>>& grid) {
        queue<pair<int,int>>q;
        int n = grid.size();
        int m = grid[0].size();
        long long vis[n][m];
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                vis[i][j]=0;
            }
        }
 for(int i=0;i<n;i++){
     for(int j=0;j<m;j++){
         if(i==0 || j==0 || i==n-1 || j==m-1){
             if(grid[i][j]==1){
                 q.push({i,j});
                 vis[i][j]=1;
             }
         }
     }
 }
 int delrow[]={-1,0,1,0};
 int delcol[]={0,1,0,-1};
 while(!q.empty()){
     int row= q.front().first;
     int col=q.front().second;
     q.pop();
     for(int i=0;i<4;i++){
         int newrow=row+delrow[i];
         int newcol=col+delcol[i];
         if(newrow>=0 && newrow<n && newcol>=0 && newcol<m && vis[newrow][newcol]==0 && grid[newrow][newcol]==1){
             q.push({newrow,newcol});
             vis[newrow][newcol]=1;
         }
     }
 }
 int count=0;
 for(int i=0;i<n;i++){
     for(int j=0;j<m;j++){
         if(grid[i][j]==1 && vis[i][j]==0){
             count++;
         }
     }
 }
 return count;
    }
};
