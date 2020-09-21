#include "graph.cpp"



Graph create_barabasi_albert_graph(int n, int d)
{
	vector<int> s;
	vector<int> e;
	int M[2*n*d+1];
	mt19937 mt = get_mersenne_twister_generator_with_current_time_seed(); 
	for (int v=0;v<n;v++)
	{
		for(int i=0;i<d;i++)
		{
			M[2*(v*d+i)]=v;
			uniform_int_distribution<int> unif(0, 2*(v*d+i));
   	 		
			int r = unif(mt);
			M[2*(v*d+i)+1]=M[r];
		}
	}
	for(int i=0;i<n*d;i++)
	{
		if (M[2*i]!=0 && M[2*i+1]!=0)
		{
			s.push_back(M[2*i]);
			e.push_back(M[2*i+1]);
		}
	}
	return make_graph(n,s,e);
}