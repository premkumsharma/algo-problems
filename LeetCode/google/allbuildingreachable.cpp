/*
Shortest Distance from All Buildings
You want to build a house on an empty land which reaches all buildings in the shortest amount of distance. You can only move up, down, left and right. You are given a 2D grid of values 0, 1 or 2, where:

Each 0 marks an empty land which you can pass by freely.
Each 1 marks a building which you cannot pass through.
Each 2 marks an obstacle which you cannot pass through.
Example:

Input: [[1,0,2,0,1],[0,0,0,0,0],[0,0,1,0,0]]

1 - 0 - 2 - 0 - 1
|   |   |   |   |
0 - 0 - 0 - 0 - 0
|   |   |   |   |
0 - 0 - 1 - 0 - 0

Output: 7 

Explanation: Given three buildings at (0,0), (0,4), (2,2), and an obstacle at (0,2),
             the point (1,2) is an ideal empty land to build a house, as the total 
             travel distance of 3+3+1=7 is minimal. So return 7.
Note:
There will be at least one building. If it is not possible to build such house according to the above rules, return -1.
*/

class Solution {
    
public:
    bool isSafe(vector<vector<int>> &grid, int row, int col){
        return row >= 0 && row < grid.size() && col >=0 && col < grid[0].size() && grid[row][col] == 0; 
    }
    void bfs(vector<vector<int>> &grid, int row, int col,vector<vector<int>>& distance, vector<vector<int>> &reach){
        
        int rows = grid.size();
        int cols = grid[0].size();
        bool visited[rows][cols];
        memset(visited,false,sizeof(visited));
        
        //direction left top right bottom 
        pair<int,int> directions[] = {{0,-1},{-1,0},{0,1,},{1,0}};
  
        queue<pair<int,int>> q;
        q.push({row,col});
        
        int d = 0;
        
        while(!q.empty()){
            d++;
            
            int size = q.size();
            for(int i = 0; i< size; i++){
            
                pair<int,int> pos = q.front();
                q.pop();
            
                // traverse through all direction
                for(auto dir : directions){

                    // get new row and column number
                    int r = pos.first + dir.first;
                    int c = pos.second + dir.second;

                    // check if it safe to go to new location 
                    if((isSafe(grid,r,c) && visited[r][c] == false)) {
                        //put new row col into queue
                        q.push({r,c});
                        // add current distance to the distance for the row and col as this is distance taken from building to empty spot
                        distance[r][c] += d;
                        // also now this row and col is reachable from one more building so increase building count
                        reach[r][c]++;
                        // mark current spot as visited
                        visited[r][c] = true;
                
                    }

                    }
        }
        
        }
        
        
    }
    int shortestDistance(vector<vector<int>>& grid) {
     if(grid.size() == 0) return -1;
        int rows = grid.size();
        int cols = grid[0].size();
        vector<vector<int>> distance(rows, vector<int>(cols)), reach(rows, vector<int>(cols));
        
        // travrese though the matrix one by one if matrix contains 1 means building then do bfs from that point and calculate distance to all empty place in matrix
        int totalBuildings = 0;
        for(int i = 0; i < rows;i++){
            for(int j = 0; j < cols; j++){
                if(grid[i][j] == 1){
                    bfs(grid,i,j,distance,reach);
                    // while traversing also keep counting total building
                    totalBuildings++;
                }
            }
        }
        int minDistance = INT_MAX;
        for(int i = 0; i < rows;i++){
            for(int j = 0; j < cols; j++){
                // now for each empty space check if empty space was reachable from all building and distance taken from all building is less than previous distance
                if(reach[i][j] == totalBuildings && distance[i][j] < minDistance){
                    minDistance = distance[i][j];
                }
            }
        }
        // if mindistance is still INT_MAX mean there was not any empty space which was reachable from building.
        return minDistance == INT_MAX ? -1 : minDistance;
        
    }
};