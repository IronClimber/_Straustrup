#ifndef BINARY_TREE_H
#define BINARY_TREE_H

#include "Graph.h"
#include "lib_14.h"

namespace Graph_lib {

struct Binary_tree : Shape {
	Binary_tree(Point p, int l);
	void set_level(int l);
	void draw_lines() const;
	void move(int dx, int dy);
	int get_level() const { return level; }

private:
	int level{0};
	Group content;


};



}






#endif /* Binary_tree.h */
