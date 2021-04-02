#include "Binary_tree.h"
#include "math.h"
#include "lib_13.h"


namespace Graph_lib {

Node::Node(Point p, int s, string l) : c{p,s}, t{Point{p.x-3,p.y-18}, l} { 
	add(p);
	c.set_fill_color(Color::black);
	if (l[l.size()-1] == 'l') { t.move(-l.size()*2-6, 0); }
}

void Node::draw_lines() const{
	c.draw();
	t.draw();
}

void Node::move(int dx, int dy) {
	Shape::move(dx,dy);
	c.move(dx,dy);
	t.move(dx,dy);
}

Binary_tree::Binary_tree(Point p, int l) {
	set_level(l);
    add(p);
	create_graph(p,l);
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

string get_label(int l, int p, int c) {
	string label(l-1, 'l');
	for (int i=2; i < l; ++i) {
		if (p%2 != 0) { label[l-i] = 'r'; }
		//else { label[i-1]= 'r'; }
		p/=2;
	}
	if (c == 0) { label += "l"; }
	else if (c == 1) { label += "r"; }
	
	return label;
}

void Binary_tree::create_graph(Point p, int l) {

	if (level > 0) {

		int size{10};
		int vd{60};
		double hd{size*2.5*pow(2,l-1)};

		Point parent{p};
		string label{"l"};
		add_node(parent, size, label);
		
		for (int i = 2; i <= level; ++i) {
			label+="l";
			int n_parents = pow(2,i-2);
			int n_children = pow(2,i-1);
			for (int j = 0; j < n_parents; ++j) {
				for (int k = 0; k < 2; ++k) {
					Point child{parent.x+int((k-0.5)*hd),parent.y+vd};
					add_link(parent, child);
					add_node(child, size, get_label(i, j, k));
				}
				parent = Point{parent.x+int(hd*2), parent.y};
			}
			parent = Point{parent.x-int(hd*(n_children+0.5)), parent.y+vd};
			hd/=2;
		}

	}

}

void Binary_tree::add_node(Point p, int s, string l) {
	nodes.push_back(new Node{p,s,l});
}

void Binary_tree::add_link(Point p1, Point p2) {
	links.push_back(new Arrow{p1, p2});
	links[links.size()-1].set_color(Color::black);
	links[links.size()-1].set_style(Line_style{Line_style::solid, 4});
}

}
