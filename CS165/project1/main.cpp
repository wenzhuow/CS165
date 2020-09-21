#include "annealing_sort.cpp"
#include "bubble_sort.cpp"
#include "insertion_sort.cpp"
#include "shell_sort.cpp"
#include "spin_the_bottle_sort.cpp"

#include "helper.cpp"


timing timing_bubble_sort(int n, int reps)
{
    double total_time = 0.0;
    vector<int> rvec;
    for(int i = 0; i < reps; i++)
    {
        rvec = get_random_shuffled_int_vector(n);
        clock_t c_start = clock();
        bubble_sort(rvec);
        clock_t c_end = clock();
        total_time += (float)(c_end - c_start) / CLOCKS_PER_SEC;
    }
    timing t;
    t.n = n;
    t.seconds = (float)total_time/reps;
    return t;
}

timing timing_insertion_sort(int n, int reps)
{
    double total_time = 0.0;
    vector<int> rvec;
    for(int i = 0; i < reps; i++)
    {
        rvec = get_random_shuffled_int_vector(n);
        clock_t c_start = clock();
        insertion_sort(rvec);
        clock_t c_end = clock();
        total_time += (float)(c_end - c_start) / CLOCKS_PER_SEC;
    }
    timing t;
    t.n = n;
    t.seconds = (float)total_time/reps;
    return t;
}


timing timing_spin_sort(int n, int reps)
{
    double total_time = 0.0;
    vector<int> rvec;
    for(int i = 0; i < reps; i++)
    {
        rvec = get_random_shuffled_int_vector(n);
        clock_t c_start = clock();
        spin_the_bottle_sort(rvec);
        clock_t c_end = clock();
        total_time += (float)(c_end - c_start) / CLOCKS_PER_SEC;
    }
    timing t;
    t.n = n;
    t.seconds = (float)total_time/reps;
    return t;
}

timing timing_shell_sort(int n, int reps, vector<int> gaps)
{
    double total_time = 0.0;
    vector<int> rvec;
    for(int i = 0; i < reps; i++)
    {
        rvec = get_random_shuffled_int_vector(n);
        clock_t c_start = clock();

        shell_sort(rvec,gaps);
        clock_t c_end = clock();
        total_time += (float)(c_end - c_start) / CLOCKS_PER_SEC;
    }
    timing t;
    t.n = n;
    t.seconds = (float)total_time/reps;
    return t;
}


timing timing_annealing_sort(int n, int reps, vector<int>& temps, vector<int>& r)
{
    double total_time = 0.0;
    vector<int> rvec;
    for(int i = 0; i < reps; i++)
    {
        rvec = get_random_shuffled_int_vector(n);
        clock_t c_start = clock();
        annealing_sort(rvec,temps,r);
        clock_t c_end = clock();
        total_time += (float)(c_end - c_start) / CLOCKS_PER_SEC;
    }
    timing t;
    t.n = n;
    t.seconds = (float)total_time/reps;
    return t;
}


timing timing_bubble_sort_almost_sorted(int n, int reps)
{
    double total_time = 0.0;
    vector<int> rvec;
    for(int i = 0; i < reps; i++)
    {
        rvec = get_almost_sorted_int_vector(n);
        clock_t c_start = clock();
        bubble_sort(rvec);
        clock_t c_end = clock();
        total_time += (float)(c_end - c_start) / CLOCKS_PER_SEC;
    }
    timing t;
    t.n = n;
    t.seconds = (float)total_time/reps;
    return t;
}

timing timing_insertion_sort_almost_sorted(int n, int reps)
{
    double total_time = 0.0;
    vector<int> rvec;
    for(int i = 0; i < reps; i++)
    {
        rvec = get_almost_sorted_int_vector(n);
        clock_t c_start = clock();
        insertion_sort(rvec);
        clock_t c_end = clock();
        total_time += (float)(c_end - c_start) / CLOCKS_PER_SEC;
    }
    timing t;
    t.n = n;
    t.seconds = (float)total_time/reps;
    return t;
}


timing timing_spin_sort_almost_sorted(int n, int reps)
{
    double total_time = 0.0;
    vector<int> rvec;
    for(int i = 0; i < reps; i++)
    {
        rvec = get_almost_sorted_int_vector(n);
        clock_t c_start = clock();
        spin_the_bottle_sort(rvec);
        clock_t c_end = clock();
        total_time += (float)(c_end - c_start) / CLOCKS_PER_SEC;
    }
    timing t;
    t.n = n;
    t.seconds = (float)total_time/reps;
    return t;
}

timing timing_shell_sort_almost_sorted(int n, int reps, vector<int> gaps)
{
    double total_time = 0.0;
    vector<int> rvec;
    for(int i = 0; i < reps; i++)
    {
        rvec = get_almost_sorted_int_vector(n);
        clock_t c_start = clock();
        shell_sort(rvec,gaps);
        clock_t c_end = clock();
        total_time += (float)(c_end - c_start) / CLOCKS_PER_SEC;
    }
    timing t;
    t.n = n;
    t.seconds = (float)total_time/reps;
    return t;
}


