/*
Campus Bikes

*/




class HeapNode
{
    public :
    int bikeIndex;
    int workerIndex;
    int distance;
    
    HeapNode(int bindex,int wIndex,int dist){
        bikeIndex = bindex;
        workerIndex = wIndex;
        distance = dist;
    }
};

class heapCompare 
{ 
public: 
    int operator() (const HeapNode& p1, const HeapNode& p2) 
    { 
        if(p1.distance == p2.distance){
            if(p1.bikeIndex == p2.bikeIndex){
                return p1.workerIndex > p2.workerIndex;
            }
            else return p1.bikeIndex > p2.bikeIndex;
        }
        else 
            return p1.distance > p2.distance; 
    } 
};

class Solution {
public:

    
    int getDistance(vector<int> &worker, vector<int> &bike){
        
        return abs(worker[0] - bike[0]) + abs(worker[1] - bike[1]);
    }
    vector<int> assignBikes(vector<vector<int>>& workers, vector<vector<int>>& bikes) {
        set<int> bikesAvailed;
        set<int> workerDone;
        priority_queue<HeapNode, vector<HeapNode>, heapCompare> minHeap;
        for(int i = 0; i< workers.size(); i++){
            for(int j = 0; j < bikes.size(); j++){
                int distance = getDistance(workers[i], bikes[j]);
                HeapNode node(j,i,distance);
                minHeap.push(node);
            }
        }
        vector<int> result(workers.size());
        while(!minHeap.empty())
        {
            HeapNode temp = minHeap.top();
            minHeap.pop();
            
            if(bikesAvailed.find(temp.bikeIndex) == bikesAvailed.end() && workerDone.find(temp.workerIndex) == workerDone.end()){
             result[temp.workerIndex]= temp.bikeIndex;   
                
            bikesAvailed.insert(temp.bikeIndex);
            workerDone.insert(temp.workerIndex);
            }
            
        }
        return result;
    }
};