import java.io.BufferedReader;
import java.io.DataInputStream;
import java.io.IOException;
import java.io.InputStreamReader;

public class Main {
    public static boolean isScoreable(int number)
    {
        return number > 0 && number < 9;
    }
    public static void main(String[] args) throws IOException {
        int test = 0,line = 0,questionNumber,score;

        BufferedReader reader = new BufferedReader(new InputStreamReader(System.in));
        String inputString = reader.readLine();
        if(inputString != null)
            test =Integer.parseInt(inputString);

        while (test > 0)
        {
            inputString = reader.readLine();
            if(inputString != null)
                line = Integer.parseInt(inputString);
            String currentLine = null;
            int []scoreArray = new int[9];

            while(line> 0)
            {
                currentLine = reader.readLine();
                if(currentLine == null) break;
                String [] numbers = currentLine.trim().split("\\s+");
                questionNumber =Integer.parseInt(numbers[0]);
                score = Integer.parseInt(numbers[1]);

                if( isScoreable(questionNumber) && scoreArray[questionNumber] < score)
                    scoreArray[questionNumber] = score;
                --line;
            }
            int scoreSum = 0;
            for(int i = 0; i < scoreArray.length;i++)
                scoreSum += scoreArray[i];
            System.out.println(scoreSum);

            --test;
        }

    }
}
