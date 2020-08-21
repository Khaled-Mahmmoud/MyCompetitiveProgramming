# Longest Regular Bracket Sequence

This is yet another problem dealing with regular bracket sequences.

We should remind you that a bracket sequence is called regular, if by inserting «+» and «1» into it we can get a correct mathematical expression. For example, sequences «(())()», «()» and «(()(()))» are regular, while «)(», «(()» and «(()))(» are not.

You are given a string of «(» and «)» characters. You are to find its longest substring that is a regular bracket sequence. You are to find the number of such substrings as well.

Input : The first line of the input file contains a non-empty string, consisting of «(» and «)» characters. Its length does not exceed 106.

Output : Print the length of the longest substring that is a regular bracket sequence, and the number of such substrings. If there are no such substrings, write the only line containing "0 1".

|input | output |
|---|---|
|)((())))(()())|6 2|
|))(|0 1|

First of all, for each closing bracket in our string let's define 2 values:

 - d[j] = position of corresponding open bracket, or -1 if closing bracket doesn't belong to any regular bracket sequence.
 - c[j] = position of earliest opening bracket, such that substring s(c[j], j) (both boundaries are inclusive) is a regular bracket sequence. Let's consider c[j] to be -1 if closing bracket doesn't belong to any regular bracket sequence.

It can be seen, that c[j] defines the beginning position of the longest regular bracket sequence, which will end in position j. So, having c[j] answer for the problem can be easily calculated.

Both d[j] and c[j] can be found with following algorithm, which uses stack.

1) Iterate through the characters of the string.
2) If current character is opening bracket, put its position into the stack.
3) If current character is closing bracket, there are 2 subcases:

- Stack is empty - this means that current closing bracket doesn't have corresponding open one. Hence, both d[j] and c[j] are equal to -1.
- Stack is not empty - we will have position of the corresponding open bracket on the top of the stack - let's put it to d[j] and remove this position from the stack. Now it is obvious, that c[j] is equal at least to d[j]. But probably, there is a better value for c[j]. To find this out, we just need to look at the position d[j] - 1. If there is a closing bracket at this position, and c[d[j] - 1] is not -1, than we have 2 regular bracket sequences s(c[d[j] - 1], d[j] - 1) and s(d[j], j), which can be concatenated into one larger regular bracket sequence. So we put c[j] to be c[d[j] - 1] for this case.

```cpp
int main()
{
    string str;
    cin>>str;
    stack<pair<int,char>>st;
    int d[str.size()],c[str.size()];
    memset(d,-1,sizeof d);
    memset(c,-1,sizeof c);
    for(int i=0;i<str.size();i++)
    {
        if(str[i]==')')
        {
            if(st.empty())
                continue;
            else
            {
                pair<int,char> p = st.top();
                d[i] = p.first;
                c[i] = d[i];
                if(d[i]-1>=0&&c[d[i]-1]!=-1)
                    c[i] = c[d[i] - 1];
                st.pop();
            }
        }
        else
            st.push({i,str[i]});
    }
    int mx = 0,cnt = 0;
    for(int i=0;i<str.size();i++)
    {
        if(c[i]!=-1&&mx<i - c[i]+1)
            mx = i-c[i]+1;
    }
    for(int i=0;i<str.size();i++)
    {
        if(c[i]!=-1&&mx == i-c[i]+1)
            cnt++;
    }
    if(mx == 0)
        cout<<mx<<' '<<1;
    else
    cout<<mx<<' '<<cnt;
    return 0;
}
```
