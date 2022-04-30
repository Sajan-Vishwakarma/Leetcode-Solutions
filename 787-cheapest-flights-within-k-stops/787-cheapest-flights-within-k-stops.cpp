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
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int K) {
        /* distance from source to all other nodes */
        vector<int> dist( n, INT_MAX );
        dist[src] = 0;
        
        // Run only K+1 times since we want shortest distance in K hops
        for( int i=0; i <= K; i++ ) {
            vector<int> tmp( dist );
            for( auto flight : flights ) {
                if( dist[ flight[0] ] != INT_MAX ) {
                    tmp[ flight[1] ] = min( tmp[flight[1]], dist[ flight[0] ] + flight[2] );
                }
            }
            dist = tmp;
        }
        return dist[dst] == INT_MAX ? -1 : dist[dst];
    }
};