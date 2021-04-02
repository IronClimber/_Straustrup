#include "Binary_tree.h"
#include "math.h"
#include "lib_13.h"


namespace Graph_lib {

Binary_tree::Binary_tree(Point p, int l, Color c, bool rev) {
	set_level(l);
    add(p);
	create_graph(p,l,c,rev);
}

void Binary_tree::move(int dx, int dy) {
	for (int i = 0; i < nodes.size(); ++i) {
		nodes[i].move(dx,dy);
	}
	for (int i = 0; i < links.size(); ++i) {
		links[i].move(dx,dy);
	}
}

void Binary_tree::draw_lines() const {
	for (int i = 0; i < nodes.size(); ++i) {
		nodes[i].draw();
	}
	for (int i = 0; i < links.size(); ++i) {
		links[i].draw();
	}
}

void Binary_tree::create_graph(Point p, int l, Color c, bool rev) {

	if (level > 0) {

		int size{10};
		int vd{60};
		double hd{size*1.2*pow(2,l-1)};

		Point parent{p};

		add_node(parent, size);
		
		for (int i = 2; i <= level; ++i) {
			int n_parents = pow(2,i-2);
			int n_children = pow(2,i-1);
			for (int j = 0; j < n_parents; ++j) {
				for (int k = 0; k < 2; ++k) {
					Point child{parent.x+int((k-0.5)*hd),parent.y+vd};
					add_link(parent, child, c, rev);
					add_node(child, size);
				}
				parent = Point{parent.x+int(hd*2), parent.y};
			}
			parent = Point{parent.x-int(hd*(n_children+0.5)), parent.y+vd};
			hd/=2;
		}

	}

}

void Binary_tree::add_node(Point p, int s) {
	nodes.push_back(new Circle{p,s});
	nodes[nodes.size()-1].set_fill_color(Color::black);
}

void Binary_tree::add_link(Point p1, Point p2, Color c, bool rev) {
	if (rev) { links.push_back(new Arrow{p2, p1}); }
	else { links.push_back(new Arrow{p1, p2}); }
	links[links.size()-1].set_color(c);
	links[links.size()-1].set_style(Line_style{Line_style::solid, 4});
}

}
