package FirstPackage;

import java.io.BufferedReader;
import java.io.InputStreamReader;

public class MaxLengthPalindrome {

	public static void main(String[] args) throws Exception {
		{
		    BufferedReader reader = new BufferedReader(
				    new InputStreamReader(System.in));
				    
		    int n =Integer.parseInt(reader.readLine());
		    String text = reader.readLine();
		    n = text.length();
		    int start = 0, maxLength = 1;
		    for(int i = 1 ; i < n - 1 ; i++)
		    {
		        int low = i - 1; 
		        int high = i;
		        
		        while(low >= 0 && high < n && text.charAt(low) == text.charAt(high))
		        {
		            if(high - low + 1 > maxLength)
		            {
		                maxLength = high - low + 1;
		                start = low;
		            }
		            low--;
		            high++;
		        }
		        
		        low = i - 1;
		        high = i + 1;
		        
		        while(low >= 0 && high < n && text.charAt(low) == text.charAt(high))
		        {
		            if(high - low + 1 > maxLength)
		            {
		                maxLength = high - low + 1;
		                start = low;
		            }
		            low--;
		            high++;
		        }
		        
		    }
		    
		    System.out.println(maxLength);
		    System.out.println(text.substring(start,start + maxLength));
				
				reader.close();

		}
	}

}
