class Solution {
public:
    int numEnclaves(vector<vector<int>>& grid) {
    int n = grid.size();
    int m = grid[0].size();
    queue<pair<int,int>>q;
    vector<vector<int>>visited(n , vector<int>(m,0));
    //put all the boundary land cell into the queue
    for(int i =0;i<n ;i++) 
    {for(int j =0;j<m;j++)
    {if(i==0 || i==n-1 || j==0 || j== m-1)
    {if ( grid[i][j]==1){q.push({i , j});
    visited[i][j]=1;}}} }
    // we have pushed all the boundary nodes into the queue and marked them as visited now look into their neighbors 
    int drow[]={-1,0,1,0};
    int dcol[]={0,1,0,-1};
    while(!q.empty())
    {int r =q.front().first; 
    int c = q .front().second;
    q.pop();
    for(int i =0;i<4;i++)
    {int nrow= r+drow[i];
    int ncol= c+dcol[i];
    if(nrow>=0 && nrow<n && ncol>=0 && ncol<m && grid[nrow][ncol]==1 && visited[nrow][ncol]!=1)
    {q.push({nrow,ncol});
    visited[nrow][ncol]=1;}}}
    int cnt =0;
    for(int i =0;i<n;i++)
    {for(int j =0;j<m;j++)
    {if(grid[i][j]==1 && visited[i][j]!=1)
    {cnt++;}}}
    return cnt ;
    }
};