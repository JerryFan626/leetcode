/*
4.  Median of Two Sorted Arrays
题意：给你两个数组，已经排好了序(你就可以把它们当做升序)，求出这两个数组合并后的中位数。需要用log(n+m)的算法
思路：很经典的一道二分题
     首先，你肯定会想到，开辟用一个(n+m)大小的数组来有序的合并这两个数组，后面直接反问中间元素的下表就可以了，但是这样做初始化的构建这个数组就已经是O(n+m)，不行
     我们想另外一种解法。这就要运用到二分的思维
     因为两个数组是有序的，我们就可以一半一半的排除这个中位数所在的位置，递归下去注意递归的结束条件就行了

     拓展:该题求得是中位数，也就是第len/2的数，请自行思考求第k个数如何求。

*/
#define max(x,y) (x > y ? x : y)
#define min(x,y) (x < y ? x : y)

double solve(int a[], int n, int b[], int m, int k)
{
    if (n > m) return solve(b, m, a, n, k);
    if (n == 0) return b[k - 1];
    if (k == 1) return min(a[0], b[0]);

    int id_a = min(k / 2, n);
    int id_b = k - id_a;
    if (a[id_a - 1] < b[id_b - 1])
        return solve(a + id_a, n - id_a, b, m, k - id_a);
    else if (a[id_a - 1] > b[id_b - 1])
        return solve(a, n, b + id_b, m - id_b, k - id_b);
    else
        return a[id_a - 1];
}

double findMedianSortedArrays(int* nums1, int nums1Size, int* nums2, int nums2Size) {
    int tot = nums1Size + nums2Size;
    if (tot % 2)
        return solve(nums1, nums1Size, nums2, nums2Size, tot/2 + 1);
    else
        return (solve(nums1, nums1Size, nums2, nums2Size, tot/2) + solve(nums1, nums1Size, nums2, nums2Size, tot / 2 + 1)) / 2.0;
}