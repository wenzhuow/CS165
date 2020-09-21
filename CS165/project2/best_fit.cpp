using namespace std;
#include <iostream>
#include "helper_best.cpp"
#include "helper.cpp"




void best_fit(const vector<double>& items, vector<int>& assignment, vector<double>& free_space)
{
	for (int i=0;i<items.size();i++)
	{
		bool find=false;
		int best = -1;
		for (int j=0;j<free_space.size();j++)
			if (free_space[j]>=items[i])
			{
				if (best==-1 || free_space[j]<free_space[best])
				{
					best = j;
					find = true;
				}
			}
		if (find)
		{
			assignment[i]=best;
			free_space[best]-=items[i];
		}
		else
		{
			free_space.push_back(1.0-items[i]);
			assignment[i]=free_space.size()-1;
		}
	}

}


void best_fit_decreasing(const vector<double>& items, vector<int>& assignment, vector<double>& free_space)
{
	vector<pair<double,int>> new_items;
	for (int i=0;i<items.size();i++)
	{
		new_items.push_back(make_pair(items[i],i));
	}
	sort(new_items.begin(), new_items.end(),sortinrev);


	for (int i=0;i<new_items.size();i++)
	{
		bool find=false;
		int best = -1;
		for (int j=0;j<free_space.size();j++)
			if (free_space[j]>=new_items[i].first)
			{
				if (best==-1 || free_space[j] < free_space[best])
				{
					best = j;
					find = true;
				}
			}
		if (find)
		{
			assignment[new_items[i].second]=best;
			free_space[best]-=new_items[i].first;
		}
		else
		{
			free_space.push_back(1.0-new_items[i].first);
			assignment[new_items[i].second]=free_space.size()-1;
		}
	}






}