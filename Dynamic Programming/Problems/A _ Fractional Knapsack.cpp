/*
***************** Fractional Knapsack Problem *****************
Given weights and values of n items, we need to put these items in a knapsack of capacity W to get the maximum total value in
the knapsack

  Input:
  Items as (value, weight) pairs
  arr[] = {{60, 10}, {100, 20}, {120, 30}}
  Knapsack Capacity, W = 50;
  Output:
  Maximum possible value = 220
  by taking items of weight 20 and 30 kg
  
In Fractional Knapsack, we can break items for maximizing the total value of knapsack. This problem in which we can break an item is
also called the fractional knapsack problem

   Input : 
   Same as above
   Output :
   Maximum possible value = 240
   By taking full items of 10 kg, 20 kg and 
   2/3rd of last item of 30 kg
   
An efficient solution is to use Greedy approach. The basic idea of the greedy approach is to calculate the ratio value/weight for 
each item and sort the item on basis of this ratio. Then take the item with the highest ratio and add them until we can’t add the next 
item as a whole and at the end add the next item as much as we can. Which will always be the optimal solution to this problem

*/

#include <bits/stdc++.h>
#define ll long long
#define mod  1000000007
using namespace std;
struct item
{
    int value,weight;
    item(int value,int weight):value(value),weight(weight){}
};
bool cmp(struct item a,struct item b)
{
    double r1 = (double)a.value/a.weight;
    double r2 = (double)b.value/b.weight;
    return r1>r2;
    
}
double fraction(int w,struct item arr[],int n)
{
    sort(arr,arr+n,cmp);
    int curweight = 0;
    double finalvalue = 0.0;
    for(int i=0;i<n;i++)
    {
        if(curweight+arr[i].weight<=w)
        {
            curweight+=arr[i].weight;
            finalvalue+=arr[i].value;
        }
        else
        {
            double remain = w - curweight;
            finalvalue+= arr[i].value * (remain/arr[i].weight);
            break;
        }
    }
    return finalvalue;
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    int w = 50;
    item arr[] = {{60,10},{100,20},{120,30}};
    int n = sizeof(arr)/sizeof(arr[0]);
    cout<<fraction(w,arr,n);
    return 0;
}
