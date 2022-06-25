// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


 // } Driver Code Ends


class Solution{

public:
    
    long long minimum_amount(vector<vector<int>> &E, int num, int start, int *cap){
        list<int> graph[num+1];
        for(int i=0;i<E.size()-1;i++){
            graph[E[i][0]].push_back(E[i][1]);
            graph[E[i][1]].push_back(E[i][0]);
        }
        
        function<bool(int,int,long long)> isPossible=[&](int node,int par,long long water){
            // cout<<node<<" "<<par<<" "<<water<<endl;
            
            if( cap[node-1] > water) return false;
            int branches = graph[node].size() - (par!=-1);
            water -= cap[node-1];
            
            bool ok = true;
            for(int child:graph[node]){
                if(child == par) continue;
                ok &= isPossible(child,node,water/branches);
                if(ok == false) return false;
            }
            return ok;
        };
        
        long long low = 1, high=1000000000000000000, res = -1;
        while(low<=high){
            
            long long mid=(low+high)/2;
            // cout<<mid<<endl;
            
            if(isPossible(start,-1,mid)==true){
                res=mid;
                high=mid-1;
            }
            else{
                low=mid+1;
            }
        }
        return res==0 ? -1 : res;
    }
};

// { Driver Code Starts.


int main()
 {
	int T;
	cin>> T;
	while (T--)
	{
	    int num, start;
	    cin>>num>>start;
	    int cap[num];
	    for(int i = 0; i<num; i++)
	        cin>>cap[i];
	    
	    vector<vector<int>> Edges(num);
	    for(int i=1;i < num;i++){
	        int u, v; cin >> u >> v;
	        Edges[i-1].push_back(u);
	        Edges[i-1].push_back(v);
	    }
	    
	    
    	Solution obj;
	    long long ans = obj.minimum_amount(Edges, num, start, cap);
	    cout << ans << endl;
	    
	}
	
	return 0;
}  // } Driver Code Ends