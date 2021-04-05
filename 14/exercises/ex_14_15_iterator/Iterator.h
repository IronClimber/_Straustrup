#ifndef ITERATOR_H_
#define ITERATOR_H_

#include <vector>
#include <list>

class Iterator {
public:
  Iterator() { }
  virtual double* next() =0;
  virtual double* end() =0;
protected:
  double* pos;
};

class Vector_iterator : public Iterator {
public:
  Vector_iterator(std::vector<double>& vv) : vd{vv} {
    pos = &*vd.begin();
  }
  double* next() override;
  double* end() override { return &vd.back(); }
private:
  std::vector<double>& vd;
};

class List_iterator : public Iterator {
public:
  List_iterator(std::list<double>& ll) : ld{ll} {
    pos = &ld.front();
  }
  double* next() override;
  double* end() override { return &ld.back(); }
  void print();
private:
  std::list<double>& ld;
};

#endif /*ITERATOR_H_*/
