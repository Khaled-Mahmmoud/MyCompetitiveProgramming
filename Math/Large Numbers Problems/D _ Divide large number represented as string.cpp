/*
Given a large number (represented as string) which has to divided by another number (represented as int data type)
The large number can be very large which does not even fit in long long in C++. The task is to find division of these numbers.

Input : number  = 1260257
        divisor = 37
Output : 34061
(See below diagram)

Input : number  = 12313413534672234
        divisor = 754
Output : 16330787181262

Input : number  = 1248163264128256512
        divisor = 125
Output : 9985306113026052

*/

string longDivision(string number, int divisor) 
{ 
    string ans; 
    int idx = 0; 
    int temp = number[idx] - '0'; 
    while (temp < divisor) 
       temp = temp * 10 + (number[++idx] - '0'); 
    while (number.size() > idx) 
    { 
        ans += (temp / divisor) + '0'; 
        temp = (temp % divisor) * 10 + number[++idx] - '0'; 
    } 
    if (ans.length() == 0) 
        return "0"; 
    return ans; 
} 
