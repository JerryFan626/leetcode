/*

136.  Single Number
题意：给你一个整形的数组,其中除了一个元素只出现一次外，其余的都出现两次，输出该元素
思路：异或...  相同元素偶数次异或为0，基数次异或为该元素.
     O(n)
 
    当年进集训队的时候的新手选拔题...  永远记得.....
*/

int singleNumber(int* nums, int numsSize) {
    int ans = 0, i;
    for(i = 0; i < numsSize; i++){
        ans ^= nums[i];
    }
    return ans;
}