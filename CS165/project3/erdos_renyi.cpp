#include "graph.cpp"


Graph create_erdos_renyi_graph(int n, float p)
{
	vector<int> s;
	vector<int> e;
	int v=2;
	int w=0;
	uniform_real_distribution<double> unif(0, 1);
    mt19937 mt = get_mersenne_twister_generator_with_current_time_seed(); 
	while (v<=n)
	{
		double r = unif(mt);
		while (r==1.0)
			r = unif(mt);
		w = w+1+(log(1-r)/log(1-p));
		while((w>=v) && (v<=n))
		{
			w=w-v;
			v=v+1;
		}
		if (v<=n && v!=0 && w!=0)
		{
			s.push_back(v);
			e.push_back(w);
		}
	}
	return make_graph(n,s,e);
}