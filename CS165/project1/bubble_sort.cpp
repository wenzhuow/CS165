#include <stdio.h> 
#include "project1.h"
using namespace std; 
#ifndef bubble
#define bubble
#include "helper.cpp"

  
void bubble_sort(vector<int>& a)
{ 
   int i, j,n;
   n = a.size();
   for (i = 0; i < n-1; i++)         
       for (j = 0; j < n-i-1; j++)  
           if (a[j] > a[j+1]) 
              swap(&a[j], &a[j+1]); 
} 
  

#endif /* bubble */