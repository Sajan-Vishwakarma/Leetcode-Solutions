vector<long long> st;
bool called = false;

class Solution {
public:
    Solution(){
        if( called )
            return;

        auto checkpalindrome=[&](const string &num){
            int l = 0, r = num.size()-1;
            while( l <= r){
                if( num[l] != num[r])
                    return false;
                l++;
                r--;
            }
            return true;
        };

        auto makepalindrome=[&](int i){
            string first = to_string(i) , fl = first;
            reverse(fl.begin(), fl.end());

            if( (first.size() + fl.size() < 10) && checkpalindrome(first+fl)){
                long long num = stoll(first+fl);
                if( checkpalindrome(to_string(num*num)) )
                    st.push_back(num*num);
            }
            first.pop_back();
            if( (first.size() + fl.size() < 10) && checkpalindrome(first+fl)){
                long long num = stoll(first+fl);
                if( checkpalindrome(to_string(num*num)) )
                    st.push_back(num*num);
            }
        };
        for(int i = 1;i<=100000;i++){
            makepalindrome(i);
        }
        sort(st.begin(), st.end());
        called = true;
    }

    int superpalindromesInRange(string left, string right) {
        long long start = stoll(left), end = stoll(right);
        auto firstindex = lower_bound(st.begin(), st.end(),start);
        auto lastindex = upper_bound(st.begin(), st.end(),end);
        return lastindex-firstindex;
    }
};