#pragma once

class Node
{
public:
	Node(void){ link = nullptr};
	Node(const Item& init_data=Item(),
	~Node(void);
private:
	Item data;
	Node* link;
};

