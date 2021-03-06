#define vi vector<int>
#define vvi vector<vector<int>>

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
    void fun(int n, int target, vi &candidates, vvi &ans, vi &temp){
        
        if(target < 0 || n <=0 ){
            return ;
        }
        
        if(target == 0){
            ans.push_back(temp);
            return;
        }
        
        if(candidates[n-1] <= target){
            temp.push_back(candidates[n-1]);
            fun(n,target-candidates[n-1],candidates,ans,temp);
            temp.pop_back();
            
            fun(n-1,target,candidates,ans,temp);
            return;
        }
        else{
            fun(n-1,target,candidates,ans,temp);
            return;
        }
    }
    // vvi ans;vi temp;
    // int n = candidates.size();
    // fun(n,target,candidates,ans,temp);
    // return ans;
    
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        
        int n = candidates.size();
        sort(candidates.begin(),candidates.end());
        vector<vector<int>> dp[target+1];
        
        dp[0] = {{}};
        
        for(int t=1;t<=target;t++){
            dp[t] = {};
            for(int &candidate:candidates){
                if(candidate > t) break;
                for(vector<int> combination:dp[t-candidate]){
                    // <= to keep unique combination, if all combination remove if condition
                    // issi saal kiya hai to yaad rahega
                    if(combination.empty() || combination.back() <= candidate){
                        combination.push_back(candidate);
                        dp[t].push_back(combination);
                    }
                }
            }
        }
        
        return dp[target];
    }
};






























