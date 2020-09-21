#include <math.h> 
#include <stdio.h> 
#include "project1.h"
using namespace std; 


void insertion_sort(std::vector<int>& a)
{ 
    int i, key, j, n; 
    n = a.size();
    for (i = 1; i < n; i++) { 
        key = a[i]; 
        j = i - 1; 
  

        while (j >= 0 && a[j] > key) { 
            a[j + 1] = a[j]; 
            j = j - 1; 
        } 
        a[j + 1] = key; 
    } 
} 
  