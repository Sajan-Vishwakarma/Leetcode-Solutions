// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution {
  public:
vector<vector<int>> formCoils(int n) {

        n = 4*n;
        vector<int> coil1,coil2;
        vector<vector<bool>> vis(n+1,vector<bool>(n+1,false));

        // down, right, up ,left
        int d1 = 0, d2 = 2;
        int dx[]={1,0,-1,0};
        int dy[]={0,1,0,-1};

        auto getnum=[&](int x,int y){
            return (x-1)*n+y;
        };

        auto valid=[&](int x,int y){
            int newx = x+dx[d1], newy = y+dy[d1];
            if( newx <= 0 || newy <= 0 || newx > n || newy > n || vis[newx][newy]){
                d1 = (d1+1)%4;
                d2 = (d2+1)%4;
            }
            return vis[x+dx[d1]][y+dy[d1]]==false; 
        };

        function<void(int,int,int,int)> fun= [&](int r1,int c1,int r2,int c2)->void{
            
            int num1 = getnum(r1,c1), num2 = getnum(r2,c2);
            vis[r1][c1] = vis[r2][c2] = true;

            coil1.push_back(num1);
            coil2.push_back(num2);

            if( valid(r1,c1) )
                fun(r1+dx[d1],c1+dy[d1],r2+dx[d2],c2+dy[d2]);
        };
        fun(1,1,n,n);

        reverse(coil1.begin(), coil1.end());
        reverse(coil2.begin(), coil2.end());
        return {coil2,coil1};
    }
};

// { Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        
        cin>>n;

        Solution ob;
        vector<vector<int>> ptr = ob.formCoils(n);
        
        for(auto it: ptr)
        {
            for(int i: it)
                cout<<i<<" ";
            cout<<endl;
        }
    }
    return 0;
}  // } Driver Code Ends