/*
Input: 1 2 3
Output: 
    1 2 3
    2 1 3
    3 1 2
    1 3 2
    2 3 1
    3 2 1
    
Heap’s algorithm is used to generate all permutations of n objects
The idea is to generate each permutation from the previous permutation by choosing a pair of elements to interchange
without disturbing the other n-2 elements
*/

void printArr(int a[],int n) 
{ 
    for (int i=0; i<n; i++) 
        cout << a[i] << " "; 
    printf("\n"); 
} 
  
void heapPermutation(int a[], int size, int n) 
{ 
    if (size == 1) 
    { 
        printArr(a, n); 
        return; 
    } 
  
    for (int i=0; i<size; i++) 
    { 
        heapPermutation(a,size-1,n); 
        if (size%2==1) 
            swap(a[0], a[size-1]); 
        else
            swap(a[i], a[size-1]); 
    } 
} 
  
int main() 
{ 
    int a[] = {1, 2, 3}; 
    int n = sizeof a/sizeof a[0]; 
    heapPermutation(a, n, n); 
    return 0; 
} 
// Complexity : O(!n)
