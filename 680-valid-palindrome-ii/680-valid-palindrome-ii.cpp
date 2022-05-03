class Solution {
public:
    bool validPalindrome(string s) {
        
    auto ispalindrome=[&](int l,int r){
		while(l<=r){
			if(s[l] != s[r]) return false;
			l++;r--;
		}
		return true;
	};

	if(ispalindrome(0,s.size()-1)){
		// cout<<"Yes";
		return true;
	}

	int left=0, right = s.size()-1;
	while(left <= right){
		if(s[left] != s[right]){
			if( ispalindrome(left+1,right) || ispalindrome(left,right-1)){
				// cout<<"Yes\n";
				return true;
			}
            break;
		}
		left++;
		right--;
	}
        
        return false;
    }
};