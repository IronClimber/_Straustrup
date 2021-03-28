#include "Pseudo.h"

namespace Graph_lib{

Pseudo_window::Pseudo_window(Point p, int w, int h, string n) {
	add(p);
	int header_height{20};
    content.add(new Box{Point{p.x,p.y-header_height},w,h,5});
	content.add(new Line{p,Point{p.x+w,p.y}});
	content.add(new Text{Point{p.x+10, p.y-5}, n});
	content.add(new Circle{Point{p.x+340,p.y-10},8});
	content.add(new Circle{Point{p.x+360,p.y-10},8});
	content.add(new Circle{Point{p.x+380,p.y-10},8});
	content.add(new Line{Point{p.x+335,p.y-10},{p.x+345,p.y-10}});
	content.add(new Rectangle{Point{p.x+355,p.y-13},10,6});
	content.add(new Lines{Point{p.x+376,p.y-14}, Point{p.x+384,p.y-6},
						  Point{p.x+376,p.y-6}, Point{p.x+384,p.y-14}});
    
}

/*
void Pseudo_window::add_image(Point p, string f, Suffix::Encoding e) {
	content.add(new Image{p,f,e});
	//content[content.size()-1]->set_mask(Point{0,0},400,400);
}
*/

void Pseudo_window::add_content(Shape& s) {
	content.add(s);
}

void Pseudo_window::draw_lines() const {
	content.draw();
}

void Pseudo_window::move(int dx, int dy) {
	content.move(dx,dy);
}

}
