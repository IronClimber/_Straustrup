#include "lib_14.h"

namespace Graph_lib {

void Stripped_rectangle::draw_lines() const {
  
  if (fill_color().visibility()) {	// fill
	fl_color(fill_color().as_int());
	for (int i = 0; i < height(); ++i) {
	  if (i%2) {
 		fl_line(point(0).x,point(0).y+i,point(0).x+width()-1,point(0).y+i);
	  }
	}
	fl_color(color().as_int());	// reset color
  }

  if (color().visibility()) {	// edge on top of fill
	fl_color(color().as_int());
	fl_rect(point(0).x,point(0).y,width(),height());
  }

}

void Stripped_circle::draw_lines() const {
  
  if (fill_color().visibility()) {	// fill
	fl_color(fill_color().as_int());
	for (int i = 0; i < radius()*2; ++i) {
	  if (i%2) {
		int h = -(i-radius());
        int a = sqrt(radius()*radius()-h*h);
 		fl_line(point(0).x + radius() - a,
				point(0).y+i,
				point(0).x + radius() + a - 1,
				point(0).y+i);
	  }
	}
	fl_color(color().as_int());	// reset color
  }

  if (color().visibility()) {	// edge on top of fill
	fl_color(color().as_int());
	fl_arc(point(0).x,point(0).y,radius()*2,radius()*2,0,360);
  }

}

void print_points(vector<Point> &vpp) {
	for(Point p : vpp) {
		cout << p.x << "-" << p.y << " ";
	}
	cout << endl;
}


void Stripped_closed_polyline::draw_lines() const {
	//+Find upper and lower point.
	//+left and right point
	//+For every horizontal line find intersection with polyline.
	//+Start draw lines from point to point. Draw even, not draw odd distances.

	Point upper_p = point(0);
	Point lower_p = point(0);
	Point left_p  = point(0);
	Point right_p = point(0);

    for(int i=1; i<number_of_points(); ++i){
		if(upper_p.y > point(i).y) { 
			upper_p = point(i);
		}
		else if(lower_p.y < point(i).y) {
			lower_p = point(i);
		}
		if(left_p.x > point(i).x) {
			left_p = point(i);
		}
		else if (right_p.x < point(i).x) {
			right_p = point(i);
		}
	}
	
	/*
	cout << upper_p.y << " " << lower_p.y << " "
		 << left_p.x  << " " << right_p.x << endl;
	*/
	
	//fill strip lines
	if (fill_color().visibility()) {
		fl_color(fill_color().as_int());

		Point p;
		for(int i=1; i<lower_p.y-upper_p.y; i+=2) {

		  vector<Point> vp;
		  for(int j=1; j<number_of_points(); ++j) {
		
			if(line_segment_intersect(Point{left_p.x, upper_p.y+i}, Point{right_p.x, upper_p.y+i}, point(j-1), point(j), p)) {
			  vp.push_back(p);
			  //cout << p.x << "-" << p.y << " ";
			}

		  }

		  if(line_segment_intersect(Point{left_p.x, upper_p.y+i}, Point{right_p.x, upper_p.y+i}, point(number_of_points()-1), point(0), p)) {
			  vp.push_back(p);
			  //cout << p.x << "-" << p.y << " ";
		  }
		  //cout << endl;
		  //print_points(vp);

		  //sort points, bubble sorting
		  for (int k=0; k<vp.size(); ++k) {
			for (int l=vp.size()-1; l>k+1; --l) {
			  if (vp[l].x < vp[l-1].x) {
				swap(vp[l],vp[l-1]);
			  }
			}
		  }
		  //cout << i << ": ";
		  
		  //draw strips
		  for (int m=1; m<vp.size(); m+=2) {
			/*
			cout << vp[m].x << "-"
				 << vp[m].y << ","
				 << vp[m-1].x << "-"
				 << vp[m-1].y << ";";
			*/
			fl_line(vp[m].x,
			    	vp[m].y,
				    vp[m-1].x,
				    vp[m-1].y);
		  }
		  //cout << endl;

		}
		
		fl_color(color().as_int());
	}

	//draw lines
	if (color().visibility()) {
		Shape::draw_lines();
		fl_line(point(number_of_points()-1).x,point(number_of_points()-1).y,point(0).x,point(0).y);
	}
}
}
