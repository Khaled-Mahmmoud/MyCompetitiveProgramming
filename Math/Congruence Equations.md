# Congruence Equations

`a ≡ b (mod n)`

called a and b congruent modulo n, It means a%n = b%n = x, this means (a-b) % n = 0

57 ≡ 37 (mod 10) AND 57 - 37 = 20

57%10 = 37% 10 = 7, Also 20 % 10 = 0

More importantly: a = b+qn for some q integer (a-b = qn)

If ax ≡ ay (mod n) and gcd(a,n) = d, then the congruence is equivalent x ≡ y (mod n/d)

IF ax ≡ ay (mod n) SAME as x ≡ y (mod n) THEN d = 1, Reverse doesn’t need this condition.

### Congruence Facts

- IF a ≡ b (mod m)  a^n ≡ b^n (mod m) for all  n>= 1

- If p is prime , (x+y)^p ≡ x^p + y^p (mod p)

- If a ≡ b (mod m) and b ≡ c (mod m), then a ≡ c (mod m)

- If a ≡ b (mod m) and c ≡ d (mod m), then a + c ≡ b + d (mod m) OR a - c ≡ b - d (mod m)

- If a ≡ b (mod m) and c ≡ d (mod m), then ac ≡ bd (mod m) 

- IF a ≡ b (mod m)  a + c ≡ b + c (mod m) 

- IF a ≡ b (mod m)  ac ≡ bc (mod m) 

- From last one, ax ≡ b (mod n) same as x ≡ ba^-1 (mod n) 

### Find answer of 3^5555 % 80

Hint: Think how to reduce the large power?!

Hint: 3^4 ≡ 1 (% 80) and 5555 = 4 * 1388 + 3

Then, 3^5555 % 80 = 3^3 % 80 = 27

**Find answer of (3^1000 + 3) % 28**

Hint: 3^3 = 27 = -1 (% 28) and 1000 = 3*333+1

Then equation = [(-1 * 3) + 3] (% 28) = 0

prove that 2^(5n+1) + 5^(n+2) ≡ 0 (mod 27)
