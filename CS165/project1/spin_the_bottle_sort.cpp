#include "project1.h"
using namespace std; 
#include "bubble_sort.cpp"
#include "helper.cpp"

bool check(vector<int>& a, int n)
{
	for (int i=0;i<n-1;i++)
	{
		if (a[i]>a[i+1])
			return false;
	}
	return true;
}
void spin_the_bottle_sort(vector<int>& a)
{
	int n = a.size()-1;
	bool f=false;
	mt19937 mt = get_mersenne_twister_generator_with_current_time_seed();
	uniform_int_distribution<int> k =  get_uniform_int_generator(0,n);
	while(!f)
	{
		for (int i=0;i<n;i++)
		{
			int s = k(mt);
			if((i<s && a[i]>a[s]) || (i>s && a[i]<a[s]))
			{
				swap(&a[i],&a[s]);
			}
		}
		if(check(a,n))
			f=true;
	}
}