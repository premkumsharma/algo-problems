/*
A robot is located at the top-left corner of a m x n grid (marked 'Start' in the diagram below).

The robot can only move either down or right at any point in time. The robot is trying to reach the bottom-right corner of the grid (marked 'Finish' in the diagram below).

Now consider if some obstacles are added to the grids. How many unique paths would there be?
*/

class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        
        int m = obstacleGrid.size();
        int n = obstacleGrid[0].size();
        long grid[m][n];
        memset(grid,0,sizeof(grid));
        
        grid[0][0] = obstacleGrid[0][0] == 0? 1: 0;
        
        for(int i = 1; i< m;i++)
            if(obstacleGrid[i][0] == 0)
                grid[i][0] = grid[i-1][0];
        
        for(int i = 1 ; i< n; i++)
            if(obstacleGrid[0][i] == 0)
                grid[0][i] = grid[0][i-1];
        
        for(int i = 1; i < m; i++)
        {
            for(int j = 1; j < n; j++)
                if(obstacleGrid[i][j] == 0)
                grid[i][j] = grid[i-1][j] + grid[i][j-1];
        }
        
        return grid[m-1][n-1];
    }
};