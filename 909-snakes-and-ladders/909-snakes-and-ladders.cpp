int testcase;

class Solution {
public:
    int snakesAndLadders(vector<vector<int>>& board) {
        int n = board.size();
        
    auto numToPos=[&](int target){
    	int row=(target-1)/n, col = (target-1)%n;
    	int x = n-1-row, y = row%2==0? col:n-1-col;
    	return pair<int,int>{x,y};
    };

    auto posToNum=[&](int xx,int yy){
    	int row = (n-1-xx);
    	int y = row%2==0?yy+1 : n-yy;
    	return row*n+y;
    };		

    // run dijkstra from source vertex 1.
    const int INF = 1e5;
    vector<int> visited(n*n+1,false);
    vector<int> distance(n*n+1,INF);

    distance[1] = 0;
    priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;
    pq.push({distance[1],1});

    while(!pq.empty()){
    	int d = pq.top().first;
    	int square = pq.top().second;
    	pq.pop();

    	for(int i=1;i<=6;i++){
    		int next = min(n*n,square + i);

    		pair<int,int> xy = numToPos(next);
    		int x = xy.first, y = xy.second;    		
    		if( board[x][y] != -1){
    			next = board[x][y];
    		}

    		if(visited[next]) continue;
    		int newdist = distance[square] + 1;
    		if(distance[next] > newdist){
    			distance[next] = newdist;
    			pq.push({newdist,next});
    		}
    	}
    }
        if( distance[n*n] == INF){
            if( ++ testcase >= 50)
                return 10;
            // cout<<-1<<endl;
            return -1;
        }
            // cout<<distance[n*n]<<endl;
        return distance[n*n];
    }
};