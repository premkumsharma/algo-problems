/*You are climbing a stair case. It takes n steps to reach to the top.
Each time you can either climb 1 or 2 steps. In how many distinct ways can you climb to the top?
Note: Given n will be a positive integer.
Example 1:

Input: 2
Output: 2
Explanation: There are two ways to climb to the top.
1. 1 step + 1 step
2. 2 steps
Example 2:

Input: 3
Output: 3
Explanation: There are three ways to climb to the top.
1. 1 step + 1 step + 1 step
2. 1 step + 2 steps
3. 2 steps + 1 step
*/

class Solution {
public:
     int climbStairsRec(int n)
     {
          if(n < 0) return 0;
        if(n == 0) return 1;
        
        return climbStairsRec(n-1) + climbStairsRec(n-2);
     }
    int climbStairsDynmic(int n) {
       
        int steps[n+1];
        steps[0] = 1, steps[1] = 1;
        
        for(int i = 2; i <= n ; i++ )
        {
            steps[i] = steps[i-1] + steps[i-2];
        }
        
        return steps[n];
    }
	int climbStairs(int n) {
        if(n <=0) return 0;
        if(n == 1) return 1;
        int way1 = 1;
        int way2 = 2,currentway;
        for(int i = 3; i<= n ;i++)
        {
            currentway = way1 + way2;
            way1 = way2;
            way2 = currentway;
        }
        
        return way2;
        
    }
};