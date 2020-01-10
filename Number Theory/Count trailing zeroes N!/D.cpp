//Count number of trailing zeros in Binary representation of a number using Bitset
int CountTrailingZeros(int n) 
{ 
    bitset<64> bit; 
    bit |= n; 
    int cnt = 0; 
    for (int i = 0; i < 64; i++) 
        if (bit[i]) break; else cnt++;
    return cnt; 
} 
  
