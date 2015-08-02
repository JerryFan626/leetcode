/*
1.	Two Sum
题意：给你一个整数数组和一个目标数target，求在整数数组中找到两个值，使得它们两个相加等于目标数，并输出其下标
思路：先Hash下整数数组，再扫一遍数组，如果target-num[i]在数组中存在，即为答案。
*/
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        map<int, int>M;
        for(int i = 0; i < nums.size(); i++){
            M[nums[i]] = i+1;
        }
        
        vector<int>ans;
        for(int i = 0; i < nums.size(); i++){
            int tmp = target - nums[i];
            if(M[tmp] && M[tmp] != i+1){
                ans.push_back(i+1);
                ans.push_back(M[tmp]);
                break;
            }
        }
        return ans;
    }
};
