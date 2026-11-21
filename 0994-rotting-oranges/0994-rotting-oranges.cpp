class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
    int n = grid.size();
    int m = grid[0].size();
    queue<pair<pair<int,int>,int>>q;
    //instead of a visited vector we make a visited array this time
    vector<vector<int>>visited(n,vector<int>(m,0));
    //we initialised all its elements to 0
    //we would put the first set of rotten oranges at time t=0 into the queue and then pop it and then put all the rotten neighbors into the queue
    for(int i =0;i<n;i++)    
    {for(int j=0;j<m;j++)
    {if(grid[i][j]==2&&visited[i][j]!=2)
    {q.push({{i,j},0});
    visited[i][j]=2;}}}
    int drow[]={-1,0,1,0};
    int dcol[]={0,1,0,-1};
    int tm =0;
    while(!q.empty())
    {int r =q.front().first.first;
    int c=q.front().first.second;
    int t=q.front().second;
    q.pop();
    //popped the first element now look into the neighbors
    tm=max(tm,t);
    for(int i =0;i<4;i++)
    {int nrow=r+drow[i];
    int ncol=c+dcol[i];
    //for every nrow and ncolumn check if it has any fresh oranges
    if(nrow>=0 && nrow<n && ncol>=0 && ncol<m && grid[nrow][ncol]==1 && visited[nrow][ncol]!=2)
    {q.push({{nrow,ncol},t+1});
    visited[nrow][ncol]=2;}}
    
    }
    //to check in the entire matrix at the end if you have any fresh oranges left 
    for(int i =0;i<n;i++)
    {for(int j=0;j<m;j++)
    {if(grid[i][j]==1 && visited[i][j]!=2)
    {return -1;}}}
    return tm;}
};