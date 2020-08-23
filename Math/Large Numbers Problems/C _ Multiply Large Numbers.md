# Multiply Large Numbers represented as Strings

Given two numbers as strings. The numbers may be very large (may not fit in long long int)
        
the task is to find product of these two numbers.
        
Input : num1 = 4154  
        
num2 = 51454
        
Output : 213739916 
        
Input :  num1 = 654154154151454545415415454  
        
num2 = 63516561563156316545145146514654 
        
Output : 41549622603955309777243716069997997007620439937711509062916
        
The idea is based on school mathematics multiplication
We start from last digit of second number multiply it with first number
Then we multiply second last digit of second number with first number, and so on
We add all these multiplications. While adding, we put i-th multiplication shifted
The approach used in below solution is to keep only one array for result
We traverse all digits first and second numbers in a loop and add the result at appropriate position.
```cpp
void multiply(string str1, string str2) 
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
```
Time Complexity: O(m*n), where m and n are length of two number that need to be multiplied