timing timing_annealing_sort_almost_sorted(int n, int reps, vector<int>& temps, vector<int>& r)
{
    double total_time = 0.0;
    vector<int> rvec;
    for(int i = 0; i < reps; i++)
    {
        rvec = get_almost_sorted_int_vector(n);
        clock_t c_start = clock();
        annealing_sort(rvec,temps,r);
        clock_t c_end = clock();
        total_time += (float)(c_end - c_start) / CLOCKS_PER_SEC;
    }
    timing t;
    t.n = n;
    t.seconds = (float)total_time/reps;
    return t;
}

int main() 
{ 
    create_empty_timings_file("timings_of_uniformly_distributed.csv");
    timing t;
    for(int n = 10; n <= 100000; n *= 10)
    {
        t = timing_bubble_sort(n, 3);
        add_timings_to_file("bubble_sort", t, "timings_of_uniformly_distributed.csv");
    }
    for(int n = 10; n <= 100000; n *= 10)
    {
        t = timing_insertion_sort(n, 3);
        add_timings_to_file("insertion_sort", t, "timings_of_uniformly_distributed.csv");
    }
    for(int n = 10; n <= 10000; n *= 10)
    {
        t = timing_spin_sort(n, 3);
        add_timings_to_file("spin_the_bottle_sort", t, "timings_of_uniformly_distributed.csv");
    }
    for(int n = 10; n <= 10000000; n *= 10)
    {
    	vector<int> gaps;
    	for (int i=n/2;i>0;i/=2)
    		gaps.push_back(i);
        t = timing_shell_sort(n, 3, gaps);
        add_timings_to_file("shell_sort 1", t, "timings_of_uniformly_distributed.csv");
    }
    for(int n = 10; n <= 10000000; n *= 10)
    {
    	vector<int> gaps;
    	for (int i=1;i<n;i*=2.25)
    		gaps.insert(gaps.begin(),i);
        t = timing_shell_sort(n, 3, gaps);
        add_timings_to_file("shell_sort 2", t, "timings_of_uniformly_distributed.csv");
    }
    for(int n = 10; n <= 1000000; n *= 10)
    {
    	vector<int> temps;
    	for (int i=2*n;i>0;i/=2)
    		temps.push_back(i);
 		temps.push_back(0);
    	vector<int> reps;
    	for (int i=temps.size();i>0;i--)
    		reps.push_back(4);

        t = timing_annealing_sort(n, 3, temps , reps);
        add_timings_to_file("annealing_sort 1", t, "timings_of_uniformly_distributed.csv");
    }
    for(int n = 10; n <= 1000000; n *= 10)
    {
    	vector<int> temps;
    	for (int i=pow(log(n),6);i>0;i/=2)
    		temps.push_back(i);
 		temps.push_back(0);
    	vector<int> reps;
    	for (int i=temps.size();i>0;i--)
    		reps.push_back(4);

        t = timing_annealing_sort(n, 3, temps , reps);
        add_timings_to_file("annealing_sort 2", t, "timings_of_uniformly_distributed.csv");
    }


	create_empty_timings_file("timings_of_almost_sorted.csv");
    timing t1;
    for(int n = 10; n <= 100000; n *= 10)
    {
        t1 = timing_bubble_sort_almost_sorted(n, 3);
        add_timings_to_file("bubble_sort", t1, "timings_of_almost_sorted.csv");
    }
    for(int n = 10; n <= 10000000; n *= 10)
    {
        t1 = timing_insertion_sort_almost_sorted(n, 3);
        add_timings_to_file("insertion_sort", t1, "timings_of_almost_sorted.csv");
    }
    for(int n = 10; n <= 10000; n *= 10)
    {
        t1 = timing_spin_sort_almost_sorted(n, 3);
        add_timings_to_file("spin_the_bottle_sort", t1, "timings_of_almost_sorted.csv");
    }
    for(int n = 10; n <= 10000000; n *= 10)
    {
    	vector<int> gaps;
    	for (int i=n/2;i>0;i/=2)
    		gaps.push_back(i);
        t1 = timing_shell_sort_almost_sorted(n, 3, gaps);
        add_timings_to_file("shell_sort 1", t1, "timings_of_almost_sorted.csv");
    }
    for(int n = 10; n <= 10000000; n *= 10)
    {
    	vector<int> gaps;
    	for (int i=1;i<n;i*=2.25)
    		gaps.insert(gaps.begin(),i);
        t1 = timing_shell_sort_almost_sorted(n, 3, gaps);
        add_timings_to_file("shell_sort 2", t1, "timings_of_almost_sorted.csv");
    }
    for(int n = 10; n <= 1000000; n *= 10)
    {
    	vector<int> temps;
    	for (int i=2*n;i>0;i/=2)
    		temps.push_back(i);
 		temps.push_back(0);
    	vector<int> reps;
    	for (int i=temps.size();i>0;i--)
    		reps.push_back(4);

        t1 = timing_annealing_sort_almost_sorted(n, 3, temps , reps);
        add_timings_to_file("annealing_sort 1", t1, "timings_of_almost_sorted.csv");
    }
    for(int n = 10; n <= 1000000; n *= 10)
    {
    	vector<int> temps;
    	for (int i=pow(log(n),6);i>0;i/=2)
    		temps.push_back(i);
 		temps.push_back(0);
    	vector<int> reps;
    	for (int i=temps.size();i>0;i--)
    		reps.push_back(4);
        t1 = timing_annealing_sort_almost_sorted(n, 3, temps , reps);
        add_timings_to_file("annealing_sort 2", t1, "timings_of_almost_sorted.csv");
    }


    return 0; 
} 