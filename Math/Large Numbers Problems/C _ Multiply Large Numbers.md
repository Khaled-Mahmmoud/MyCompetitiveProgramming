```cpp
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
int main() 
{ 
    string str1 = "1235421415454545454545454544"; 
    string str2 = "1714546546546545454544548544544545"; 
    
    multiply(str1, str2); 
    return 0; 
} 
// Time Complexity: O(m*n)
```
