/*

6.  ZigZag Conversion
题意：给出一个字符串和一个数nRow,nRow代表下面需要输出的行数,输出的形式看题目所示
思路：纯模拟题,处理的时候注意下就行了

*/

char* convert(char* s, int numRows) {
    int len = strlen(s);
    if (numRows == 1 || numRows >= len) return s;
    
    char* ans = (char*)malloc(len + 1);
    int id = 0;
    for (int i = 0; i < len; i += 2 * (numRows - 1))  ans[id++] =  s[i];
    
    for (int i = 1; i < (numRows - 1) && i < len; i++)
    {
        ans[id++] = s[i];
        for (int j = i + 2 * (numRows - 1); j - i * 2 < len; j += 2 * (numRows - 1))
        {
            ans[id++] = s[j - i * 2];
            if (j < len)
                ans[id++] = s[j];
        }
    }
    
    for (int i = numRows - 1; i < len; i += 2 * (numRows - 1)) ans[id++] = s[i];
    ans[id] = 0;
    return ans;
    
}
