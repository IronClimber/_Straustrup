#include "Binary_tree.h"
#include "math.h"


namespace Graph_lib {

/*
Binary_tree::create_child(Point p) {
	content.add(

}
*/

void Binary_tree::move(int dx, int dy) {
	content.move(dx,dy);
}

void Binary_tree::draw_lines() const {
	content.draw();

}

Binary_tree::Binary_tree(Point p, int l) : level{l} {

    add(p);
	
	if (level > 0) {

		int r{10};
		int vd{60};
		double hd{r*1.2*pow(2,l-1)};

		Point parent{p};

		content.add(new Circle{parent, r});
content[content.size()-1]->set_fill_color(Color::black);
		
		for (int i = 2; i <= level; ++i) {
			int n_parents = pow(2,i-2);
			int n_children = pow(2,i-1);
			//parent = Point{parent.x+int(hd), parent.y};
			for (int j = 0; j < n_parents; ++j) {
				for (int k = 0; k < 2; ++k) {
					Point child{parent.x+int((k-0.5)*hd),parent.y+vd};
					content.add(new Line{child, parent});
					content.add(new Circle{child,r});
					content[content.size()-1]->set_fill_color(Color::black);
				}
				parent = Point{parent.x+int(hd*2), parent.y};
			}

			
			parent = Point{parent.x-int(hd*(n_children+0.5)), parent.y+vd};
			hd/=2;
		}

	}

}



}
