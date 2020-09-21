#ifndef NODE_H
#define NODE_H

class Node
{
public:
	int id;
	Node(){}
	Node(int new_id)
	{
		id = new_id;
	}
	bool operator==(const Node& other) const 
		{return id == other.id;} 

};




#endif