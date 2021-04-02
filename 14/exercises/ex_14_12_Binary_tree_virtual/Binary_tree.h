#ifndef BINARY_TREE_H
#define BINARY_TREE_H

#include "Graph.h"
#include "lib_14.h"

namespace Graph_lib {

class Binary_tree : public Shape {
public:
	Binary_tree(Point p, int l);
	void set_level(int l) { level = l; }
	void draw_lines() const;
	void move(int dx, int dy);
	int get_level() const { return level; }
	void create_graph(Point p, int l);
	virtual void add_node(Point p, int s);
	void add_link(Point p1, Point p2);
	//void add_content(Shape& s);
	
protected:
	Group content;
	int level{0};
	Binary_tree() { };
};


class Binary_tree_triangle : public Binary_tree {
public:
	Binary_tree_triangle(Point p, int l);
	void add_node(Point p, int s) override;
};


}






#endif /* Binary_tree.h */
