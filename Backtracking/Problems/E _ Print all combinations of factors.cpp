/*

Print all combinations of factors (Ways to factorize)
Write a program to print all the combinations of factors of given number n.

Input : 16
Output :2 2 2 2 
        2 2 4 
        2 8 
        4 4 

Input : 12
Output : 2 2 3
         2 6
         3 4

To solve this problem we take one array of array of integers or list of list of integers to store 
all the factors combination possible for the given n. So , to achieve this we can have one 
recursive function which can store the factors combination in each of its iteration
And each of those list should be stored in the final result list
*/


vector<vector<int>>resultant; 
void factorsListFunc (int first, int each_prod, int n, vector<int>single_result_list)  
{  
    if (first> n || each_prod > n)  
        return;   
    if (each_prod == n)  
    {  
        resultant.push_back(single_result_list);  
        return;  
    }  
    for (int i = first; i < n; i++)  
    {  
        if (i * each_prod > n)  
            break;  
        if (n % i == 0)  
        {  
            single_result_list.push_back(i);   
            factorsListFunc(i, i * each_prod, n, single_result_list);  
            single_result_list.pop_back();  
        }  
    }  
}  
void factComb(int n)  
{   
    vector<int>single_result_list; 
    factorsListFunc(2, 1, n, single_result_list);  
}  
int main() 
{ 
    int n = 16;  
    factComb(n);  
    for (int i = 0; i < resultant.size(); i++) 
    {  
        for (int j = 0; j < resultant[i].size(); j++)  
            cout << resultant[i][j] << " ";  
        cout << endl; 
    } 
    return 0; 
}   
