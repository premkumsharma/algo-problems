#include<iostream>
#include<vector>
using namespace std;
bool isValidToDistribute(vector<int> &A,long long int k,long long int mid)
{
    long long int numberOfStudents = 1,currentPages = 0;
    
    for(int i = 0; i< A.size();i++)
    {
        if(currentPages + A[i] > mid)
        {
            currentPages = A[i];
            numberOfStudents++;
            if(numberOfStudents > k) return false;
        }
        else
        currentPages+= A[i];
    }
    return true;
    
}
int allocateBooks(vector<int> &A, int B) {
    
    if(A.size() < B) return -1;
    long long int sum,high,low,mid;
    sum =  high = 0;
    low = A[0];
    for(int i = 0; i< A.size();i++)
    {
        sum+=A[i];
        low = max((int)low,A[i]);
    }
    high =  sum;
    bool isValidFound = false;
    long long int maxPage = A[0]; 
    while(low <= high)
    {
        mid = low + (high-low)/2;
        if(isValidToDistribute(A,B,mid))
        {
            maxPage = mid;
            high = mid -1;
            isValidFound = true;
        }
        else
        low = mid+1;
    }
    if(isValidFound) return maxPage ;else return -1;
    
}
int main()
{
	vector<int> pages{10,20,30,40};
	int s = 2;
	cout<<allocateBooks(pages,s);
}
