# Suffix Array

Prefix and Suffix of a string

let the string is abbab

| Prefixes | Suffixes|
|---|---|
|#|abbab|
|a|bbab|
|ab|bab|
|abb|ab|
|abba|b|
|abbab|#|

For our purpose, we will consider # is empty string

So, for length n = 5, we generate 6 suffixes

Remember: 6 suffixes of different lengths

Let S = abracadabra (length = 11)

1- Generate 12 suffixes
2- Sort based on string (alphabetically)
3- The new indices ordering is called **suffix array**

|Suffixes|Suffix Array|
|---|---|
| (0) abracadabra | (11) #|
| (1) bracadabra  | (10) a|
| (2) racadabra | (7) abra|
| (3) acadabra | (0) abracadabra|
| (4) cadabra | (3) acadabra|
| (5) adabra  | (5) adabra|
| (6) dabra  | (8) bra |
| (7) abra | (1) bracadabra  |
| (8) bra | (4) cadabra |
| (9) ra  | (6) dabra  |
| (10) a  | (9) ra  | 
| (11) #  | (2) racadabra |

int suffix_array[] = {11,10, 7, 0, 3, 5, 8, 1, 4, 6, 9, 2}
