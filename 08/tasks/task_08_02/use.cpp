#include <iostream>
#include "swap.h"

/*

swap_cr - wrong function

swap_v(x,y) - not swap variable
swap_r(x,y) - swap variable    !!Only this swap variables

swap_v(7,9) - not swap variable
swap_r(7,9) - error

swap_v(cx,cy) - not swap variable
swap_r(cx,cy) - error

swap_v(7.7, 9.9) - not swap variable
swap_r(7.7, 9.9) - error (not int reference)

swap_v(dx, dy) - not swap variable
swap_r(dx, dy) - error (not int reference)
*/


using namespace std;

int main() {

    int x = 7;
    int y = 9;
    const int cx = 7;
    const int cy = 9;
    double dx = 7.7;
    double dy = 9.9;
    cout<<"Variables: A = "<<x<<" B = "<<y<<endl;
    //swap_v(x,y);
    //swap_r(x,y);
    //swap_v(7,9);
    //swap_r(7,9);
    //swap_v(cx, cy);
    //swap_r(cx, cy);
    //swap_v(7.7, 9.9);
    //swap_r(7.7, 9.9);
    //swap_v(dx,dy);
    swap_r(dx,dy);
    cout<<"Variables after swap: A = "<<x<<" B = "<<y<<endl;
    

}
