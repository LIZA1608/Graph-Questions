/*https://practice.geeksforgeeks.org/problems/flood-fill-algorithm1856/1?utm_source=youtube&utm_medium=collab_striver_ytdescription&utm_campaign=flood-fill-algorithm*/

class Solution {
public:
void dfs(int row,int col, vector<vector<int>>&ans, vector<vector<int>>image,int newColor,int delrow[],int delcol[],int imcol){
    ans[row][col]=newColor;
    int n=image.size();
    int m=image[0].size();
   for(int i=0;i<4;i++){
      int nrow=row+delrow[i];
      int ncol=col+delcol[i];
      if(nrow>=0 && nrow<n && ncol>=0 && col<m && image[nrow][ncol]== imcol&& ans[nrow][ncol]!=newColor){
          dfs(nrow,ncol,ans,image,newColor,delrow,delcol,imcol);
      }
   }
}
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int newColor) {
        // Code here 
        int incol=image[sr][sc];
         vector<vector<int>>ans= image;
          int delrow[]={-1,0,+1,0};
          int delcol[]={0,+1,0,-1};
         dfs(sr,sc,ans,image,newColor,delrow,delcol,incol);
         return ans;
    }
};
