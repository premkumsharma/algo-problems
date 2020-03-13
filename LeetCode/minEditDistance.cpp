/*
  Given two words word1 and word2, find the minimum number of operations required to convert word1 to word2.
You have the following 3 operations permitted on a word:

Insert a character
Delete a character
Replace a character
Example 1:

Input: word1 = "horse", word2 = "ros"
Output: 3
Explanation: 
horse -> rorse (replace 'h' with 'r')
rorse -> rose (remove 'r')
rose -> ros (remove 'e')
*/

class Solution {
public:
    int minDistanceRec(string word1, string word2, int m, int n)
    {
        if(m == 0) return n;
	if(n == 0) return m;
	
	if(word1[m-1] == word2[n-1])
		return minDistanceUtil(word1,word2, m -1 , n-1);
	return 1 + min(
		minDistanceUtil(word1,word2, m,n-1), //Insert
		min(minDistanceUtil(word1,word2, m - 1, n), // Remove 
		minDistanceUtil(word1,word2, m-1 , n-1))); // Replace        
    }
    int minDistanceUtil(string word1, string word2, int m ,int n)
    {   
		int distance[m+1][n+1];
	
		for(int i = 0; i <= m ; i++)
		{	
			for(int j = 0; j <= n; j++)
			{
				if(i ==0)
				distance[i][j] = j;
				else if(j ==0)
				distance[i][j] = i;
				else if(word1[i-1] == word2[j-1])
				distance[i][j] = distance[i-1][j-1];
					else
				distance[i][j] = min(distance[i][j-1], min(distance[i-1][j], distance[i-1][j-1])) + 1;
			}
		}
	return distance[m][n];

    }
    int minDistance(string word1, string word2) {
        return minDistanceUtil(word1, word2,word1.length(),word2.length());
    }
};