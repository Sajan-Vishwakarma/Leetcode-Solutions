class Solution {
public:
    long long maximumBeauty(vector<int>& a, long long k, int target, int full, int partial) {
        #define int int64_t
        
        int n = a.size();
        cout << n << endl;
        sort(a.begin(), a.end());
        vector<int> pref(n);
        for (int i = 0; i < n; i++)
            pref[i] = a[i];
        for (int i = 1; i < n; i++)
            pref[i] += pref[i - 1];
        int ans = 0;
        for (int i = n; i >= 0; i--) {
            if (i < n) {
                k -= max<int>(0, target - a[i]);
                a[i] = max(a[i], target);
           }
            if (k < 0) {
                break;
            }
            int lo = 0, hi = target - 1;
            int cnt = 0;
            while (lo <= hi) {
                int mid = (lo + hi) / 2;
                int ind = upper_bound(a.begin(), a.end(), mid) - a.begin() - 1;
                ind = min(ind, i - 1);
                int need = ind >= 0 ? (ind + 1) * mid - pref[ind] : 0;
                if (need <= k) {
                    cnt = mid;
                    lo = mid + 1;
                }
                else {
                    hi = mid - 1;
                }
            }
            if (i - 1 >= 0 && a[i - 1] >= target) {
                continue;
            }
            int cur = (n - 1 - i + 1) * full + (i > 0) * cnt * partial;
            // cout << i << " " << cnt << " " << cur << endl;
            ans = max(ans, cur);
        }
        
        #undef int
        
        return ans;
    }
};