// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution{
    public:
    void segregateElements(int v[],int n){
        // Your code goes here
        vector<int> pos, neg;
        for(int i=0;i<n;i++){
            if(v[i] >= 0)
                pos.push_back(v[i]);
            else
                neg.push_back(v[i]);
        }
        pos.insert(pos.end(),neg.begin(), neg.end());
        
        for(int i=0;i<n;i++){
            v[i] = pos[i];
        }
    }
};

// { Driver Code Starts.
int main() {
	// your code goes here
	int t;
	cin>>t;
	while(t--)
	{
		int n;
		cin>>n;
		int a[n];
		for(int i=0;i<n;i++)
		cin>>a[i];
		Solution ob;
		ob.segregateElements(a,n);
		
        for(int i=0;i<n;i++)
        cout<<a[i]<<" ";
		cout<<endl;
	}
}
  // } Driver Code Ends