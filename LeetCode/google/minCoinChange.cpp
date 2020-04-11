#include<cstring>
class Solution {
    int minCoin;
public:
    int coinChangeUtil(vector<int>& coins,int totalSum,int countArray[])
    {
        if(totalSum == 0) 
            return 0;
        if(totalSum < 0) 
            return -1;
        
        if(countArray[totalSum] != 0) return countArray[totalSum];
        
        int minCoins = INT_MAX;
        for(int coin : coins)
        {
            int result = coinChangeUtil(coins, totalSum - coin,countArray);
            if(result >= 0 && result < minCoins)
                minCoins = result + 1;
        }
        countArray[totalSum] = (minCoins == INT_MAX ? -1 : minCoins);
            return countArray[totalSum];
    }
    int coinChange(vector<int>& coins, int amount) {
        if(amount <= 0) return 0;
        int countArray[amount+1];
        memset(countArray,0,sizeof(countArray));
        return coinChangeUtil(coins, amount, countArray );
        
    }
};