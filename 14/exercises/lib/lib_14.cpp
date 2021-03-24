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

Octagon::Octagon(Point p, int rr) : r{rr} {

  	int x = p.x;
    int y = p.y;
    double angle_iterator = 0;

	for (int i = 0; i < 8; ++i) {
        angle_iterator += M_PI/4;
        x = p.x + int(r*cos(angle_iterator));
        y = p.y - int(r*sin(angle_iterator));
        add(Point{x,y});
    }
}

void Group::move(int dx, int dy) {
	for (int i = 0; i < size(); ++i) {
		vs[i].move(dx,dy);
	}
}

void Group::draw_lines() const {
	for (int i = 0; i < size(); ++i) {
        //cout << i << endl;
		vs[i].draw();
	}
}

void Cell::draw_lines() const {
    Rectangle::draw_lines();
    c.draw();

}

void Cell::set_side(bool cs) {
    cell_side = cs;
    if (cs) { set_fill_color(Color::white); } //Make constant color?
    else { set_fill_color(Color::black); }
    //draw_lines???
}

void Cell::set_checker(int chh) {
    ch.set(chh);
    switch(chh) {
	case Checker::none:
		c.set_fill_color(Color::invisible);
		c.set_color(Color::invisible);
        break;
    case Checker::light:
    	c.set_fill_color(Color::visible); 
		c.set_color(Color::visible);
        c.set_fill_color(Color::white);
        c.set_color(Color::black);
 		break;
    case Checker::dark:
    	c.set_fill_color(Color::visible); 
		c.set_color(Color::visible);
        c.set_fill_color(Color::black);
        c.set_color(Color::white);
        break;
    default:
		//c.set_fill_color(Color::invisible);
		//c.set_color(Color::invisible);
        break;
    }
}

void Cell::move(int dx, int dy) {
    Rectangle::move(dx, dy);
    c.move(dx, dy);
}

Cell::Cell(Point p, int s, bool cs) : size{s}, cell_side{cs}, Rectangle{p,s,s} { 
    //using Rectangle::Rectangle(p,s,s);
    int delta = 4;
    set_side(cs);
    c.move(p.x+delta+1, p.y+delta+1);
    c.set_radius(int(s/2)-delta);
	set_checker(Checker::none);
}


Chessboard::Chessboard(Point p, int s) : size{s} {
    add(p);
    double cell_size = double (s)/8.0;
    for (int i = 0; i < 8; ++i) {
        for (int j = 7; j >= 0; --j) {
            bool side{true};
	        if ((i+j)%2) { side = false; }
			cells.push_back(new Cell{Point{int(p.x+i*cell_size),
									 int(p.y+j*cell_size)},
									 int(cell_size), 
                                     side});
            board.add(cells[cells.size()-1]);
	  	}
    }

    vector<string> numbers{"8", "7", "6", "5", "4", "3", "2", "1"};

    for (int i = 0; i < 8; ++i) {
        board.add(new Text{Point{p.x-int(cell_size*0.5), p.y+int(cell_size)*i+int(cell_size*0.75)},numbers[i]});
	}

    vector<string> letters{"A", "B", "C", "D", "E", "F", "G", "H"};

    for (int i = 0; i < 8; ++i) {
        board.add(new Text{Point{p.x+int(cell_size)*i+int(cell_size*0.25), p.y-int(cell_size*0.2)},letters[i]});
	}
    
}

void Chessboard::draw_lines() const {
    board.draw();
}

void Chessboard::reset() {
    for (int i = 0; i < 64; ++i) {
        change(static_cast<Cell_num>(i), Checker::none);
	}
}

void Chessboard::move(int dx, int dy) {
	board.move(dx,dy);
}

void Chessboard::start() {
    reset();
    vector<Cell_num> dark_checkers{B8, D8, F8, H8, A7, C7, E7, G7, B6, D6, F6, H6};
    vector<Cell_num> light_checkers{A3, C3, E3, G3, B2, D2, F2, H2, A1, C1, E1, G1};
    for (int i = 0; i < dark_checkers.size(); ++i) {
		change(dark_checkers[i], Checker::dark);
    }
    for (int i = 0; i < light_checkers.size(); ++i) {
		change(light_checkers[i], Checker::light);
    }
}

void Chessboard::change(int c, int ct) {
    cells[c].set_checker(ct);
}

bool Chessboard::step(int c1, int c2) {
	if(cells[c1].checker() != Checker::none) {
        if(cells[c2].checker() == Checker::none) {
           	if(cells[c1].checker() == Checker::dark) {
  				change(c2, Checker::dark);
            }
			else {
				change(c2, Checker::light);
			}
			change(c1, Checker::none);
			return true;
        }
  		return false;
    }
    return false;
}

}
