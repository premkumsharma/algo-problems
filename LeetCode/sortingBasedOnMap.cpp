class Solution {
public:
    vector<int> relativeSortArray(vector<int>& arr1, vector<int>& arr2) {
        unordered_map<int,int> m;
        vector<pair<int,int>> result(arr1.size());
        for(int i = 0; i< arr2.size(); i++){
            if(m.find(arr2[i]) == m.end())
            m[arr2[i]] = i;
        }
        
        vector<int> finalResult(arr1.begin(), arr1.end());
    

        sort(finalResult.begin(), finalResult.end(), [&m](const int a, const int b){
            int aIndex = INT_MAX, bIndex = INT_MAX;
            if(m.find(a) != m.end())
                aIndex = m[a];
            if(m.find(b) != m.end())
               bIndex = m[b];
            
            return aIndex < bIndex ||( aIndex == bIndex && a < b);
           
            
            });
          

        return finalResult;
        
    }
};