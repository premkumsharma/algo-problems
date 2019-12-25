import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;

public class LeadGame {
	
	public static void main(String[] args) throws IOException {
		 BufferedReader reader = new BufferedReader(
				    new InputStreamReader(System.in));
			int n = 0;
			String line = reader.readLine();
			if(line == null) return;
		    n = Integer.parseInt(line);
		    int playerOneScore = 0, playerTwoScore = 0;
		    int player = -1,maxDiff = 0;
		    
		    while(n > 0)
		    {
		    	line = reader.readLine();
		    	if(line == null) break;
		    	String []inputs = line.trim().split("\\s+");
		    	
		    	playerOneScore += Integer.parseInt(inputs[0]);
		    	playerTwoScore += Integer.parseInt(inputs[1]);
		    	
		    	if(Math.abs(playerOneScore - playerTwoScore) > maxDiff)
		    	{
		    		player = playerOneScore > playerTwoScore ? 1 : 2;
		    		maxDiff = Math.abs(playerOneScore - playerTwoScore); 
		    	}
		    	--n;
		    }
		    System.out.println(player + " " +maxDiff);
	}

}
