#ifndef helper
#define helper


#include <iostream>
#include <chrono>
#include <random>
#include <vector>
using namespace std;

#include <fstream>
#include <algorithm>
#include <ctime>
#include <math.h>

void swap(int *left, int *right) 
{ 
    int temp = *left; 
    *left = *right; 
    *right = temp; 
}

mt19937 get_mersenne_twister_generator_with_current_time_seed()
{
    unsigned seed = chrono::system_clock::now().time_since_epoch().count();
    return mt19937(seed);
}

void print_mt_random_numbers(mt19937 mt, int n)
{
    for(int i = 0; i < n; i++)
        cout << mt() << "\n";
}

uniform_int_distribution<int> get_uniform_int_generator(int lb, int ub)
{
    return uniform_int_distribution<int>(lb, ub);
}


struct timing 
{
    int n;
    double seconds;
};

// get a vector of ints in 1, 2, ... , n shuffled randomly
vector<int> get_random_shuffled_int_vector(int n)
{
    vector<int> vec = vector<int>(n);
    for(int i = 0; i < n; i++)
        vec[i] = (i + 1);
    random_shuffle(vec.begin(), vec.end());
    return vec;
}

void shuffle_vector(vector<int>& nums)
{
	int n = nums.size();
    mt19937 mt = get_mersenne_twister_generator_with_current_time_seed();
    uniform_int_distribution<int> ran =  get_uniform_int_generator(0,n-1);
    n = 2*log(n);
    for (int k=0;k<n;k++)
    {
    	int i = ran(mt);
        int j = ran(mt);
        swap(&nums[i],&nums[j]);
    }
}

vector<int> get_almost_sorted_int_vector(int n)
{
    vector<int> vec = vector<int>(n);
    for(int i = 0; i < n; i++)
        vec[i] = (i + 1);
    shuffle_vector(vec);
    return vec;
}

void create_empty_timings_file(string filename)
{
    ofstream f;
    f.open(filename, ios::trunc);
    f << "funcname,number of int,total seconds\n";
    f.close();
}

void add_timings_to_file(string funcname, timing t, string filename)
{
    ofstream f;
    f.open(filename, ios::app);
    f << funcname << "," << t.n << "," << t.seconds << "\n";
    f.close();
}




#endif /* helper */