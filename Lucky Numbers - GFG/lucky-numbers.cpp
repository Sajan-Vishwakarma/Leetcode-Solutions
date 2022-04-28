// { Driver Code Starts
//Initial Template for C++


#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
//User-function template for C++

// Complete the function
// n: Input n
// Return True if the given number is a lucky number else return False

bool called = false;
vector<int> board;

class Solution{
public:
    Solution(){
        if(called)
            return;
            
        int n = 100000;
        vector<int> v(n);
        for(int i=0;i<n;i++){
            v[i] = i+1;
        }

        for(int step = 1;step <= 1000; step++){
        	vector<int> newv;
        	for(int i=step;i<v.size(); i += (step+1)){
        		v[i] = -1;
        	}
        	for(int i:v){
        		if(i != -1) newv.push_back(i);
        	}
        	swap(v,newv);
        }
        board = v;
        
        called = true;
    }
    
    bool isLucky(int n) {
        // code here
        return binary_search(board.begin(),board.end(),n);
    }
};

// { Driver Code Starts.
signed main(){
    int T;
    cin>>T;
    while(T--){
        int n;
        cin>>n;
        Solution obj;
        //calling isLucky() function
        if(obj.isLucky(n))
            cout<<"1\n";//printing "1" if isLucky() returns true
        else
            cout<<"0\n";//printing "0" if isLucky() returns false
    }
    
}  // } Driver Code Ends