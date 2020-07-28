# Messenger

Given string is represented as a concatenation of n blocks, each block containing only equal characters.
One block may be described as a pair (li, ci), where li is the length of the i-th block and ci is the corresponding letter. 
Thus, the string s may be written as the sequence of pairs .

Your task is to write the program, that given two compressed string t and s finds all occurrences of s in t. Developers know that there may be many such occurrences, so they only ask you to find the number of them. 

Note that the way to represent the string in compressed form may not be unique. For example string "aaaa" may be given as [(4,a)] , [(3,a),(1,a)] , [(2,a),(2,a)]

**Input**

The first line of the input contains two integers n and m (1 ≤ n, m ≤ 200 000) — the number of blocks in the strings t and s, respectively.

The second line contains the descriptions of n parts of string t in the format " li- ci" (1 ≤ li ≤ 1 000 000) — the length of the i-th part and the corresponding lowercase English letter.

The second line contains the descriptions of m parts of string s in the format " li- ci" (1 ≤ li ≤ 1 000 000) — the length of the i-th part and the corresponding lowercase English letter.

**Output**

Print a single integer — the number of occurrences of s in t.

input

5 3

3-a 2-b 4-c 3-a 2-c

2-a 2-b 1-c

output

1

input

6 1

3-a 6-b 7-a 4-c 8-e 2-a

3-a

output

6

input

5 5

1-h 1-e 1-l 1-l 1-o

1-w 1-o 1-r 1-l 1-d

output

0

