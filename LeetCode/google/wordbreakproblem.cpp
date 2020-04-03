class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        int wordLen = s.size();
        bool wb[wordLen +1];
        memset(wb,false,sizeof(wb));
        set<string> dict;
        
        for(string str : wordDict)
            dict.insert(str);
        
        for(int i = 1; i <= wordLen; i++)
        {
            if(wb[i] == false && dict.find(s.substr(0,i)) != dict.end())
                wb[i] = true;
            
            if(wb[i] == true)
            {
                if(i == wordLen) return true;
                for(int j = i + 1; j<= wordLen; j++)
                {
                    if(wb[j] == false && dict.find(s.substr(i,j - i)) != dict.end())
                        wb[j] = true;
                    if(j == wordLen && wb[j] == true)
                        return true;
                } 
                    
            }
           }
         return false;
        
        
    }
};