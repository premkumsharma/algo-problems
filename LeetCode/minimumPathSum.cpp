/*
Given a m x n grid filled with non-negative numbers, find a path from top left to bottom right which minimizes the sum of all numbers along its path.
Note: You can only move either down or right at any point in time.
Example:

Input:
[
  [1,3,1],
  [1,5,1],
  [4,2,1]
]
Output: 7
Explanation: Because the path 1→3→1→1→1 minimizes the sum.
*/

class Solution {
public:
    int minPathSumUtilRec(vector<vector<int>> grid,int m ,int n)
    {
               
        if(m == 0 && n == 0) return grid[m][n];
        
        if(m < 0 || n < 0) return INT_MAX;
        
        return min(minPathSumUtilRec(grid,m-1,n),minPathSumUtilRec(grid,m,n-1)) + grid[m][n];
    }
    
    int minPathSumUtil(vector<vector<int>> grid,int m ,int n)
    {
        int pathCost[m][n];
        memset(pathCost,0,sizeof(pathCost));
        
        pathCost[0][0] = grid[0][0];
        
        for(int i = 1; i< m ;i++)
            pathCost[i][0] = pathCost[i-1][0] +grid[i][0];
        
        for(int j = 1; j < n; j++)
            pathCost[0][j] =pathCost[0][j-1] + grid[0][j];
        
        for(int i = 1; i < m ;i++)
        {
            for(int j = 1; j < n; j++)
                pathCost[i][j] = min(pathCost[i-1][j] , pathCost[i][j-1]) + grid[i][j];
        }
        
        return pathCost[m-1][n-1];
    }
    int minPathSum(vector<vector<int>>& grid) {
 
        return minPathSumUtil(grid,grid.size(), grid[0].size());
    }
};