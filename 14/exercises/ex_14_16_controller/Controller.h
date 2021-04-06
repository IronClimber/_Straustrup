#ifndef CONTROLLER_H_
#define CONTROLLER_H_

#include "Graph.h"
#include "Binary_tree.h"

using namespace Graph_lib;

class Controller {
public:
  virtual void on()=0;
  virtual void off()=0;
  virtual void set_level(int l)=0;
  virtual void show()=0;
protected:
  Controller() { };
};

class Test_controller : public Controller {
public:
  Test_controller() : level{0}, state{false} { };
  Test_controller(int l) : level{l}, state{false} { };
  void on() override { state = true; }
  void off() override { state = false; }
  void show() override;
  void set_level(int l) override { level = l; }
private:
  bool state;
  int level;

};

class Shape_controller : public Controller {
public:
  Shape_controller(Shape& s) : state{true}, figure{s}, level{s.fill_color().as_int()} { off(); }
  void on() override;
  void off() override;
  void show() override;
  void set_level(int l) override;

private:
  bool state;
  int level;
  Shape& figure;

};

class Binary_tree_controller : public Controller {
public:
  Binary_tree_controller(Binary_tree& btt) : state{true}, bt{btt}, level{btt.get_level()} { }
  void on() override { state = true; bt.set_level(level); }
  void off() override { state = false; bt.reset(); }
  void show() override;
  void set_level(int l) { level=l; bt.set_level(level); }
private:
  bool state;
  int level;
  Binary_tree& bt;

};



#endif /* CONTROLLER_H_ */
