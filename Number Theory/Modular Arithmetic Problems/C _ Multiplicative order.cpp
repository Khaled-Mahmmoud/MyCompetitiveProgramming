/*

Multiplicative order
In number theory, given an integer A and a positive integer N with gcd( A , N) = 1
the multiplicative order of a modulo N is the smallest positive integer k with A^k( mod N ) = 1 ( 0 < K < N )

Input : A = 4 , N = 7 
Output : 3
explanation :  GCD(4, 7) = 1  
               A^k( mod N ) = 1 ( smallest positive integer K )
               4^1 = 4(mod 7)  = 4
               4^2 = 16(mod 7) = 2
               4^3 = 64(mod 7)  = 1
               4^4 = 256(mod 7) = 4
               4^5 = 1024(mod 7)  = 2
               4^6 = 4096(mod 7)  = 1

smallest positive integer K = 3  

Input :  A = 3 , N = 1000 
Output : 100  (3^100 (mod 1000) == 1) 

Input : A = 4 , N = 11 
Output : 5 

IF we take a close look then we observe that we do not need to calculate power every time
we can be obtaining next power by multiplying ‘A’ with the previous result of a module  

Explanation : 
A = 4 , N = 11  
initially result = 1 
with normal                with modular arithmetic (A * result)
4^1 = 4 (mod 11 ) = 4  ||  4 * 1 = 4 (mod 11 ) = 4 [ result = 4]
4^2 = 16(mod 11 ) = 5  ||  4 * 4 = 16(mod 11 ) = 5 [ result = 5]
4^3 = 64(mod 11 ) = 9  ||  4 * 5 = 20(mod 11 ) = 9 [ result = 9]
4^4 = 256(mod 11 )= 3  ||  4 * 9 = 36(mod 11 ) = 3 [ result = 3]
4^5 = 1024(mod 5 ) = 1 ||  4 * 3 = 12(mod 11 ) = 1 [ result = 1]

smallest positive integer  5 
Run a loop from 1 to N-1 and Return the smallest +ve power of A under modulo n which is equal to 1

*/

int GCD ( int a , int b ) 
{ 
    if (b == 0 ) 
        return a; 
    return GCD( b , a%b ) ; 
} 
int multiplicativeOrder(int A, int  N) 
{ 
    if (GCD(A, N ) != 1) 
        return -1; 
    unsigned int result = 1; 
    int K = 1 ; 
    while (K < N) 
    { 
        result = (result * A) % N ; 
        if (result  == 1) 
            return K; 
        K++; 
    } 
  
    return -1 ; 
} 
int main() 
{ 
    int A = 4 , N = 7; 
    cout << multiplicativeOrder(A, N); 
    return 0; 
} 

// Time Complexity: O(N)
