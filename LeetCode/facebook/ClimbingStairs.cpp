class Solution {
public:
    bool static cmp(const pair<char,int> p1, const pair<char,int> p2)
{
    return p1.second > p2.second;
}
    int leastInterval(vector<char>& tasks, int n) {
        
        priority_queue<pair<int,char>> mh, temp;
        map<char,int> m;
        
        for(char task : tasks)
            m[task]++;
        int i = 0;
        for(auto itr = m.begin(); itr != m.end();itr++)
            mh.push(make_pair(itr->second,itr->first));
        

        int counter = 0;
        while(!mh.empty())
        {
            int interValTime = n+1, index = 0;
            while(interValTime > 0)
            {
                if(!mh.empty())
                {
                    pair<int,char> item = mh.top();
                    mh.pop();
                    item.first--;
                    if(item.first > 0) temp.push(item);
                }
                counter++;
                interValTime--;
                if(mh.empty() && temp.empty()) break;
            }
            while(!temp.empty())
            {
                mh.push(temp.top());
                temp.pop();
            }
        }
           return counter;
            
    }
};