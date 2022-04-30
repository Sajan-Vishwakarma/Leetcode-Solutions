// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends

class Solution{
    public:
    int lenOfLongSubarr(int A[],  int n, int k) { 
        // Complete the function
        map<int,int> mp;
        mp[0] = -1;
        
        int ans = 0;
        long long sum =0;
        for(int i=0;i<n;i++){
            sum += A[i];
            if(sum == k) ans = i+1;
            if( mp.find(sum) == mp.end() ){
                mp[sum] = i;
            }
            
            if(mp.find(sum-k) != mp.end()){
                ans = max(ans, i-mp[sum-k]);
            }
            // cout<<i<<" "<<(sum-k)<<"\n";
            
        }
        return ans;
    } 

};

// { Driver Code Starts.

int main() {
	//code
	
	int t;cin>>t;
	while(t--)
	{
	    int n, k;
	    cin>> n >> k;
	    int a[n];
	    
	    for(int i=0;i<n;i++)
	        cin>>a[i];
	   Solution ob;
	   cout << ob.lenOfLongSubarr(a, n , k)<< endl;
	    
	}
	
	return 0;
}  // } Driver Code Ends