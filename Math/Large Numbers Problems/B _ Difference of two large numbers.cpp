/*
Difference of two large numbers
Given two numbers as strings. The numbers may be very large (may not fit in long long int)
the task is to find difference of these two numbers.

Input : str1 = "11443333311111111100", 
        str2 =     "1144422222221111"
Output : 11442188888888889989

Input :str1 = "122387876566565674",
       str2 =     "31435454654554"
Output : 122356441111911120

This is simple based on school mathematics. We traverse both strings from end, one by one subtract digits.
1) Reverse both strings.
2) Keep subtracting digits one by one from 0’th index (in reversed strings) to end of smaller string,
append the diff if it’s positive to end of result. If difference(diff) is negative then add 10 
and keep track of carry as 1 if it’s positive then carry is 0.
3) Finally reverse the result.
*/
bool smaller(string str1,string str2)
{
    if(n1<n2)
        return false;
    if(n1>n2)
        return true;
    for(int i=0;i<n1;i++)
    if(str1[i]<str2[i])
        return false;
    else if(str1[i]>str2[i])
        return true;
    return false;
    
}
string findDiff(string str1,string str2)
{
    int n1=str1.length();
    int n2=str2.length();
    
    if(smaller(str1,str2))
        swap(str1,str2);
        
    string str;
    int carry = 0;
    
    reverse(str1.begin(),str1.end());
    reverse(str2.begin(),str2.end());
    
    for(int i=0;i<n1;i++)
    {
        int sub = (str2[i]-'0') - (str1[i]-'0') - carry;
        if(sub<0)
        {
            sub+=10;
            carry=1;
        }
        else 
            carry=0;
        str.push_back(sub+'0');
    }
    for(int i=n1;i<n2;i++)
    {
        int sub = (str2[i]-'0') - carry;
        if(sub<0)
        {
            sub+=10;
            carry=1;
        }
        else
            carry=0;
        str.push_back(sub+'0');
    }
    reverse(str.begin(),str.end());
    return str;

}
