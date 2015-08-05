/*

8.  String to Integer (atoi)
题意：实现atoi函数，即将字符串转换为整形
思路：直接模拟即可，注意溢出、正负和前为" "(空格字符)

*/

int myAtoi(char* str) {
    int len = strlen(str);
    double ans = 0;
    int sign = 1, i = 0;
    while (str[i] == ' ') i++;
    
    if (str[i] == '-')
        sign = -1, i++;
    else if (str[i] == '+')
        sign = 1, i++;
    
    for (; isdigit(str[i]); i++)
        ans = ans * 10 + str[i] - '0';
    
    ans = sign * ans ;
    
    ans = ans > INT_MAX ? INT_MAX : ans;
    ans = ans < INT_MIN ? INT_MIN : ans;
    
    return (int)ans;
    
}