```cpp
// Sum of two large numbers
string findSum(string str1, string str2) 
{    
    if (str1.length() > str2.length()) 
        swap(str1, str2);
        
    int n1 = str1.length();
    int n2 = str2.length();
        
    string str = ""; 
    reverse(str1.begin(), str1.end()); 
    reverse(str2.begin(), str2.end()); 
  
    int carry = 0; 
    for (int i=0; i<n1; i++) 
    { 
        int sum = ((str1[i]-'0')+(str2[i]-'0')+carry); 
        str.push_back(sum%10 + '0'); 
        carry = sum/10; 
    } 
    for (int i=n1; i<n2; i++) 
    { 
        int sum = ((str2[i]-'0')+carry); 
        str.push_back(sum%10 + '0'); 
        carry = sum/10; 
    } 
    if (carry) 
        str.push_back(carry+'0'); 
    reverse(str.begin(), str.end()); 
  
    return str; 
} 
// Time Complexity : O(n1 + n2) 

// Difference of two large numbers
bool islarger(string str1,string str2)
{
    int n1=str1.length();
    int n2=str2.length();
        
    // if str1 = 003234 it will be 3234
    int i=0;
    while(i<n1-1&&str1[i]=='0')i++;
    a=a.substr(i);
        
    // if str2 = 000 it will be 0
    i=0;
    while(i<n2-1&&str2[i]=='0')i++;
    b=b.substr(i);
        
    // resize length of a and b
    n1=a.length();
    n2=b.length();
        
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
    if(islarger(str1,str2))
        swap(str1,str2);
        
    int n1=str1.length();
    int n2=str2.length();
    
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
// Time complexity : O(n1 + n2)

// Multiply Large Numbers represented as Strings
string multiply(string str1, string str2) 
{ 
    if(str1.at(0) == '-' && str2.at(0)!='-') 
    { 
         str1 = str1.substr(1); 
         cout<<"-";
    } 
    else if(str1.at(0) != '-' && str2.at(0) == '-') 
    { 
         str2 = str2.substr(1); 
         cout<<"-";
    } 
    else if(str1.at(0) == '-' && str2.at(0) == '-') 
    { 
         str1 = str1.substr(1); 
         str2 = str2.substr(1); 
    } 
    int n1 = str1.length(); 
    int n2 = str2.length(); 
        
    if (n1 == 0 || n2 == 0) 
    return "0"; 
        
    vector<int> result(n1 +n2, 0); 
        
    int i_n1 = 0;  
    int i_n2 = 0;  
        
    for (int i=n1-1; i>=0; i--) 
    { 
        int carry = 0; 
        int m1 = str1[i] - '0'; 
        i_n2 = 0;       
        for (int j=n2-1; j>=0; j--) 
        { 
            int m2 = str2[j] - '0'; 
            int sum = m1*m2 + result[i_n1 + i_n2] + carry; 
            carry = sum/10; 
            result[i_n1 + i_n2] = sum % 10; 
            i_n2++; 
        } 
        if (carry > 0) 
            result[i_n1 + i_n2] += carry; 
        i_n1++; 
    } 
    int i = result.size() - 1; 
    while (i>=0 && result[i] == 0) 
    i--; 
    if (i == -1) 
    return "0"; 
    
    string str = ""; 
    while (i >= 0) 
        str.push_back(result[i--]+'0'); 
  
    return str; 
} 
// Time Complexity: O(n1*n2)

// Divide large number represented as string
string longDivision(string number, int divisor) 
{ 
    string ans; 
    int idx = 0; 
    int temp = (number[idx] - '0'); 
    while (idx<number.size() && temp < divisor) 
       temp = temp * 10 + (number[++idx] - '0'); 
    while(idx < number.size()) 
    { 
        ans += ((temp / divisor) + '0'); 
        temp = (temp % divisor) * 10 + (number[++idx] - '0'); 
    } 
    if (ans.length() == 0) 
        return "0"; 
    return ans; 
} 

// Factorial of a large number
// First Solution
vector<string>v(1009);
string multiply(string str1, string str2) 
{ 
    int n1 = str1.length(); 
    int n2 = str2.length(); 
        
    if (n1 == 0 || n2 == 0) 
    return "0"; 
        
    vector<int> result(n1 +n2, 0); 
        
    int i_n1 = 0;  
    int i_n2 = 0;  
        
    for (int i=n1-1; i>=0; i--) 
    { 
        int carry = 0; 
        int m1 = str1[i] - '0'; 
        i_n2 = 0;       
        for (int j=n2-1; j>=0; j--) 
        { 
            int m2 = str2[j] - '0'; 
            int sum = m1*m2 + result[i_n1 + i_n2] + carry; 
            carry = sum/10; 
            result[i_n1 + i_n2] = sum % 10; 
            i_n2++; 
        } 
        if (carry > 0) 
            result[i_n1 + i_n2] += carry; 
        i_n1++; 
    } 
    int i = result.size() - 1; 
    while (i>=0 && result[i] == 0) 
    i--; 
    if (i == -1) 
    return "0"; 
    
    string str = ""; 
    while (i >= 0) 
        str.push_back(result[i--]+'0'); 
  
    return str; 
} 
void init()
{
    v[0] = "1";
    for(int i=1;i<=1000;i++)
        v[i] = multiply(v[i-1],to_string(i));
}
int main()
{
    init();
    int t;cin>>t;while(t--)
    {
        int n;cin>>n;
        cout<<v[n]<<'\n';
    }
	return 0;
}
// Second Solution
vector<string>v(1009);
int multiply(int x, int res[], int res_size) 
{ 
    int carry = 0; 
    for (int i=0; i<res_size; i++) 
    { 
        int prod = res[i] * x + carry; 
        res[i] = prod % 10;   
        carry  = prod/10;     
    } 
    while (carry) 
    { 
        res[res_size++] = carry%10; 
        carry = carry/10; 
    } 
    return res_size; 
} 
void init() 
{ 
    int res[3000];  // size of factorial(1000) equals 2568

    res[0] = 1; 
    int res_size = 1; 
    v[0] = "1";
    
    for (int x=1; x<=1000; x++) 
    {
        res_size = multiply(x, res, res_size);
        for (int i=res_size-1; i>=0; i--) 
        v[x].push_back(res[i]+'0'); 
    }
} 
int main()
{
    init();
    int t;cin>>t;while(t--)
    {
        int n;cin>>n;
        cout<<v[n]<<'\n';
    }
	return 0;
}
// Complexity : Second Solution is the better.

// How to compute mod of a big number?
int mod(string num, int a) 
{ 
    int res = 0; 
    for (int i = 0; i < num.length(); i++) 
         res = (res*10 + (num[i] - '0')) %a; 
    return res; 
} 
```
