// { Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
//User function Template for C++

class Solution {
public:
    int longestPath(vector<vector<int>> matrix, int xs, int ys, int xd, int yd){
       
        int ans = -1, n = matrix.size(), m = matrix[0].size();
        function<void(int,int,int)> fun=[&](int x,int y,int len)->void{
            
            if( x<0 || y<0|| x>=n || y >= m || matrix[x][y] == 0) 
                return;
            
            if(x == xd && y == yd){
                ans = max(ans, len);
                return;
            }
            
            if(matrix[x][y] == 1){
                matrix[x][y] = 0;
                fun(x+1,y,len+1);
                fun(x-1,y,len+1);
                fun(x,y+1,len+1);
                fun(x,y-1,len+1);
                matrix[x][y] = 1;    
            }
        };
        
        fun(xs,ys,0);
        return ans;
    }
};

// { Driver Code Starts.

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n, m;
        cin >> n >> m;
        int xs, ys, xd, yd;
        cin >> xs >> ys >> xd >> yd;
        vector<vector<int>> mat(n, vector<int>(m));
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                cin >> mat[i][j];
            }
        }
        Solution ob;
        int ans = ob.longestPath(mat, xs, ys, xd, yd);
        cout << ans;
        cout << "\n";
    }
    return 0;
}  // } Driver Code Ends