/*
Given an integer, the task is to find factorial of the number
1 ≤ T ≤ 100
1 ≤ N ≤ 1000
*/

// first solution
vector<string>v(1009,"*");
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
int main()
{
    f();
    int t;cin>>t;while(t--)
    {
        int n;cin>>n;
        cout<<v[n]<<'\n';
    }
	return 0;
}
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//                                                   second solution
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

#define MAX 5000
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
        res[res_size] = carry%10; 
        carry = carry/10; 
        res_size++; 
    } 
    return res_size; 
} 
void factorial(int n) 
{ 
    int res[MAX]; 

    res[0] = 1; 
    int res_size = 1; 
  
    for (int x=2; x<=n; x++) 
        res_size = multiply(x, res, res_size); 

    for (int i=res_size-1; i>=0; i--) 
        cout << res[i]; 
} 
int main()
{
    int t;cin>>t;while(t--)
    {
        int n;cin>>n;
        factorial(n);
        cout<<'\n';
    }
	return 0;
}
