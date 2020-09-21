#include "project1.h"
using namespace std; 
#include "helper.cpp"

void annealing_sort(vector<int>& a, vector<int>& temps, vector<int>& reps)
{
	int t = temps.size();
	int n = a.size();
	mt19937 mt = get_mersenne_twister_generator_with_current_time_seed();
	uniform_int_distribution<int> ran;
	int s;
	for (int j=0;j<t-1;j++)
	{
		for (int i=0;i<n-1;i++)
		{
			ran = get_uniform_int_generator(i+1,min(n-1,i+temps[j]));
			for (int k = 1;k<=reps[j];k++)
			{	
				s= ran(mt);
				if (a[i]>a[s])
					swap(&a[i],&a[s]);
			}
		}
		for (int i=n-1;i>0;i--)
		{
			ran = get_uniform_int_generator(max(0,i-temps[j]),i-1);
			for (int k = 1;k<=reps[j];k++)
			{
				s= ran(mt);
				if (a[s]>a[i])
					swap(&a[i],&a[s]);
			}
		}
	}
}