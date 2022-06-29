// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
// User function template for C++

// 27 179
// 88 84 3 51 54 99 32 60 76 68 39 12 26 86 94 39 95 70 34 78 67 1 97 2 17 92 52

class Solution{
    public:
    // arr[] : int input array of integers
    // k : the quadruple sum required
    vector<vector<int>> fourSum(vector<int> &arr, int k) {
        // Your code goes here
        int n= arr.size();
        sort(arr.begin(),arr.end());
        vector<vector<int>> ans;
        
        for(int i=0;i<n;i++){
            if (i  && arr[i] == arr[i - 1]) continue;
            for(int j=i+1;j<n;j++){
                if (j > i + 1 && arr[j] == arr[j - 1]) continue;
                
                int l = j+1, r = n-1;
                while(l < r){
                    int sum = arr[i]+arr[j]+arr[l]+arr[r];
                    if( (k) ==  sum){
        
                        vector<int> quad{arr[i],arr[j],arr[l],arr[r]};
                        ans.push_back(quad);
                        
                        int ll = l, rr  =r;
                        while( l < r && arr[l] == arr[ll]){
                            l++;
                        } 
                        while(r > l && arr[r] == arr[rr]){
                            r--;
                        }
                    }
                    else if(  (sum) >  k){
                        r--;
                    }
                    else if(  (sum) <  k){
                        l++;
                    }
                }
            }
        }
        
        return ans;
    }
};

// { Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, k, i;
        cin >> n >> k;
        vector<int> a(n);
        for (i = 0; i < n; i++) {
            cin >> a[i];
        }
        Solution ob;
        vector<vector<int> > ans = ob.fourSum(a, k);
        for (auto &v : ans) {
            for (int &u : v) {
                cout << u << " ";
            }
            cout << "$";
        }
        if (ans.empty()) {
            cout << -1;
        }
        cout << "\n";
    }
    return 0;
}  // } Driver Code Ends