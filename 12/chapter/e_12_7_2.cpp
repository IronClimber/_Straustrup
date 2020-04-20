#include "std_lib_facilities.h"
#include "Simple_window.h"
#include "Graph.h"

using namespace Graph_lib;

int main() {

    Point t1{100,100};

    Simple_window win{t1,600,400,"Canvas"};

    win.wait_for_button();

}
