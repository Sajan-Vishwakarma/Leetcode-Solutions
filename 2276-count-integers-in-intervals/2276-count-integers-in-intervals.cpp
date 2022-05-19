
class CountIntervals {
public:

    int ans;
    set<pair<int,int>> s;

    CountIntervals() {
        ans = 0;
    }

    void add(int left, int right) {
        auto it = s.lower_bound({left,right});
        if( it != s.begin() && left <= prev(it)->second )
            it = prev(it);

        int ll=left,rr=right;
        while( it != s.end() ){
            int a = it->first, b = it->second;
            if( rr < a || ll > b) break;
            ll = min(a,ll), rr = max(b,rr);
            ans -= (b-a+1);
            it = s.erase(it);
        }
        s.insert({ll,rr});
        ans += rr-ll+1;
    }
    
    int count() {
        return ans;
    }
};

/**
 * Your CountIntervals object will be instantiated and called as such:
 * CountIntervals* obj = new CountIntervals();
 * obj->add(left,right);
 * int param_2 = obj->count();
 */