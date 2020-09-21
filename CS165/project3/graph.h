using namespace std;
#include "node.h"
#include "helper.cpp"
#ifndef GRAPH_H
#define GRAPH_H

class Graph : public AbstractGraph
{
    public: // all methods must be overriden
    	int num_nodes;
    	int num_edges;
    	set<int> nodes;
    	map<int,set<int>> edges;

    	Graph();

    	void add_edge(int start,int end);
        int get_num_nodes(); // number of nodes
        int get_num_edges(); // number of edges
        bool is_neighbor(Node u, Node v);
        vector<Node> get_neighbors(Node u); 

        // allows lookup of nodes from ids
        map<int, Node> get_id_to_node_map();
};



#endif