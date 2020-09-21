#include <set>
#include <list>
#include <map>
#include <iostream>
#include <chrono>
#include <random>
#include <vector>
using namespace std;

#include <fstream>
#include <algorithm>

#include "tests.h"
#include "graph_algorithms.cpp"
#include "erdos_renyi.cpp"
// #include "barabasi_albert.cpp"
#include <math.h>


void create_empty_space_file(string filename)
{
    ofstream f;
    f.open(filename, ios::trunc);
    f << "num, diameter, coefficient\n";
    f.close();
}
void add_space_to_file(int num, int diameter, float coefficient,string filename)
{
    ofstream f;
    f.open(filename, ios::app);
    f << num << "," << diameter << "," << coefficient << "\n";
    f.close();
}
void create_empty_space_file1(string filename)
{
    ofstream f;
    f.open(filename, ios::trunc);
    f << "num, degree\n";
    f.close();
}
void add_space_to_file1(int num, int degree,string filename)
{
    ofstream f;
    f.open(filename, ios::app);
    f << num << "," << degree << "\n";
    f.close();
}

int main()
{
	// run_tests();
	
	create_empty_space_file("diameter and cluster");
	for (int n=10;n<=10000;n*=10)
	{
		float p = 2 * log(n) / n;

		int a1=0;
		float a2=0.0;

		for (int re=0;re<2;re++){
		Graph g = create_erdos_renyi_graph(n,p);
		int d=5;
		// Graph g = create_barabasi_albert_graph(n,d);


		cout<<"create graph"<<endl;
		// g.edges.erase(0);
		// for (int k=0;k<=10;k++)
		// {
		// 	cout<<k<<endl;
		// 	for (int i:g.edges[k])
		// 		cout<<i;
		// 	cout<<endl;
		// }
		a1 += get_diameter(g);

		a2 += get_clustering_coefficient(g);
		}
		add_space_to_file(n,a1/4,a2/4,"diameter and cluster");

	}
	for (int n=1000;n<=100000;n*=10)
	{
		create_empty_space_file1("degree_distribution"+to_string(n));
		float p = 2 * log(n) / n;
		Graph g = create_erdos_renyi_graph(n,p);
		int d=5;
		// Graph g = create_barabasi_albert_graph(n,d);
		map<int, int> m = get_degree_distribution(g);
		for (int i=1;i<=g.num_nodes;i++)
			add_space_to_file1(i,m[i],"degree_distribution"+to_string(n));
	}


}

