/*
Smallest number to multiply to convert floating point to natural
Given a positive floating point number n, the task is to find the smallest integer k
such that when we multiply k with n, we get a natural number.
Input : 30.25
Output : 4
30.25 * 4 = 321, there is no number less than 4
which can convert 30.25 into natural number.
Input : 5.5
Output : 2
5.5 * 2 = 11, there is no number less than 2
which can convert 5.5 into natural number.
Input : 5.33
Output : 100
The idea is to convert given floating point number into a fraction (not necessarily in reduced form) 
and find the GCD of numerator and denominator. For example, if input floating point number is 30.25
we convert into fraction as 3025/100. This can be easily done by finding the position of dot.
Finally to get the answer, we divide the denominator of the converted fraction by GCD of denominator and numerator
For example, GCD of 3025 and 100 is 25. We divide 100 by 25 and get the answer as 4.
*/


int findnum(string &str) 
{ 
    int n = str.length(); 
    int count_after_dot = 0; 
    bool dot_seen = false; 
    int num = 0; 
    for (int i = 0; i < n; i++) 
    { 
        if (str[i] != '.') 
        { 
            num = num*10 + (str[i] - '0'); 
            if (dot_seen == true) 
                count_after_dot++; 
        } 
        else
            dot_seen = true; 
    } 
    if (dot_seen == false) 
       return 1; 
    int dem = pow(10, count_after_dot); 
    return (dem / __gcd(num, dem)); 
} 
int main() 
{ 
    string str = "5.125"; 
    cout << findnum(str) << endl; 
    return 0; 
}
