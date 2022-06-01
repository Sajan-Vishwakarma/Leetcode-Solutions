class Solution {
public:


    int nextGreaterElement(int num) {

        string s = to_string(num), intmax="2147483647";
        int n = s.size();

        auto compare=[&](string s,string intmax){
            if( s.size() > intmax.size()) return true;
            if( intmax.size() > s.size()) return false;

            for(int i=0;i<n;i++){
                if( s[i] > intmax[i]){
                    return true;
                }
                else if(s[i] < intmax[i]) {
                    return false;
                }
            }
            return false;
        };

        int i,j,k;
        for( i=n-1; i > 0;i--){
            if( s[i] > s[i-1]){
                break;
            }
        }
        // number is in decreasing so next number doesn't exists
        if( i == 0) return -1;

        k = i;
        for( j=i ; j < n; j++){
            if( s[j] > s[i-1] && s[j] <= s[k]){
                k = j;
            }
        }        
        swap(s[i-1],s[k]);
        sort(s.begin()+i,s.end());
        return compare(s,intmax)?-1:stoi(s);
    }
};