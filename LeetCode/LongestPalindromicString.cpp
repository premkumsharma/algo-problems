class Solution {
public:
    string longestPalindrome(string s) {
      
        int n = s.length();
        if(n == 0) return "";
        bool palindromeTable[n][n] ={false};
        
        int maxLength = 1;
        int startIndex = 0;
        for(int i = 0 ;i < n;i++)
            palindromeTable[i][i] = true;
        
        for(int i = 1;i<n;i++)
            if(s[i] == s[i-1])
            {
                palindromeTable[i-1][i] = true;
                maxLength = 2;
                startIndex = i - 1 ;
            }
        
        for(int k =3 ; k <= n;k++ )
        {
            for(int i = 0 ; i< n-k+1;i++)
            {
                int j = i + k -1;
                
                if(palindromeTable[i+1][j-1] && s[i] == s[j])
                {
                    palindromeTable[i][j] = true;
                    if(maxLength <= k) 
                    {
                        maxLength = k;
                        startIndex = i;
                    }
                }
            }
            
        }
        
        return s.substr(startIndex,maxLength);
    }
};