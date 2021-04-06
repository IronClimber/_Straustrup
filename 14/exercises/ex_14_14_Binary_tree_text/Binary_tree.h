#ifndef BINARY_TREE_H
#define BINARY_TREE_H

#include "Graph.h"
#include "lib_14.h"

namespace Graph_lib {

class Node : public Shape {
public:
	Node(Point p, int s, string l);
	void draw_lines() const;
	void move(int dx, int dy);
	string label() { return t.label(); }
	void set_label(string l) { t.set_label(l); }

protected:
	Circle c;
	Text t;

};

class Binary_tree : public Shape {
public:
	Binary_tree(Point p, int l);
	void set_level(int l) { level = l; create_graph(point(0),l);}
	int get_level() const { return level; }
    void reset() { nodes.clear(); links.clear(); }
	void create_graph(Point p, int l);
	virtual void add_node(Point p, int s, string l);
	void add_link(Point p1, Point p2);
	void draw_lines() const;
	void move(int dx, int dy);
	Node& node(int n) { return nodes[n]; }
	Node& last_node(int n) { return nodes[nodes.size()-1]; }
	
protected:
	Vector_ref<Node> nodes;
	Vector_ref<Shape> links;
	int level{0};
	Binary_tree() { };
};

}




#endif /* Binary_tree.h */
