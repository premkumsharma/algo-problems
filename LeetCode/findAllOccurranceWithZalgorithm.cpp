
#include <iostream>
#include<limits.h>
#include<cstring>
using namespace std;
int* calcuateZ(string text){
	int *z = new int[text.length()];
	int left, right ;
	left = right = 0;
    for(int i = 1; i < text.length(); i++){
    	if(i > right)
        {
            left = right = i;
        	while(right < text.length() && text[right] == text[right -left])
        		right++;
        	z[i] = right - left;
        	right--;
        }
    else
        {
        	int k = i - left;
        	if(z[k]  < right - i + 1)
        		z[i] = z[k];
            else
            {
            	left = i;
            	while(right < text.length() && text[right] == text[right - left])
            		right++;
            	z[i] = right - left;
            	right--;
            } 
}

}
return z;
}

int * findAllOcurrance(string text, string pattern)
{
    int n = text.length() + 1 + pattern.length();
    int *z = calcuateZ(pattern + "$" + text );
    
    cout<<endl;
     for(int i = 0; i < n ;i++)
    {
        if(z[i] == pattern.length())
        cout<<i - pattern.length() - 1 <<endl;
    }
        
}

int main()
{
     string str ="abdabcefabcde";
    string pat ="abc";
    
    findAllOcurrance(str, pat);
    
    return 0;
}
