class Solution {
public:
    int minSpeedOnTime(vector<int>& dist, double hour) {
        int n = dist.size();
        
        auto CHECK=[&](int speed){
            double time = 0.0;
            for(int i=0;i<n-1;i++){
                time += (dist[i]+speed-1)/speed;
            }
            time += (dist[n-1]*1.0)/(speed*1.0);
            return time <= hour;
        };
        
        int low = 1, high = 1e8, speed = -1;
        while(low <= high){
            int mid = (low+high)/2;
            if(CHECK(mid)){
                speed = mid;
                high = mid-1;
            }
            else
                low = mid+1;
        }
        
        return speed;
    }
};