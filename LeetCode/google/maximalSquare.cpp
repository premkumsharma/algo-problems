class Solution {
public:
    int maximalSquare(vector<vector<char>>& matrix) {
        int rows = matrix.size();
        if(rows == 0) return 0;
        int cols = matrix[0].size();
        if(cols == 0) return 0;
        int maxSquare[rows][cols];
        int maxSize = 0;
        memset(maxSquare, 0, sizeof(maxSquare));
        for(int i = 0; i< rows; i++)
        {
            for(int j = 0; j < cols; j++)
            {
                if(i ==0 ||j ==0)
                    maxSquare[i][j] = matrix[i][j] == '1'? 1 : 0;
                else if(matrix[i][j] =='1')
                {
                    maxSquare[i][j] = min(min(maxSquare[i-1][j], maxSquare[i][j-1]), maxSquare[i-1][j-1]) + 1;
                }
                
                if(maxSize < maxSquare[i][j])
                    maxSize = maxSquare[i][j];
            }
        }
        return maxSize * maxSize;
                }




};