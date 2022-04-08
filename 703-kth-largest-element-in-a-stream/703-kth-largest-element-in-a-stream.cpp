#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;

typedef tree<int, null_type, less_equal<int>, rb_tree_tag, tree_order_statistics_node_update> indexed_multiset;
typedef tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> indexed_set;
 
class KthLargest {
public:
    
    int k;
    indexed_multiset ms;
    
    KthLargest(int K, vector<int>& nums) {
        k = K;
        for(int i=0;i<nums.size();i++){
            ms.insert(nums[i]);
        }
    }
    
    int add(int val) {
        
        ms.insert(val);
        return *ms.find_by_order(ms.size()-k);
    }
};

/**
 * Your KthLargest object will be instantiated and called as such:
 * KthLargest* obj = new KthLargest(k, nums);
 * int param_1 = obj->add(val);
 */