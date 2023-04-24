/*https://practice.geeksforgeeks.org/problems/rotten-oranges2536/1?utm_source=youtube&utm_medium=collab_striver_ytdescription&utm_campaign=rotten_oranges*/

class Solution 
{
    public:
    //Function to find minimum time required to rot all oranges. 
    int orangesRotting(vector<vector<int>>& grid) {
        // Code here
        int n=grid.size();
        int m=grid[0].size();
        queue<pair<pair<int,int>,int>>q;
         int vis[n][m];
         int cntfresh=0;
         for(int i=0;i<n;i++){
             for(int j=0;j<m;j++){
                 if(grid[i][j]==2){
                     q.push({{i,j},0});
                     vis[i][j]=2;
                 }
                 else{
                     vis[i][j]=0;
                 }
                 if(grid[i][j]==1) cntfresh++;
             }
         }
         int tm=0;
         int cnt=0;
          int delrow[4]={-1,0,+1,0};
              int delcol[4]={0,+1,0,-1};
         while(!q.empty()){
             int r=q.front().first.first;
             int c=q.front().first.second;
              int t=q.front().second;
              tm=max(tm,t);
              q.pop();
             
             for(int i=0;i<4;i++){
                 int row=delrow[i]+r;
                 int col=delcol[i]+c;
                 if(row>=0 && row<n && col>=0 && col<m && grid[row][col]==1 && vis[row][col]==0){
                     q.push({{row,col},t+1});
                     vis[row][col]=2;
                     cnt++;
                 }
             }
         
         }
         if(cnt!=cntfresh)
          return -1;
         return tm;
    }
};
