```
   1010101100
   |        |
   V        V
  most     least
 significant bit
 
 
A number N in base or radix b can be written as:
(N)b = dn-1 dn-2 — — — — d1 d0 . d-1 d-2 — — — — d-m

In the above, dn-1 to d0 is integer part, then follows a radix point, and then d-1 to d-m is fractional part

dn-1 = Most significant bit (MSB)

d-m = Least significant bit (LSB)

Representation             Base/Radix        numbers
Binary                         2           0   1
Octal                          8           0 1 2 3 4 5 6 7
Decimal                        10          0 1 2 3 4 5 6 7 8 9
Hexadecimal                    16          0 1 2 3 4 5 6 7 8 9 A B C D E F

How to convert a number from one base to another?

************************ Binary to Octal ***********************
(11101010.101110011)2 = (011 101 010 . 101 110 011)2 = (352.563)8
(1101.10)2 = ( 001 101 . 100)2 = (15.4)

************************ Octal to Binary ***********************
(352.563)8 = (011 101 010 . 101 110 011)2 = (11101010.101110011)2

************************ Binary to Decimal  ***********************
(1010.01)2 = ( ? )10
1*2^3 + 0*2^2 + 1*2^1+ 0*2^0 +      0*2^-1 + 1×2*-2 = 8+0+2+0+    0+0.25 = 10.25
(1010.01)2 = (10.25)10

************************ Decimal to Binary ***********************
(28.125)10 = ( ? )2
2   |   28            ٨
2   |   14     0      |
2   |   7      0      |
2   |   3      1      |
2   |   1      1      |
2   |   0      1      |
(28)10 = (11100)2
0.125*2 = 0.250     0    |
0.250*2 = 0.500     0    |
0.500*2 = 1.000     1    V
(0.125)10 = (0.001)2
(28.125)10 = (11100.001)2

************************ Binary to Hexadecimal ***********************
(1001110110110010.1011000001)2 = (1001 1101 1011 0010.10 1100 0001)2 = (9DB2.2C1)16
(11.10101)2 = ( 0011 . 1010 1000)2 = (3.A8)

************************ Hexadecimal to Binary ***********************
(9DB2.2C1)16 = (1001 1101 1011 0010.10 1100 0001)2 = (1001110110110010.1011000001)2
                                     ^-> Notice
                                     
************************  Octal to Decimal ***********************
(12.2)8 = ( ? )10
1 * 8^1 + 2 * 8^0 +      2 * 8^-1 = 8+2+0.25 = 10.25
(12.2)8 = (10.25)10

************************  Decimal to Octal  ***********************
(10.65)10 = ( ? )8
8   |   10           ٨
8   |   1     2      |
8   |   0     1      |
(10)10 = (12)8
0.25 x 8 = 2.00
Note : Keep multiplying the fractional part with 8 until decimal part .00 is obtained
(.25)10 = (.2)8
(10.25)10 = (12.2)8

FOR (0.65)10 = (?)8
0.65 * 8 = 5.20    5    |
0.20 * 8 = 1.60    1    |
0.60 * 8 = 4.80    4    |
0.80 * 8 = 6.40    6    V
and continue

************************ Octal to Hexadecimal ***********************
(352.563)8 = ( ? )16
first , we convert Octal to binary then convert binary to Hexadecimal
(352.563)8 = (011 101 010 . 101 110 011)2 = ( 1110 1010 . 1011 1001 1000)2 = (EA.B98)16

************************ Hexadecimal to Octal  ***********************
(EA.B98)16 = ( ? )8
first , we covert Hexadecimal to binary then convert binary to Octal
(EA.B98)16 = ( 1110 1010 . 1011 1001 1000)2 = (011 101 010 . 101 110 011)2 = (352.563)8

************************ Decimal to Hexadecimal ***********************
(720.046875)10 = ( ? )16
16   |   720           ٨
16   |   45     0      |
16   |   2      D      |
16   |   0      2      |
(720)10 = (2D0)16
0.046875 * 16  = 0.75     0    | 
0.75 * 16      = 12.00    C    V
Note : Keep multiplying the fractional part with 16 until decimal part .00 is obtained
(.046875)10 = (.0C)16
(720.0625)10 = ( 2D0.0C )16

For (0.659)10 = (?)16
0.659 *  16 = 10.544    A    |
0.544 *  16 = 8.704     8    |
0.704 *  16 = 11.264    B    |
0.264 *  16 = 4.422     4    V
and continue

************************ Hexadecimal to Decimal ***********************
(9FA.E6)16 = ( ? )10
9 * 16^2 + F * 16^1 + A * 16^0 +     E * 16^-1 + 6 * 16^-2 = 57892.843
(9FA.E6)16 = ( 57892.843 )10
```
