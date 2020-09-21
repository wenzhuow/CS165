#include "graph.h"
#include "project3.h"
#ifndef GRAPH_C
#define GRAPH_C

int Graph::get_num_nodes()
{
	return num_nodes;
}

int Graph::get_num_edges()
{
	return num_edges;
}

Graph::Graph()
{
    num_nodes=0;
    num_edges=0;
}
void Graph::add_edge(int start,int end)
{
	edges[start].insert(end);
	edges[end].insert(start);
	// int s = min(start,end);
	// int e = max(start,end);

	// int k = hashfunc(s);
	// vector<pair<int,int>> temp = edges[k];
	// if (! contain(temp,s,e))
	// 	temp.push_back(make_pair(s,e));
}

bool Graph::is_neighbor(Node u, Node v) 
{
	return edges[u.id].count(v.id)>0;
	// int s=min(u.id,v.id);
	// int e=max(u.id,v.id);
	
	// int k = hashfunc(s);
	// vector<pair<int,int> temp = edges[k];
	// return contain(temp,s,e);

}

vector<Node> Graph::get_neighbors(Node u)
{
	vector<Node> v;
	for (int i:edges[u.id])
	{
		v.push_back(Node(i));
	}
	return v;
}

map<int, Node> Graph::get_id_to_node_map()
{
	map<int, Node> m;
	for (int i=1;i<=num_nodes;i++)
	{
		m[i] = Node(i);
		cout<<i<<" "<<m[i].id<<endl;
	}
	return m;
}

Graph make_graph(int num_nodes, vector<int> u, vector<int> v)
{
	Graph g = Graph();
	g.num_nodes = num_nodes;
	g.num_edges = u.size();
	for (int i=0;i<g.num_edges;i++)
		g.add_edge(u[i],v[i]);
	return g;
}



#endif