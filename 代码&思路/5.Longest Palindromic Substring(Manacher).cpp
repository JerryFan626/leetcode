/*
5.  Longest Palindromic Substring(Manacher)
题意：输出一个串的最大回文子串
思路：ACM大法好 而且窝是主要弄字符串的 (*^__^*) 嘻嘻……
     看到就直接Manacher了，O(n)的算法，用DP的话O(n^2)
     额... 数据范围只有1000..  我的心里是崩溃的...

     关于Manacher的学习，我之前看的是这篇博客
     http://blog.csdn.net/ggggiqnypgjg/article/details/6645824
     这算法的思想很有趣

*/


#define max(x, y) (x > y ? x : y)
#define min(x, y) (x < y ? x : y)
#define MAXN 1010

int Mp[MAXN * 2];
char Ma[MAXN * 2];

void Manacher(char s[], int len){
    int l = 0, i;
    Ma[l++] = '$';
    Ma[l++] = '#';
    for (i = 0; i < len; i++){
        Ma[l++] = s[i];
        Ma[l++] = '#';
    }
    Ma[l] = 0;
    int mx = 0, id = 0;
    for (i = 0; i < l; i++){
        Mp[i] = mx > i ? min(Mp[2 * id - i], mx - i) : 1;
        while (Ma[i + Mp[i]] == Ma[i - Mp[i]]) Mp[i]++;
        if (i + Mp[i] > mx){
            mx = i + Mp[i];
            id = i;
        }
    }
}

char *longestPalindrome(char* s) {
    int i, j;
    int len = strlen(s);
    int ans = -1, index = -1;
    char* res = (char *)malloc(len + 1);
    
    Manacher(s, len);
    for (i = 0; i < 2 * len + 2; i++)
    {
        if (ans < Mp[i] - 1){
            ans = Mp[i] - 1;
            index = i;
        }
    }

    for (i = index - ans + 1, j = 0; i <= index + ans - 1; i++)
        if (Ma[i] != '#')
            res[j++] = Ma[i];
    res[j] = 0;
    
    return res;
}
