/*

7.  Reverse Integer
题意：反转整数
思路：注意可能会爆int, 还有注意溢出后的前导零问题

*/


int reverse(int x) {
    int ans = 0;
    while (x != 0)
    {
        if (ans > INT_MAX / 10 ||  ans < INT_MIN / 10) return 0;
        ans = ans * 10 + x % 10;
        x = x / 10;
    }
    return ans;
}