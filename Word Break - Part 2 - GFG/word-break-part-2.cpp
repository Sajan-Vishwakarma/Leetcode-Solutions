// { Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
// User function Template for C++

class Solution{
public:
    vector<string> wordBreak(int m, vector<string>& dict, string s){
        // code here
        int n = s.size();
        sort(dict.begin(),dict.end());
        
        vector<string> ans;
        function<void(int,vector<string>&)> fun=[&](int i,vector<string> &str){
            
            if(i >= n){
                string sen = "";
                for(string st:str) 
                    sen += st+' ';
                sen.pop_back();
                ans.push_back(sen);
                return;
            }
            
            string temp = "";
            for(int j=i;j<n;j++){
                temp += s[j];
                if( binary_search(dict.begin(),dict.end(),temp) ){
                    str.push_back(temp);
                    fun(j+1,str);
                    str.pop_back();
                }
            }
        };
        
        vector<string> str;
        fun(0,str);
        
        return ans;
    }
};

// { Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        vector<string> dict;
        string s;
        cin>>n;
        for(int i = 0;i < n;i++){
            cin>>s;
            dict.push_back(s);
        }
        cin>>s;
        
        Solution ob;
        vector<string> ans = ob.wordBreak(n, dict, s);
        if(ans.size() == 0)
            cout<<"Empty\n";
        else{
            sort(ans.begin(), ans.end());
            for(int i = 0;i < ans.size();i++)
                cout<<"("<<ans[i]<<")";
            cout<<endl;
        }
    }
    return 0;
}  // } Driver Code Ends