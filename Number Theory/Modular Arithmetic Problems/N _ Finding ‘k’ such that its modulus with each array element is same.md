# Finding ‘k’ such that its modulus with each array element is same

Given an array of n integers .We need to find all ‘k’ such that

arr[0] % k = arr[1] % k = ....... = arr[n-1] % k 

Input  : arr[] = {6, 38, 34}

Output : 1 2 4
        
6%1 = 38%1 = 34%1 = 0

6%2 = 38%2 = 34%2 = 0

6%4 = 38%4 = 34%2 = 2

Input  : arr[] = {3, 2}
Output : 1


Suppose the array contains only two elements a and b (b>a)
So we can write b = a + d where d isa positive integer and ‘k’ be a number such that b%k = a%k

(a + d)%k = a%k

a%k + d%k = a%k 

d%k = 0

Now what we get from the above calculation is that ‘k’ should be a divisor of difference between the two numbers.
        
Now what we have to do when we have an array of integers.

Find out the difference ‘d’ between maximum and minimum element of the array

Find out all the divisors of ‘d’

Step 3: For each divisor check if arr[i]%divisor(d) is same or not .if it is same print it.

```cpp
void printEqualModNumbers (int arr[], int n) 
{ 
    sort(arr, arr + n); 
    int d = arr[n-1] - arr[0]; 
    vector <int> v; 
    for (int i=1; i*i<=d; i++) 
    { 
        if (d%i == 0) 
        { 
            v.push_back(i); 
            if (i != d/i) 
                v.push_back(d/i); 
        } 
    } 
    for (int i=0; i<v.size(); i++) 
    { 
        int temp = arr[0]%v[i]; 
        int j; 
        for (j=1; j<n; j++) 
            if (arr[j] % v[i] != temp) 
                break;  
        if (j == n) 
            cout << v[i] <<" "; 
    } 
} 
int main() 
{ 
    int arr[] = {38, 6, 34}; 
    int n = sizeof(arr)/sizeof(arr[0]); 
    printEqualModNumbers(arr, n); 
    return 0; 
} 
```
