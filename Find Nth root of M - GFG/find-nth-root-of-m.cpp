// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution{
	public:

	int NthRoot(int n, int m){
	    // Code here.
	    
	   // long long low=1,high=m;
	   // while(high>=low){
	   //     long long mid=(low+high)/2;
	   //     int val = pow(mid,n);
	        
	   //     cout<<mid<<" "<<val<<endl;
	        
	   //     if(val==m){
	   //         return mid;
	   //     }
	   //     else if(val>m){
	   //         high=mid-1;
	   //     }
	   //     else{
	   //         low=mid+1;
	   //     }
	   // }
	   // return -1;
	   long int a=0;
	    long int ele=0;
	    while(ele<=m){
	        ele=pow(a,n);
	        if(ele==m){
	            return a;
	        }
	        a++;
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