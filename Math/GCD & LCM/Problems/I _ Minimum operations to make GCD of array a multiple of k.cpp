/*
Given an array and k, we need to find the minimum operations needed to make GCD of the array equal or multiple of k
Here an operation means either increment or decrements an array element by 1.

Input : a = { 4, 5, 6 }, k = 5
Output: 2
Explanation: We can increase 4 by 1 so that it becomes 5 and decrease 6 by 1 so that it becomes 5
Hence minimum operation will be 2.



Input : a = { 4, 9, 6 }, k = 5
Output : 3
Explanation: Just like the previous example we can increase and decrease 4 and 6 by 1 and increase 9 by 1 
so that it becomes 10. Now each element has GCD 5. Hence minimum operation will be 3.

Here we have to make the gcd of the array equal or multiple to k, which means there will be cases in which some elements 
are near k or to some of its multiple. So, to solve this we just have to make each array value equal to or multiple to K
By doing this we will achieve our solution as if every element is multiple of k then it’s GCD will be at least K
Now our next target is to convert the array elements in the minimum operation i.e. minimum number of increment and decrement
This minimum value of increment or decrement can be known only by taking the remainder of each number from K 
i.e. either we have to take the remainder value or (k-remainder) value, whichever is minimum among them.
*/
int MinOperation(int a[], int n, int k) 
{ 
      
    int result = 0; 
      
    for (int i = 0; i < n; ++i) { 
      
        // If array value is not 1 
        // and it is greater than k 
        // then we can increase the 
        // or decrease the remainder 
        // obtained by dividing k 
        // from the ith value of array 
        // so that we get the number 
        // which is either closer to k 
        // or its multiple 
        if (a[i] != 1 && a[i] > k) { 
            result = result + min(a[i] % k, k - a[i] % k); 
        } 
        else { 
  
            // Else we only have one choice 
            // which is to increment the value 
            // to make equal to k 
            result = result + k - a[i]; 
        } 
    } 
  
    return result; 
} 
  
// Driver code 
int main() 
{ 
    int arr[] = { 4, 5, 6 }; 
    int n = sizeof(arr) / sizeof(arr[0]); 
    int k = 5; 
    cout << MinOperation(arr, n, k); 
    return 0; 
}
