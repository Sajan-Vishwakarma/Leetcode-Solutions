class Solution {
public:
    int minimumNumbers(int num, int k) {
        
        if(num == 0) return 0;
        
        int size = 1, sum = k;
        while( sum <= num && size<11){
            int last = sum%10;
            if(last == num%10)
                return size;
            sum += k;
            size++;
        }
        
        return -1;
    }
};