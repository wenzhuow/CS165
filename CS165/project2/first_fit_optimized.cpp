using namespace std;
#include <iostream>
#include "helper_best.cpp"
#include "helper.cpp"


Node* find_first_fit(Node* tree,double value)
{
	Node *first = nullptr;
    Node *node = tree;
    while (node != nullptr && !first) 
    {
        double result = node->remain_cap - value;
        if (result >= 0)
        	first = node;
        else
        	node = node->right;
    }
    return first;
}

void first_fit(const vector<double>& items, vector<int>& assignment, vector<double>& free_space)
{
	Node * tree = nullptr;
	int space_used=-1;
	Node * found;
	for (int i=0;i<items.size();i++)
	{
		found = find_first_fit(tree,items[i]);
		if (found)
		{
			// cout<<"found "<<items[i]<<" "<<found->remain_cap<<endl;
			// found->remain_cap -= items[i];
			assignment[i] = found->index;
			free_space[found->index]-=items[i];
			tree = deleteNode(tree,found->remain_cap);
			tree = insert(tree,assignment[i],free_space[assignment[i]]);
			// found->remain_cap=free_space[found->index];
			//update(tree,found->index);
		}
		else
		{
			// cout<<"not found "<<items[i]<<endl;
			space_used++;
			assignment[i] = space_used;
			free_space.push_back(1 - items[i]);
			tree = insert(tree,space_used,free_space[space_used]);
			// preOrder(tree);
		}
	}
	clear_tree(tree);
}



void first_fit_decreasing(const vector<double>& items, vector<int>& assignment, vector<double>& free_space)
{
	vector<pair<double,int>> new_items;
	for (int i=0;i<items.size();i++)
	{
		new_items.push_back(make_pair(items[i],i));
	}
	sort(new_items.begin(), new_items.end(),sortinrev);

	Node * tree = nullptr;
	int space_used=-1;
	Node * found;
	for (int i=0;i<new_items.size();i++)
	{
		found = find_first_fit(tree,new_items[i].first);
		if (found)
		{
			// cout<<"found "<<items[i]<<endl;
			// found->remain_cap -= new_items[i].first;
			assignment[new_items[i].second] = found->index;
			free_space[found->index]-=new_items[i].first;
			tree = deleteNode(tree,found->remain_cap);
			tree = insert(tree,assignment[new_items[i].second],free_space[assignment[new_items[i].second]]);
		
			// found->remain_cap=free_space[found->index];
			//update(tree,found->index);
		}
		else
		{
			//cout<<"not found "<<items[i]<<endl;
			space_used++;
			assignment[new_items[i].second] = space_used;
			free_space.push_back(1 - new_items[i].first);
			tree = insert(tree,space_used,free_space[space_used]);
			// preOrder(tree);
		}
	}
	clear_tree(tree);
}