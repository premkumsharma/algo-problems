/*
Given an m x n matrix of non-negative integers representing the height of each unit cell in a continent, the "Pacific ocean" touches the left and top edges of the matrix and the "Atlantic ocean" touches the right and bottom edges.

Water can only flow in four directions (up, down, left, or right) from a cell to another one with height equal or lower.

Find the list of grid coordinates where water can flow to both the Pacific and Atlantic ocean.

Note:

The order of returned grid coordinates does not matter.
Both m and n are less than 150.
 

Example:

Given the following 5x5 matrix:

  Pacific ~   ~   ~   ~   ~ 
       ~  1   2   2   3  (5) *
       ~  3   2   3  (4) (4) *
       ~  2   4  (5)  3   1  *
       ~ (6) (7)  1   4   5  *
       ~ (5)  1   1   2   4  *
          *   *   *   *   * Atlantic

Return:

[[0, 4], [1, 3], [1, 4], [2, 2], [3, 0], [3, 1], [4, 0]] (positions with parentheses in above matrix).
*/

typedef pair<int,int> iPair;
class Solution {
public:
    bool isSafe(vector<vector<int>> &grid, int row, int col, int parent){
        // if indexes are safe and next row col contains greater or equal value then it is safe
        return row >= 0 && row < grid.size() && col >=0 && col < grid[0].size() && grid[row][col] >= parent; 
    }
    
    void bfs(vector<vector<int>> &matrix,vector<vector<bool>> &ocean, int row, int col){
        
        bool visited[matrix.size()][matrix[0].size()];
        memset(visited,false,sizeof(visited));
        
        queue<iPair> q;
        iPair directions[] = {{0,-1},{-1,0},{0,1},{1,0}};
  
        q.push({row,col});
        visited[row][col] = true;
        
        while(!q.empty())
        {
             iPair current = q.front();
            q.pop();
            
            for(auto dir : directions){

                    // get new row and column number
                    int r = current.first + dir.first;
                    int c = current.second + dir.second;

                    // check if it safe to go to new location 
                    if((isSafe(matrix,r,c, matrix[current.first][current.second]) && visited[r][c] == false && ocean[r][c] == false)) {
                        //put new row col into queue
                        q.push({r,c});
                        //make ocean to true that is reachable from the ocean
                        ocean[r][c] = true;
                        // mark current spot as visited
                        visited[r][c] = true;
                
                    }

        }
            
    }
    }
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& matrix) {
        vector<vector<int>> result;
        if(matrix.size() == 0) return result;
        int rows = matrix.size();
        int cols = matrix[0].size();
        vector<vector<bool>> pacific(rows, vector<bool>(cols)) ;        
        vector<vector<bool>> atlantic(rows, vector<bool>(cols)) ;
        
        for(int i = 0; i < rows; i++){
            // first column column belong to pacific so make pacific true
            pacific[i][0] =true;
            // last column belongs to atlantic so make atalantic true
            atlantic[i][cols-1] =true;
            // start bfs from first and last column for pacific and atalantic
            bfs(matrix,pacific,i,0);
            bfs(matrix,atlantic,i,cols -1);
        }
        
        
        for(int j = 0; j < cols; j++){
            // first row column belong to pacific so make pacific true            
            pacific[0][j] =true;
            // last row belongs to atlantic so make atalantic true            
            atlantic[rows-1][j] =true;
            // start bfs from first and last column for pacific and atalantic
            
            bfs(matrix,pacific,0,j);
            bfs(matrix,atlantic,rows -1, j);
        }
        
            // After bfs check both boolean matrix where both matrix is set true add row and col in resultset
       
        for(int i = 0 ; i < rows; i++){
            for(int j = 0; j < cols; j++){
                
                if(pacific[i][j] == true && atlantic[i][j] == true)
                    result.push_back({i,j});
                    
            }
        }
        return result;
    }
};