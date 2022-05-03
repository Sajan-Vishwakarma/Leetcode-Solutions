// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution {
public:
    vector<int> FindExitPoint(vector<vector<int>>&matrix){
		// Code here
		int n = matrix.size(), m  = matrix[0].size();
		auto valid=[&](int x,int y){
		if(x<0||x>=n||y<0||y>=m)
			return false;
		return true;
	};


	vector<pair<int,int>> directions= {
		{0,1}, // right
		{1,0},// down
		{0,-1},// left
		{-1,0} // up
 	};

	int x=0,y=0; // alice current position
 	int dir = 0; // current Alice is facing right;
	while(true){
		
		if( matrix[x][y] == 1){
			matrix[x][y] = 0;
			dir = (dir+1)%4;
		}

		int dx = directions[dir].first, dy=directions[dir].second;
		if( valid(x+dx, y+dy) == false ){
			// after taking this step she will step out of matrix.
			break;
		}
		x += dx;
		y += dy;
	}
// 	cout<<x<<" "<<y<<endl;
    return vector<int>{x,y};
    }
};

// { Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n, m;
		cin >> n >> m;
		vector<vector<int>>matrix(n, vector<int>(m, 0));
		for(int i = 0; i < n; i++)
			for(int j = 0; j < m; j++)
				cin >> matrix[i][j];
		Solution obj;
		vector<int> ans = obj.FindExitPoint(matrix);
		for(auto i: ans)
			cout << i << " ";
		cout << "\n";
	}
	return 0;
}  // } Driver Code Ends