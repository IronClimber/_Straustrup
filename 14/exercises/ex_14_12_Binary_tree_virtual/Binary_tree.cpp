#include "Binary_tree.h"
#include "math.h"
#include "lib_13.h"


namespace Graph_lib {

Binary_tree::Binary_tree(Point p, int l) {
	set_level(l);
    add(p);
	create_graph(p,l);
}

void Binary_tree::move(int dx, int dy) {
	content.move(dx,dy);
}

void Binary_tree::draw_lines() const {
	content.draw();
}

void Binary_tree::create_graph(Point p, int l) {

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
					add_link(parent, child);
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
	content.add(new Circle{p,s});
	content[content.size()-1]->set_fill_color(Color::black);
}

void Binary_tree::add_link(Point p1, Point p2) {
	content.add(new Line{p1, p2});
}

void Binary_tree_triangle::add_node(Point p, int s) {
	content.add(new Regular_polygon{p,3,s});
	content[content.size()-1]->set_fill_color(Color::black);
}


Binary_tree_triangle::Binary_tree_triangle(Point p, int l) {

	set_level(l);
    add(p);
	create_graph(p,l);
}



}
