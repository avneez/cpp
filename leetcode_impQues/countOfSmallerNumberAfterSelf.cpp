#include<bits/stdc++.h>
using namespace std;

#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;

typedef tree<int, null_type, less_equal<int>, rb_tree_tag, tree_order_statistics_node_update> ordered_set;

class Solution {
public:
    vector<int> countSmaller(vector<int>& nums) {
//         vector<int> snums;
//         vector<int> ans;
//         snums=nums;
//         sort(snums.begin(),snums.end());

//         for(auto elem:nums){
//             auto itr = find(snums.begin(), snums.end(), elem);
//             int idx = itr-snums.begin();
//             ans.push_back(idx);
//             remove(snums.begin(), snums.end(), elem);
//         }
//         return ans;

        //policy-based DS
        ordered_set p;
        int n=nums.size();
        // int v[n];
        int c=0;
        for(long long i=n-1;i>=0;i--){
            c++;
            p.insert(nums[i]);
            int f=p.order_of_key(nums[i]);
            nums[i]=f;  //v[i]=f;
        }
        return nums;
    }
};
