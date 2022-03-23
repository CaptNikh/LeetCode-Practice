// { Driver Code Starts
//Initial Template for C++

#include<bits/stdc++.h>
#define N 105
using namespace std;
void printArray(vector<int> arr, int size)
{
for (int i=0; i < size; i++)
	cout << arr[i] << " ";
}


 // } Driver Code Ends
//User function Template for C++

struct triplets {
    int r, c, val;
    triplets(int value, int x, int y)
    {
        val = value;
        r = x;
        c = y;
    }
};

struct cmp
{
    bool operator () (triplets &p1, triplets &p2) {
        return p1.val > p2.val;
    }
    
};
class Solution
{
    public:
    //Function to merge k sorted arrays.
    vector<int> mergeKArrays(vector<vector<int>> arr, int K)
    {
        priority_queue<triplets, vector<triplets>, cmp> pq;
        
        for(int i = 0; i < K; i++)
        {
            triplets t(arr[i][0], i, 0);
            pq.push(t);
        }
        
        vector<int> ans;
        
        while(pq.size() > 0)
        {
            triplets p = pq.top();
            pq.pop();
            
            int i = p.r;
            int j = p.c;
            
            ans.push_back(p.val);
            
            if(j + 1 < K){
                triplets t(arr[i][j + 1], i, j + 1);
                pq.push(t);
            }
        }
        
        return ans;
        
    }
};

// { Driver Code Starts.

int main()
{
	int t;
	cin>>t;
	while(t--){
	    int k;
	    cin>>k;
	    vector<vector<int>> arr(k, vector<int> (k, 0));
	    for(int i=0; i<k; i++){
	        for(int j=0; j<k; j++)
	        {
	            cin>>arr[i][j];
	        }
	    }
	    Solution obj;
    	vector<int> output = obj.mergeKArrays(arr, k);
    	printArray(output, k*k);
    	cout<<endl;
    }
	return 0;
}





  // } Driver Code Ends