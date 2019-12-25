package CodeChef;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.Collections;
import java.util.PriorityQueue;

public class EndOfCorrupt {

	public static void main(String[] args) throws IOException {
	
		BufferedReader reader = new BufferedReader(
			    new InputStreamReader(System.in));
		int n = 0, m =0 ,num =0;
		String line = reader.readLine();
		if(line == null) return;
    	String []inputs = line.trim().split("\\s+");
    	n = Integer.parseInt(inputs[0]);
    	m = Integer.parseInt(inputs[1]);
	    PriorityQueue<Integer> maxHeap = new PriorityQueue<>(Collections.reverseOrder());
	    
	    while(n + m > 0)
	    {
	    	line = reader.readLine();
		    if(line == null) break ;
		    num = Integer.parseInt(line);
		    
		    if(num > 0)
		    {
		    	maxHeap.add(num);
		    	n--;
		    }
		    else
		    {
		    	System.out.println(maxHeap.poll());
		    	m--;
		    }
	    	
	    }
	    
	
	}

}
