/*

Multiplicative order
In number theory, given an integer a and positive integer m with gcd(a , m) = 1
the multiplicative order of a modulo m is the smallest positive integer k with  (0 < K < m)

    a^x = 1  (mod m)

Input : a = 4 , m = 7 
Output : 3
explanation :  GCD(4, 7) = 1  
               a^x(mod m) = 1 ( smallest positive integer x )
               4^1 = 4(mod 7)  = 4
               4^2 = 16(mod 7) = 2
               4^3 = 64(mod 7)  = 1
               4^4 = 256(mod 7) = 4
               4^5 = 1024(mod 7)  = 2
               4^6 = 4096(mod 7)  = 1

smallest positive integer x = 3  

Input :  a = 3 , m = 1000 
Output : 100  (3^100 (mod 1000) == 1) 

Input : a = 4 , m = 11 
Output : 5 

If we take a close look then we observe that we do not need to calculate power every time
we can be obtaining next power by multiplying ‘a’ with the previous result of a mod m

Explanation : 
a = 4 , m = 11  
initially result = 1 
with normal                with modular arithmetic (a * result)
4^1 = 4 (mod 11 ) = 4  ||  4 * 1 = 4 (mod 11 ) = 4 [ result = 4]
4^2 = 16(mod 11 ) = 5  ||  4 * 4 = 16(mod 11 ) = 5 [ result = 5]
4^3 = 64(mod 11 ) = 9  ||  4 * 5 = 20(mod 11 ) = 9 [ result = 9]
4^4 = 256(mod 11 )= 3  ||  4 * 9 = 36(mod 11 ) = 3 [ result = 3]
4^5 = 1024(mod 5 ) = 1 ||  4 * 3 = 12(mod 11 ) = 1 [ result = 1]

smallest positive integer  5 
Run a loop from 1 to m-1 and Return the smallest +ve power of a under modulo n which is equal to 1

*/

int GCD ( int a , int b ) 
{ 
    if (b == 0 ) 
        return a; 
    return GCD( b , a%b ) ; 
} 
int multiplicativeOrder(int a, int  m) 
{ 
    if (GCD(a, m) != 1) 
        return -1; 
    int result = 1; 
    int x = 1 ; 
    while (x < m) 
    { 
        result = (result * a) % m ; 
        if (result  == 1) 
            return x; 
        x++; 
    } 
  
    return -1 ; 
} 
int main() 
{ 
    int a = 4 , m = 7; 
    cout << multiplicativeOrder(a, m); 
    return 0; 
} 

// Time Complexity: O(m)
