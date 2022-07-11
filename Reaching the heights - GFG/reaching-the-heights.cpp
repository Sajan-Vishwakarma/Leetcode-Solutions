// { Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


vector<int> reaching_height(int n, int a[]) ;

int main() {
	int t;
	cin >> t;
	while (t-- > 0) {
	    int n; 
	    cin >> n;
	    int a[n];
	    for (int i = 0; i < n; i++) 
	        cin >> a[i];
	    vector<int> v;
	    v = reaching_height(n,a);
	
	    if(v.size()==1 and v[0] == -1){
	        cout << "Not Possible\n";
	    }
	    else{
	    for(int i:v)
	        cout << i << " ";
	    cout << endl;}
	    
	}
	return 0;
}// } Driver Code Ends


//User function Template for C++

vector<int> reaching_height(int n, int a[]) {
    // Complete the function
    sort(a,a+n);
    
    vector<int> ans(n);
    int i= 0, j = n-1;
    for(int k=0;k<n;k++){
        if(k%2){
            ans[k] = a[i++];
        }
        else
            ans[k] = a[j--];
    }
    int cur = 0;
    for(int k=0;k<n;k++){
        if(k%2) cur -= ans[k];
        else cur += ans[k];
        if( cur <= 0) return {-1};
    }
    return ans;
}
