#ifndef PSEUDO_H
#define PSEUDO_H

#include "Graph.h"
#include "lib_13.h"
#include "lib_14.h"


namespace Graph_lib {

struct Pseudo_window : Shape {
	Pseudo_window(Point p, int w, int h, string l);
	//void add_image(Point p, string f, Suffix::Encoding e = Suffix::none);
	void draw_lines() const;
	void add_content(Shape& s);
	void move(int dx, int dy);



private:
	string label;
	int width;
	int height;
	Group content;  

};





}

#endif /*Pseudo.h*/
