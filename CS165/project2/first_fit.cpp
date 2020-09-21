using namespace std;
#include <iostream>
#include "helper.cpp"




void first_fit(const vector<double>& items, vector<int>& assignment, vector<double>& free_space)
{
	for (int i=0;i<items.size();i++)
	{
		bool find=false;
		for (int j=0;j<free_space.size();j++)
			if (free_space[j]>=items[i])
			{
				assignment[i]=j;
				free_space[j]-=items[i];
				find=true;
				break;
			}
		if (!find)
		{
			free_space.push_back(1.0-items[i]);
			assignment[i]=free_space.size()-1;
		}
	}
}


void first_fit_decreasing(const vector<double>& items, vector<int>& assignment, vector<double>& free_space)
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
		for (int j=0;j<free_space.size();j++)
			if (free_space[j]>=new_items[i].first)
			{
				assignment[new_items[i].second]=j;
				free_space[j]-=new_items[i].first;
				find=true;
				break;
			}
		if (!find)
		{
			free_space.push_back(1.0-new_items[i].first);
			assignment[new_items[i].second]=free_space.size()-1;
		}
	}
}