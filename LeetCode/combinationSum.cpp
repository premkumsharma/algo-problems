

/*
Find all possible combinations of k numbers that add up to a number n, given that only numbers from 1 to 9 can be used and each combination should be a unique set of numbers.

Note:

All numbers will be positive integers.
The solution set must not contain duplicate combinations.
*/
class Solution {
public:
    vector<vector<int>> combinationSum3(int k, int n) {
        vector<int> path;
        combinationSum(1, n, k, path);
        return result;
    }
private:
    void combinationSum(int index, int target, int k, vector<int> &path) {
        if (target == 0) {
            if (path.size() == k)
                result.push_back(path);
            return;
        }
        if (target <= 0 || index == 10 || path.size() == k)
            return;
        
        path.push_back(index);
        combinationSum(index+1, target-index, k, path);
        path.pop_back();
        combinationSum(index+1, target, k, path);          
        
    }
    vector<vector<int>>result;
};

class Solution {
public:
     void combineUtil(vector<vector<int>> &resultSet, vector<int> &result, int index,int n, int k ,int target)
{
         if(target < 0) return;
        if(result.size() == k && target == 0)
        {
            resultSet.push_back(result);
            return;
        }
        while(index <= 9)
        {	
            result.push_back(index);
            
            combineUtil(resultSet,result,index+1,n,k,target-index);
            index++;
            result.pop_back();
        }	
}
    vector<vector<int>> combinationSum3(int k, int n) {
        
        vector<vector<int>> resultSet;
        vector<int> result;
        if(n == 0|| k == 0) return resultSet;
        combineUtil(resultSet,result,1,n,k,n);
        return resultSet;
    }
};