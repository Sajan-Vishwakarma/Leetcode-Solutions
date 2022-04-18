// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution{
	public:
	long long Power(long long num, unsigned pow){
        long long res;
        for(res = 1; pow; pow >>= 1){
            if (pow & 1)
            res = (res * num);
            num = (num * num);
        }
        return res;
    }

	int NthRoot(int n, int m){
	    // Code here.
	    
	    long long low=1,high=m;
	    while(high>=low){
	        long long mid=(low+high)/2;
	        if(pow(mid,n)==m){
	            return mid;
	        }
	        else if(pow(mid,n)>m){
	            high=mid-1;
	        }
	        else{
	            low=mid+1;
	        }
	    }
	    return -1;
	    
	}  
};

// { Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n, m;
		cin >> n >> m;
		Solution ob;
		int ans = ob.NthRoot(n, m);
		cout << ans << "\n";
	}  
	return 0;
}  // } Driver Code Ends