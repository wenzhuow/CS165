#include "AVLTree.hpp"
#include "project2.h"
#include "next_fit.cpp"
#include "first_fit_optimized.cpp"
#include "best_fit_optimized.cpp"
#include "helper.cpp"

// #include "first_fit.cpp"
// #include "best_fit.cpp"


int main()
{

	create_empty_space_file("free_space_of_uniformly_distributed.csv");

    uniform_real_distribution<double> unif(0, 1);
    mt19937 mt = get_mersenne_twister_generator_with_current_time_seed(); 

    for(int n = 10; n <= 1000; n *= 10)
    {
    	vector<double> items;
    	for (int i=0;i<n;i++)
    	{
    		items.push_back(unif(mt));
    	}

    	double space = 0.0;
    	vector<int> assignment1(items.size(), 0);
    	vector<double> free1;
    	next_fit(items,assignment1,free1);	
    	for (int s=0;s<free1.size();s++)
    		space+=free1[s];
    	add_space_to_file("next fit",n,space,"free_space_of_uniformly_distributed.csv");



    	vector<int> assignment2(items.size(), 0);
    	vector<double> free2;
    	first_fit(items,assignment2,free2);
    	space = 0.0;
    	for (int s=0;s<free2.size();s++)
    		space+=free2[s];
    	add_space_to_file("first fit",n,space,"free_space_of_uniformly_distributed.csv");


    	// vector<int> assignment21(items.size(), 0);
    	// free2.clear();
    	// first_fit1(items,assignment21,free2);
    	// space = 0.0;
    	// for (int s=0;s<free2.size();s++)
    	// 	space+=free2[s];
    	// add_space_to_file("first fit1",n,space,"free_space_of_uniformly_distributed.csv");




    	vector<int> assignment3(items.size(), 0);
    	vector<double> free3;	
    	first_fit_decreasing(items,assignment3,free3);
    	space = 0.0;
    	for (int s=0;s<free3.size();s++)
    		space+=free3[s];
    	add_space_to_file("first fit decreasing",n,space,"free_space_of_uniformly_distributed.csv");

    	
    	// vector<int> assignment31(items.size(), 0);
    	// free3.clear();	
    	// first_fit_decreasing1(items,assignment31,free3);
    	// space = 0.0;
    	// for (int s=0;s<free3.size();s++)
    	// 	space+=free3[s];
    	// add_space_to_file("first fit decreasing1",n,space,"free_space_of_uniformly_distributed.csv");




    	vector<int> assignment4(items.size(), 0);
    	vector<double> free4;
    	best_fit(items,assignment4,free4);
    	space = 0.0;
    	for (int s=0;s<free4.size();s++)
    		space+=free4[s];
    	add_space_to_file("best fit",n,space,"free_space_of_uniformly_distributed.csv");

    	
    	// vector<int> assignment41(items.size(), 0);
    	// free4.clear();
    	// best_fit1(items,assignment41,free4);
    	// space = 0.0;
    	// for (int s=0;s<free4.size();s++)
    	// 	space+=free4[s];
    	// add_space_to_file("best fit1",n,space,"free_space_of_uniformly_distributed.csv");




    	vector<int> assignment5(items.size(), 0);
    	vector<double> free5;	
    	best_fit_decreasing(items,assignment5,free5);
    	space = 0.0;
    	for (int s=0;s<free5.size();s++)
    		space+=free5[s];
    	add_space_to_file("best fit decreasing",n,space,"free_space_of_uniformly_distributed.csv");

    	
    	// vector<int> assignment51(items.size(), 0);
    	// free5.clear();	
    	// best_fit_decreasing1(items,assignment51,free5);
    	// space = 0.0;
    	// for (int s=0;s<free5.size();s++)
    	// 	space+=free5[s];
    	// add_space_to_file("best fit decreasing1",n,space,"free_space_of_uniformly_distributed.csv");


    	assignment1.clear();
    	assignment2.clear();
    	assignment3.clear();
    	assignment4.clear();
    	assignment5.clear();
    	free1.clear();	
    	free2.clear();	
    	free3.clear();	
    	free4.clear();	
    	free5.clear();	
    	items.clear();
    }
    return 0;
}