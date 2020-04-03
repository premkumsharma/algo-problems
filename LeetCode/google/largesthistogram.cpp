
/*
Largest Rectangle in Histogram
Input: [2,1,5,6,2,3]
Output: 10
*/
class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        stack<int> stk;
        
        int stackTop;
        int maxArea = 0;
        int i ;
        for( i = 0; i < heights.size() ; )
        {
            if(stk.empty() || heights[stk.top()] <= heights[i])
                stk.push(i++);
            else
            {
                stackTop = stk.top();
                stk.pop();
                int areaWithTop = heights[stackTop] * (stk.empty() ? i : i - stk.top() - 1);
                maxArea = max(maxArea,areaWithTop);
            }
        
        }
        
        while(!stk.empty())
        {
            stackTop = stk.top();
            stk.pop();
            int areaWithTop = heights[stackTop] *(stk.empty() ? i : i - stk.top() -1);
            maxArea = max(maxArea,areaWithTop);
        }
        return maxArea;
    }
};