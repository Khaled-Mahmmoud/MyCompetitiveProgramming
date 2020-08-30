# Congruence Equations

`a ≡ b (mod n)`

called a and b congruent modulo n

- It means a%n = b%n = x,

- this means (a-b)%n = 0 and (b-a)%n = 0

- a = b+qn for some q integer (a-b = qn)

Note that a ≡ 0 (mod m) if and only if m | a . Thus, modular arithmetic gives you another way of dealing with divisibility relations. Another way of saying this is: Mod m any multiple of m is 0.

Example.

(a) Reduce 101 (mod 3) to a number in the range {0, 1, 2}.

(b) Reduce -101 (mod 3) to a number in the range {0, 1, 2}.

(a) 101 = 2 (mod 3) , because 3 | 101 - 2 = 99.

(b) -101 = 1 (mod 3) , because 3 | -101 - 1 = -102 .



### Congruence Facts

- If ax ≡ ay (mod n) and gcd(a,n) = d, then the congruence is equivalent x ≡ y (mod n/d)

- If ax ≡ ay (mod n) SAME as x ≡ y (mod n) THEN d = 1, Reverse doesn’t need this condition.

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
