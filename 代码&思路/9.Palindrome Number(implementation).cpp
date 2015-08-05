/*

9.  Palindrome Number
题意：判断一个数是否为回文数。eg：121、12321
思路：直接模拟即可，注意正负

*/

bool isPalindrome(int x) {
    int num = 0, tmp = x;
    while (tmp)
    {
        num = num * 10 + tmp % 10;
        tmp /= 10;
    }
    if (x < 0) num = -num;
    if (num == x) return 1;
    else return 0;
    
}