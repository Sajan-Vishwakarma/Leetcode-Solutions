class Solution {
public:


    int nextGreaterElement(int num) {

        string s = to_string(num);
        int n = s.size();

        int i,j,k;
        for( i=n-1; i > 0;i--){
            if( s[i] > s[i-1]){
                break;
            }
        }
        // number is in decreasing so next number exists
        if( i == 0) return -1;

        k = i;
        for( j=i ; j < n; j++){
            if( s[j] > s[i-1] && s[j] < s[k]){
                k = j;
            }
        }        
        swap(s[i-1],s[k]);
        sort(s.begin()+i,s.end());

        long long ans = stoll(s);
        return ( ans > (1LL<<31)-1)?-1: int(ans);
    }
};