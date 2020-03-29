class Solution {
public:
    
    int minCostUtil(vector<vector<int>> &cost, int houseNumber,int color)
    {
        
        if(houseNumber == cost.size()) return 0;
        if(color < 0 || color > 2) return INT_MAX;
        
        int minCost = min(minCostUtil(cost,houseNumber + 1, color + 1),minCostUtil(cost,houseNumber + 1, color - 1));
        
        return minCost != INT_MAX ? cost[houseNumber][color] + minCost : minCost;
                                              
        
    }
    
    int minCost(vector<vector<int>>& costs) {
     
        int minPaintCost = INT_MAX; 
        for(int color = 0 ; color < 3; color++)
            minPaintCost = min(minPaintCost, minCostUtil(costs,0,color));
        
        return minPaintCost;
    }
};