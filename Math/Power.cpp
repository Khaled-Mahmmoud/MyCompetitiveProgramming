int power(int x, int y)
{
    if(!y)
        return 1;
    int t=power(x,y/2);
    t*=t;
    if(y&1)
        return x*t;
    return t;
}
