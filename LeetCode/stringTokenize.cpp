vector<string> split(char *str, const char * del){
    vector<string> result;
    if(str == NULL) return result;
    char *token = strtok(str, del); 
    while (token != NULL) 
    {
        result.push_back(token);
        token = strtok(NULL, del); 
    }
}