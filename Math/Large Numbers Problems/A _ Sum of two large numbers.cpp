/*
Given two numbers as strings. The numbers may be very large (may not fit in long long int)
the task is to find sum of these two numbers
Input  : str1 = "3333311111111111", 
         str2 =   "44422222221111"
Output : 3377733333332222
Input  : str1 = "7777555511111111", 
         str2 =    "3332222221111"
Output : 7780887733332222
The idea is based on school mathematics. We traverse both strings from end, one by one add digits and keep track of carry
To simplify the process, we do following:
1) Reverse both strings.
2) Keep adding digits one by one from 0’th index (in reversed strings) to end of smaller string
append the sum % 10 to end of result and keep track of carry as sum/10
3) Finally reverse the result.
*/

string findSum(string str1, string str2) 
{ 
    int n1 = str1.length();
    int n2 = str2.length();
         
    if (str1.length() > str2.length()) 
        swap(str1, str2);
         
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
int main() 
{ 
    string str1 = "12"; 
    string str2 = "198111"; 
    cout << findSum(str1, str2); 
    return 0; 
} 

// Time Complexity : O(n1 + n2) where n1 and n2 are lengths of two input strings representing numbers
