template<typename A, typename B> istream& operator>>(istream &is, pair<A, B> &p) { return is >> p.first >> p.second;} template<typename T_container, typename T = typename enable_if<!is_same<T_container, string>::value, typename T_container::value_type>::type> istream& operator>>(istream &is, T_container &v) { for (T& x : v) is >> x; return is;} bool debug;
template<typename A, typename B> ostream& operator<<(ostream &os, const pair<A, B> &p) { return debug ? os << '<'<<p.first<<"," <<p.second<<">" : os << p.first << " " << p.second;} template<typename T_container, typename T = typename enable_if<!is_same<T_container, string>::value, typename T_container::value_type>::type> ostream& operator<<(ostream &os, const T_container &v) { if(debug) { os << "["; string sep; for (const T &x : v) os << sep << x, sep = ", "; os << "]\n"; } else { bool f = false; for (const T &x : v) { if(f) {os << " ";} os << x, f = true; } } return os;}
template <typename T, typename T1, typename... Tail> T amin(T& a, T1 b, Tail... c) { if(b < a) a = b; if constexpr (sizeof...(c) != 0) { amin(a, c...); } return a; } template <typename T, typename T1, typename... Tail> T amax(T& a, T1 b, Tail... c) { if(b > a) a = b; if constexpr (sizeof...(c) != 0) { amax(a, c...); } return a; }
void dbg_out() { cout << endl; } template<typename Head, typename... Tail> void dbg_out(Head H, Tail... T) { cout << ' ' << H; dbg_out(T...); }
 
#ifdef ONLINE_JUDGE
#define dbg(...)
#else
#define dbg(...) cout << "[" << #__VA_ARGS__ << "]:\n", debug = true, dbg_out(__VA_ARGS__), debug = false
#endif


class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        vector<vector<pair<int, int>>> graph(n);
        for(auto e : flights) {
            graph[e[0]].push_back({e[1], e[2]});
        }
        priority_queue<vector<int>, vector<vector<int>>, greater<vector<int>>> pq;
        // {dist_from_src_node, node, number_of_stops_from_src_node}
        pq.push({0, src, 0});
        
        vector<int> stops(n, INT_MAX);
        // number of stops to reach indexth node with least possible price from src node
        // as it will be calculated once the pq.top() equals to indexth node
        
        // pq.top() will always store least cost among the pq elements so if already stop is calculated
        // and if that is greater than the cstop that means already we have a path with cheaper cost
        // as well as with less or equal number of stops
        
        while(!pq.empty()) {
            auto temp=pq.top();
            int cdist=temp[0];
            int cnode=temp[1];
            int cstop=temp[2];
            pq.pop();
            
            if(cstop>stops[cnode] || cstop>k+1)
                continue;
            
            stops[cnode]=cstop;
            if(cnode==dst) {
                return cdist;
            }
            
            for(auto a : graph[cnode]) {
                pq.push({cdist+a.second, a.first, cstop+1});
            }
        }
        return -1;
    }
};