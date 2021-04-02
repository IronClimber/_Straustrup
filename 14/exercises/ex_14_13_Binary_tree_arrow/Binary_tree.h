#ifndef BINARY_TREE_H
#define BINARY_TREE_H

#include "Graph.h"
#include "lib_14.h"

namespace Graph_lib {
/*
class Node : public Shape {
public:
	Node(Point p, size s) : size{s} { add(p); }
	void draw_lines() const;
	
}

protected:
	int size{10};
	Node() { };

}
*/
class Binary_tree : public Shape {
public:
	Binary_tree(Point p, int l, Color c = Color::black, bool rev = false);
	void set_level(int l) { level = l; }
	int get_level() const { return level; }
	void create_graph(Point p, int l, Color c = Color::black, bool rev = false);
	virtual void add_node(Point p, int s);
	void add_link(Point p1, Point p2, Color c = Color::black, bool rev = false);
	//void add_content(Shape& s);
	void draw_lines() const;
	void move(int dx, int dy);
	
protected:
	Vector_ref<Shape> nodes;
	Vector_ref<Shape> links;
	int level{0};
	Binary_tree() { };
};

}




#endif /* Binary_tree.h */
