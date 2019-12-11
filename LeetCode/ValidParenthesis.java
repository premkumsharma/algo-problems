class Solution {
    
    
    public boolean isValid(String s) {
        
    
        Stack<Character> stack = new Stack<Character>();
        
        for(int i = 0; i < s.length();i++)
        {
            char currentChar = s.charAt(i);
            if(currentChar == '(' || currentChar == '{' || currentChar == '[')
                stack.push(currentChar);
            else 
            {
                if(stack.isEmpty()) return false;
               char lastChar = stack.pop();
                if((currentChar == ')' && lastChar != '(' ) || 
                  (currentChar == '}' && lastChar != '{' ) ||
                  (currentChar == ']' && lastChar != '[' ))
                    return false;
            }
        }
        if(!stack.isEmpty()) return false;
        return true;
    }
}