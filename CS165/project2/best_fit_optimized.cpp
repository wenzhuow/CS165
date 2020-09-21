using namespace std;
#include <iostream>
#include "helper_best.cpp"
#include "helper.cpp"




Node* find_best_fit(Node* tree,double value)
{
	Node *best = nullptr;
    int found = 0;
    Node *node = tree;
    while (node != nullptr && !found) {
        double result = node->remain_cap - value;
        if (result > 0) {
        	
            if (best == nullptr || (node->remain_cap < best->remain_cap) ) 
            {
                best = node;
            }
            node = node->left;
        }
        else if (result < 0) {
            node = node->right;
        }
        else {
            best = node;
            found = 1;
        }
    }
    return best;
}

void best_fit(const vector<double>& items, vector<int>& assignment, vector<double>& free_space)
{
	Node * tree = nullptr;
	int space_used=-1;
	Node * found;

	// cout<<valgrind"start"<<endl;


	for (int i=0;i<items.size();i++)
	{
		found = find_best_fit(tree,items[i]);
		if (found)
		{
			//cout<<i<<" found "<<items[i]<<" "<<found->index<<" "<<found->remain_cap<<endl;

			assignment[i] = found->index;
			free_space[found->index]-=items[i];
			tree = deleteNode(tree,found->remain_cap);
			tree = insert(tree,assignment[i],free_space[assignment[i]]);
			//cout<<"found finish"<<endl;
		}
		else
		{
			//cout<<i<<" not found "<<items[i]<<endl;
			space_used++;
			assignment[i] = space_used;
			free_space.push_back(1 - items[i]);
			tree = insert(tree,space_used,free_space[space_used]);
			//cout<<"not found finish"<<endl;
		}
	}
	clear_tree(tree);
}



void best_fit_decreasing(const vector<double>& items, vector<int>& assignment, vector<double>& free_space)
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
		found = find_best_fit(tree,new_items[i].first);
		if (found)
		{
			// cout<<"found "<<items[i]<<endl;
			assignment[new_items[i].second] = found->index;
			free_space[found->index]-=new_items[i].first;


			tree = deleteNode(tree,found->remain_cap);
			tree = insert(tree,assignment[new_items[i].second],free_space[assignment[new_items[i].second]]);
		}
		else
		{
			// cout<<"not found "<<items[i]<<endl;
			space_used++;
			assignment[new_items[i].second] = space_used;
			free_space.push_back(1 - new_items[i].first);
			tree = insert(tree,space_used,free_space[space_used]);
		}
	}
	clear_tree(tree);
}