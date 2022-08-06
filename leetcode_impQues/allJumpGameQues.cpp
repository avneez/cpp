#include<bits/stdc++.h>
using namespace std;

//jump game 1
/* You are given an integer array nums. You are initially positioned at the array's first index, and each element in the array represents your maximum jump length at that position.

Return true if you can reach the last index, or false otherwise.

Example 1:

Input: nums = [2,3,1,1,4]
Output: true
Explanation: Jump 1 step from index 0 to 1, then 3 steps to the last index.*/

class Solution {
public:
    bool canJump(vector<int>& nums) {
        int last = nums.size()-1;
        for(int i=last; i>=0; i--){
            if(i+nums[i]>=last){
                last=i;
            }
        }
        return last==0;
    }
};

//jump game 2

/* Given an array of non-negative integers nums, you are initially positioned at the first index of the array.

Each element in the array represents your maximum jump length at that position.

Your goal is to reach the last index in the minimum number of jumps.

You can assume that you can always reach the last index.

Example 1:

Input: nums = [2,3,1,1,4]
Output: 2
Explanation: The minimum number of jumps to reach the last index is 2. Jump 1 step from index 0 to 1, then 3 steps to the last index.
Example 2:

Input: nums = [2,3,0,1,4]
Output: 2
*/

class Solution {
public:
    int jump(vector<int>& nums) {
        int farthest=0, jumps=0, curr = 0;
        for(int i=0; i<nums.size()-1; i++){
            farthest = max(farthest, nums[i]+i);
            if(i==curr){
                curr=farthest;
                jumps++;
            }
        }
        return jumps;
    }
};

//jump game 3
/*
Given an array of non-negative integers arr, you are initially positioned at start index of the array. When you are at index i, you can jump to i + arr[i] or i - arr[i], check if you can reach to any index with value 0.

Notice that you can not jump outside of the array at any time.


Example 1:

Input: arr = [4,2,3,0,3,1,2], start = 5
Output: true
Explanation:
All possible ways to reach at index 3 with value 0 are:
index 5 -> index 4 -> index 1 -> index 3
index 5 -> index 6 -> index 4 -> index 1 -> index 3

Example 3:

Input: arr = [3,0,2,1,2], start = 2
Output: false
Explanation: There is no way to reach at index 1 with value 0.
*/
class Solution {
public:
    bool helper(vector<int>& arr, int start, vector<bool>& visited){
        if(start<0 || start>=arr.size() || visited[start]==true){
            return false;
        }
        visited[start]=true;
        if(arr[start]==0) return true;
        bool x=helper(arr, start+arr[start], visited);
        bool y=helper(arr, start-arr[start], visited);
        return x||y;

    }

    bool canReach(vector<int>& arr, int start) {
        vector<bool> visited(arr.size()+1, false);
        return helper(arr,start, visited);
    }
};
