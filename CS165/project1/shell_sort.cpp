#include  <iostream> 
using namespace std; 
#include "project1.h"


void shell_sort(vector<int>& a, const vector<int>& gaps)
{ 
    int n = a.size();
    for (int index=0;index<gaps.size();index++)
    {  
        int gap = gaps[index];
        for (int i = gap; i < n; i ++) 
        { 
            int temp = a[i]; 
            int j;             
            for (j = i; j >= gap && a[j - gap] > temp; j -= gap) 
                a[j] = a[j - gap]; 
            a[j] = temp; 
        }
    }
} 
