/*
3.  Longest Substring Without Repeating Characters 
题意：给你一个字符串S，求出它的一个最长子串，满足这个子串中的字符没有重复的，输出子串长度。
思路：定义一个index数组(初始化为-1) index[i]来表示字符i当前所在位置
     扫一遍字符串S,用now来表示当前满足的子串的长度。
     如果index[S[i]]的值为-1，就是说前面这个字符没出现过。now就可以++了
     如果i - now > index[S[i]] 就是说虽然这个字符前面出现了，但是不在当前子串中，所以now还是可以++
     如果不满足以上两点，说明在当前子串中存在S[i]这个字符，所以now就得更新了，
     now就只能表示之前index记录的S[i]的位置的下一位到当前i这一段子串的长度了 now ＝ i － index[S[i]];
     这样就可以算出来最长的满足题意的子串啦～
*/
int lengthOfLongestSubstring(char* s) {
    int len = strlen(s);
    int index[128];
    memset(index, -1, sizeof(index));

    int ans = 0;
    int now = 0;
    for (int i = 0; i < len; i++)
    {
        int id = index[s[i]];
        if (id == -1 || (id >= 0 && i - now> id))
            now++;
        else
            now = i - id;
        index[s[i]] = i;
        ans = ans > now ? ans : now;
    }
    return ans;
}
