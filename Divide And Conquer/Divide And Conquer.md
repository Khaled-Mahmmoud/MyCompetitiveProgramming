# Divide And Conquer

we are going to discuss how Divide and Conquer technique is helpful and how we can solve the problem with the DAC technique approach.

This technique can be divided into the following three parts:

**Divide**: This involves dividing the problem into some sub problem.

**Conquer**: Sub problem by calling recursively until sub problem solved.

**Combine**: The Sub problem Solved so that we will get find problem solution.

The following are some standard algorithms that follows Divide and Conquer algorithm.

**Binary Search** is a searching algorithm. In each step, the algorithm compares the input element x with the value of the middle element in array. If the values match, return the index of the middle. Otherwise, if x is less than the middle element, then the algorithm recurs for left side of middle element, else recurs for the right side of the middle element.

**Quicksort** is a sorting algorithm. The algorithm picks a pivot element, rearranges the array elements in such a way that all elements smaller than the picked pivot element move to left side of pivot, and all greater elements move to right side. Finally, the algorithm recursively sorts the subarrays on left and right of pivot element.

**Merge Sort** is also a sorting algorithm. The algorithm divides the array in two halves, recursively sorts them and finally merges the two sorted halves.

**Closest Pair** of Points The problem is to find the closest pair of points in a set of points in x-y plane. The problem can be solved in O(n^2) time by calculating distances of every pair of points and comparing the distances to find the minimum. The Divide and Conquer algorithm solves the problem in O(nLogn) time.

**Strassen’s Algorithm** is an efficient algorithm to multiply two matrices. A simple method to multiply two matrices need 3 nested loops and is O(n^3). Strassen’s algorithm multiplies two matrices in O(n^2.8974) time.
Cooley–Tukey Fast Fourier Transform (FFT) algorithm is the most common algorithm for FFT. It is a divide and conquer algorithm which works in O(nlogn) time.

**Karatsuba algorithm** for fast multiplication it does multiplication of two n-digit numbers in at most 3 * n^ log2 3 = 3 n^(1.585) single-digit multiplications in general (and exactly n^{\log_23} when n is a power of 2). It is therefore faster than the classical algorithm, which requires n2 single-digit products. If n = 210 = 1024, in particular, the exact counts are 310 = 59, 049 and (210)2 = 1, 048, 576, respectively.

**Approach** : To find the maximum and minimum element from a given array using DAC

```cpp
#include <bits/stdc++.h>
using namespace std;
int max_dac(int arr[],int l,int r)
{
    if(l==r)
        return arr[l];
    int mid=(l+r)/2;

    return max( max_dac(arr,l,mid),max_dac(arr,mid+1,r));

}
int min_dac(int arr[],int l,int r)
{
    if(l==r)
        return arr[l];
    int mid=(l+r)/2;

    return min( min_dac(arr,l,mid),min_dac(arr,mid+1,r));

}
int main()
{
    int a[7] = { 70, 250, 50, 80, 140, 12, 14 };
    cout<<max_dac(a, 0, 7)<<'\n';  // 250
    cout<<min = min_dac(a, 0, 7)<<'\n';  // 14
    return 0;
}
```
