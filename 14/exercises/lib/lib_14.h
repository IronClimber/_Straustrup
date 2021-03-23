#ifndef LIB_14_H
#define LIB_14_H

#include "Graph.h"

namespace Graph_lib {

bool line_segment_intersect(Point p1, Point p2, Point p3, Point p4, Point& intersection);

struct Stripped_rectangle : Rectangle {

  using Rectangle::Rectangle;
  void draw_lines() const;  

};

struct Stripped_circle : Circle {

  using Circle::Circle;
  void draw_lines() const;  

};

struct Stripped_closed_polyline : Closed_polyline {

  using Closed_polyline::Closed_polyline;
  void draw_lines() const;  

};

struct Octagon : Polygon {
  Octagon(Point p, int rr);
private:
  int r;
};

struct Group : Shape {

  Group() { Shape::add(Point{0,0}); }
  Group(Point p) { Shape::add(p); }
    
  void move(int dx, int dy);
  void draw_lines() const;
  void add(Shape& s) { vs.push_back(&s); }
  void add(Shape* s) { vs.push_back(s); }
  int size() const { return vs.size(); }
  //Shape& last() const { return vs[vs.size()-1]; }

  //Shape& operator[](int i) { return vs[i]; }
  const Shape& operator[](int i) const { return vs[i]; }
  Shape* operator[](int i) { return &vs[i]; }
private:
  Vector_ref<Shape> vs;
};

enum Cell_num  {A1,A2,A3,A4,A5,A6,A7,A8,
		        B1,B2,B3,B4,B5,B6,B7,B8,
		        C1,C2,C3,C4,C5,C6,C7,C8,
		        D1,D2,D3,D4,D5,D6,D7,D8,
		        E1,E2,E3,E4,E5,E6,E7,E8,
		        F1,F2,F3,F4,F5,F6,F7,F8,
		        G1,G2,G3,G4,G5,G6,G7,G8,
		        H1,H2,H3,H4,H5,H6,H7,H8};

struct Checker {
  enum Checker_type {
      none = 0,
      light = 1,
      dark = 2,
  };

  Checker() : ch{Checker::none} {};
  Checker(int chh) : ch{chh} {};
  int set(int chh) { ch = chh; }
  int get() const { return ch; }
private:

  int ch;
  
};

struct Cell : Rectangle {

  Cell(Point p, int s, bool cs);
  void set_side(bool cs);
  void set_checker(int chh);
  bool side() const { return cell_side; }
  Checker checker() const { return ch.get(); }
  void draw_lines() const;
  

private:
  int size{20}; //ToDo: MIN_SIZE 5?
  bool cell_side{true}; // true -> white, flase -> black
  Checker ch;
  Circle c{Point{0,0},1}; // Default to no  conflict
};


struct Chessboard : Shape {
  Chessboard(Point p, int s);
  bool step(Cell_num c1, Cell_num c2);
  void change(int c, int ct);
  void reset();
  void start();
  void draw_lines() const;
  
private:
  int size;
  Group board;
  
};

}

#endif /* lib_14.h */
