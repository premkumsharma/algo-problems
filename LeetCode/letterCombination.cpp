class Solution {
public:
    vector<string> letterCombinationsRec(string digits,int index,map<char,string> &keyMap, vector<string> &result,char currentString[]) {
    
        if(index == digits.length())
        {
            string str(currentString);
            result.push_back(str);
            return result;
        }
        string keyString = keyMap[digits[index]];
        
        for(int i = 0; i < keyString.length(); i++)
        {
            currentString[index] = keyString[i];
            letterCombinationsRec(digits,index + 1,keyMap,result,currentString);
        }
        return result;
       
    }
    vector<string> getLetterCombinationUtil(string digits, map<char,string> &keyMap)
{
	queue<string> q;
	q.push("");
	vector<string> result;
	while(!q.empty())
	{
		string currString = q.front();
		q.pop();
		if(currString.length() == digits.length() && currString.length() > 0)
{
	result.push_back(currString);
}
		else
		for(auto letter : keyMap[digits[currString.length()]])
			q.push(currString + letter);
}
return result;
}

    vector<string> letterCombinations(string digits) {
        map<char,string> keyMap;
        keyMap.insert(pair<char,string>('0',""));
        keyMap.insert(pair<char,string>('1',""));
        keyMap.insert(pair<char,string>('2',"abc"));
        keyMap.insert(pair<char,string>('3',"def"));
        keyMap.insert(pair<char,string>('4',"ghi"));
        keyMap.insert(pair<char,string>('5',"jkl"));
        keyMap.insert(pair<char,string>('6',"mno"));
        keyMap.insert(pair<char,string>('7',"pqrs"));
        keyMap.insert(pair<char,string>('8',"tuv"));
        keyMap.insert(pair<char,string>('9',"wxyz"));
        vector<string> result;
        char output[digits.length()+1];
        output[digits.length()] = NULL;
        return getLetterCombinationUtil(digits,keyMap);
    }
};