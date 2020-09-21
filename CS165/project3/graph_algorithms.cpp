#include "graph.h"
#include <list>
#include <queue>


pair<int,int> travese(Node r,Graph g)
{
	int a[g.num_nodes+1];
	for (int q=0;q<=g.num_nodes;q++)
		a[q]=-1;

	a[r.id]=0;
	queue<Node> l;
	l.push(r);
	int max=0;
	int max_node;
	while(l.size()>0)
	{

		Node temp = l.front();
		// cout<<"pop "<<temp.id<<endl;
		l.pop();
		for (Node n:g.get_neighbors(temp))
		{
			// cout<<"find "<<n.id<<" "<<a[n.id]<<endl;
			if (a[n.id]==-1)
			{
				// cout<<n.id<<endl;
				a[n.id]=1+a[temp.id];
				l.push(n);
				if (max<a[n.id])
				{
					max=a[n.id];
					max_node = n.id;
				}
			}
		}
	}
	return make_pair(max,max_node);
}


int get_diameter(Graph g)
{
	int d=0;
	uniform_int_distribution<int> unif(1,g.num_nodes);
    mt19937 mt = get_mersenne_twister_generator_with_current_time_seed();
    
    int r = unif(mt);
    for (int i=0;i<5;i++)
    {
    	// cout<<"i "<<i<<endl;
    	pair<int,int> temp = travese(Node(r),g);
    	if (temp.first>d)
    	{
    		d=temp.first;
    	}
    	r = temp.second;
    }
    return d;
}

// list<Node> degeneracy_order(Graph g)
// {
// 	list<Node> l;
// 	int d[g.num_nodes+1];
// 	int a[g.num_nodes+1] = {0};
// 	list<Node> D[g.num_nodes+1];
// 	for (int i=1;i<=g.num_nodes;i++)
// 	{
// 		D[g.get_neighbors(Node(i)).size()].push_back(Node(i));
// 		d[i]=g.get_neighbors(Node(i)).size();
// 	}
// 	vector<Node> N[g.num_nodes+1];
// 	int i = 1;
// 	for (int i=0;i<g.num_nodes;i++)
// 	{
// 		Node v = D[i].back();
// 		D[i].pop_back();
// 		if (D[i].size()==0)
// 			i++;
// 		l.push_front(v);
// 		a[v.id]=1;
// 		for (Node w:g.get_neighbors(v))
// 		{
// 			if (a[w.id]==0)
// 			{
// 				d[w.id]-=1;
// 				D[g.get_neighbors(w).size()].remove(w);
// 				D[g.get_neighbors(w).size()].push_back(w);
// 				N[v.id].push_back(w);
// 			}
// 		}
// 	}
// 	return l;
// }

float get_clustering_coefficient(Graph g)
{
	int den = 0;
	for (int i=1;i<=g.num_nodes;i++)
	{
		int degr = g.get_neighbors(Node(i)).size();
		int temp_den = degr*(degr-1)/2;
		den+=temp_den;
	}
	int tri=0;

	int thi=0;
	
	list<Node> l;
	int d[g.num_nodes+1];
	int a[g.num_nodes+1];
	list<Node> D[g.num_nodes+1];
	for (int i=1;i<=g.num_nodes;i++)
	{
		D[g.get_neighbors(Node(i)).size()].push_back(Node(i));
		d[i]=g.get_neighbors(Node(i)).size();
		a[i]=0;
		if (g.get_neighbors(Node(i)).size()>thi)
			thi=g.get_neighbors(Node(i)).size();
	}
	vector<Node> N[g.num_nodes+1];

	for (int q=0;q<g.num_nodes;q++)
	{
		int i=0;
		// cout<<"size "<<i<<" "<<D[i].size()<<endl;
		while (D[i].size()==0)
			i++;
		// cout<<"size "<<i<<" "<<D[i].size()<<endl;
		Node v = D[i].back();
		D[i].pop_back();
		
		l.push_front(v);

		// cout<<"length "<<l.size()<<endl;

		a[v.id]=1;
		// cout<<"           mark "<<v.id<<" "<<g.get_neighbors(v).size()<<endl;
		for (Node w:g.get_neighbors(v))
		{
			// cout<<"    loop "<<w.id<<endl;
			if (a[w.id]==0)
			{
				// cout<<w.id<<" "<<d[w.id]<<endl;
				d[w.id]-=1;
				// cout<<"now "<<d[w.id]<<endl;
				D[d[w.id]+1].remove(w);
				D[d[w.id]].push_back(w);
				// cout<<333<<endl;
				N[v.id].push_back(w);
				// cout<<444<<endl;
			}
		}
	}

	// cout<<"2 "<<tri<<endl;

	for (Node nv:l)
	{
		for (int i=0;i<N[nv.id].size();i++)
		{
			for (int j=i+1;j<N[nv.id].size();j++)
			{
				if (g.is_neighbor(N[nv.id][i],N[nv.id][j]))
				{
					tri++;
				}
			}
		}
	}
	return 3.0*tri/den;


}



map<int, int> get_degree_distribution(Graph g)
{
	map<int, int> m;
	for(int i=1;i<=g.num_nodes;i++)
	{
		m[i]=g.get_neighbors(Node(i)).size();
	}
	return m;
}