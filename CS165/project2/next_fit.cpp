using namespace std;


void next_fit(const vector<double>& items, vector<int>& assignment, vector<double>& free_space)
{
	int j=0;
	free_space.push_back(1);
	for (int i=0;i<items.size();i++)
	{
		if (items[i] > free_space[j])
		{
			j+=1;
			free_space.push_back(1-items[i]);
			assignment[i]=j;
		}
		else
		{
			assignment[i]=j;
			free_space[j]-=items[i];
		}
	}
}