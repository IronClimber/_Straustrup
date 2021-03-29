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
		int vd{40};
		double hd{r*2*pow(2,l-1)};

		Point parent{p};

		content.add(new Circle{parent, r});

		for (int i = 2; i <= l; ++i) {
			for (int j = 0; j < pow(2,i-1); ++j) {
				//Point child
				content.add(new Circle{Point{parent.x+int((j-0.5)*hd),parent.y+vd},r});
				
			}

			hd/=2;
			parent = Point{parent.x-int(hd), parent.y+vd*i};

		}

	}

}



}
