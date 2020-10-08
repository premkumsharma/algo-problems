/******************************************************************************

                              Online C++ Compiler.
               Code, Compile, Run and Debug C++ program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/

#include <iostream>
#include<limits.h>
#include<cstring>
using namespace std;
void buildMinSegmentTree(int array[], int segTree[],int low, int high, int pos){
	
	if(low == high){
	segTree[pos] = array[low]; 
	return;
} 

int mid = (high + low)/ 2;

buildMinSegmentTree(array, segTree, low, mid, pos*2 + 1);
buildMinSegmentTree(array, segTree, mid + 1, high, pos*2 + 2);
segTree[pos] = min(segTree[pos*2 + 1], segTree[pos *2 + 2]);
}

int querySegmentTree(int segTree[], int qlow, int qhigh, int low ,int high, int pos){
    
    if(qlow <= low && qhigh >= high)
        return segTree[pos];
    
    if(qlow > high || qhigh < low)
        return INT_MAX;
        
    int mid = (high + low)/2;    
    
    return min(querySegmentTree(segTree, qlow,qhigh, low, mid, pos * 2 + 1), querySegmentTree(segTree,qlow, qhigh, mid + 1,high, 2 * pos+ 2));
}

int main()
{
    int size = 4;
    int array[] = {-1,4,2,0};
    int segTree[size * 4] ;
    memset(segTree, INT_MAX,sizeof(segTree));
    buildMinSegmentTree(array,segTree,0, size -1, 0);
    
    for(int i = 0; i < size * 4; i++)
        cout<<segTree[i]<<" ";
        cout<<endl;
    cout<<querySegmentTree(segTree,0,2,0,size -1, 0)<<endl;
    
    cout<<querySegmentTree(segTree,2,2,0,size -1, 0)<<endl;
    
    cout<<querySegmentTree(segTree,1,1,0,size -1, 0);
    return 0;
}
