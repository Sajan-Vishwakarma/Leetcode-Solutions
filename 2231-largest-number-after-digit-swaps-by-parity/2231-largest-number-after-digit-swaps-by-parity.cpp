class Solution {
public:
    
int largestInteger(int num){

    vector<int> odd,even,v;
    while(num > 0){
        int d = num%10;
        v.push_back(d);
        if(d&1) odd.push_back(d);
        else even.push_back(d);
        num /= 10;
    }
    reverse(v.begin(), v.end());
    
    sort(odd.begin(), odd.end());
    sort(even.begin(), even.end());

    int n = 0;
    for(int i:v){
        n*= 10;
        if(i&1){
            n += odd.back();
            odd.pop_back();
        }
        else{
            n += even.back();
            even.pop_back();
        }
    }

    return n;
}
};