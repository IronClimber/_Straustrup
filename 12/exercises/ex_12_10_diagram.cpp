#include "Simple_window.h"
#include "Graph.h"

using namespace Graph_lib;

int main() {

    Simple_window win{Point{100,100}, 600, 650, "Excersice 12.10 - File diagram"};
    
    /*FLTK headers*/
    Rectangle fltk_h1{Point{240,40},120,50};
    fltk_h1.set_fill_color(Color::white);
    win.attach(fltk_h1);

    Rectangle fltk_h2{Point{245,45},120,50};
    fltk_h2.set_fill_color(Color::white);
    win.attach(fltk_h2);

    Rectangle fltk_h{Point{250,50},120,50};
    fltk_h.set_fill_color(Color::white);
    win.attach(fltk_h);

    Text fltk_h_text{Point{260,70}, "FLTK headers"};
    win.attach(fltk_h_text);

    /*FLTK code*/
    Rectangle fltk_code1{Point{440,90},100,50};
    fltk_code1.set_fill_color(Color::white);
    win.attach(fltk_code1);

    Rectangle fltk_code2{Point{445,95},100,50};
    fltk_code2.set_fill_color(Color::white);
    win.attach(fltk_code2);

    Rectangle fltk_code{Point{450,100},100,50};
    fltk_code.set_fill_color(Color::white);
    win.attach(fltk_code);

    Text fltk_code_text{Point{460,120}, "FLTK code"};
    win.attach(fltk_code_text);

    /*Arrow from FLTK code to FLTK headers*/
    Line fltk_code_fltk_h{Point{440,115},Point{370,75}};
    win.attach(fltk_code_fltk_h);

    Circle fltk_code_fltk_h_arrow{Point{370,75},2};
    fltk_code_fltk_h_arrow.set_fill_color(Color::black);
    win.attach(fltk_code_fltk_h_arrow);

    /*Point header*/
    Rectangle point_h{Point{50,100},150,30};
    point_h.set_fill_color(Color::white);
    win.attach(point_h);

    Text point_h_up_text{Point{50,90}, "Point.h:"};
    win.attach(point_h_up_text);

    Text point_h_in_text{Point{60,120}, "struct Point { ... };"};
    win.attach(point_h_in_text);

    /*Window header*/
    Rectangle window_h{Point{250,170},160, 60};
    window_h.set_fill_color(Color::white);
    win.attach(window_h);

    Text window_h_up_text{Point{250,160}, "Window.h:"};
    win.attach(window_h_up_text);

    Text window_h_in_text1{Point{260,190}, "//window interface;"};
    win.attach(window_h_in_text1);

    Text window_h_in_text2{Point{260,210}, "class Window {...};"};    
    win.attach(window_h_in_text2);

    /*Arrow from Window header to FLTK headers*/
    Line window_h_fltk_h{Point{330,170},Point{330,100}};
    win.attach(window_h_fltk_h);

    Circle window_h_fltk_h_arrow{Point{330,100},2};
    window_h_fltk_h_arrow.set_fill_color(Color::black);
    win.attach(window_h_fltk_h_arrow);

    /*Arrow from Window header to point header*/
    Line window_h_point_h{Point{250,170},Point{150,130}};
    win.attach(window_h_point_h);

    Circle window_h_point_h_arrow{Point{150,130},2};
    window_h_point_h_arrow.set_fill_color(Color::black);
    win.attach(window_h_point_h_arrow);

    /*Graph header*/
    Rectangle graph_h{Point{50,200},160, 60};
    graph_h.set_fill_color(Color::white);
    win.attach(graph_h);

    Text graph_h_up_text{Point{50,190}, "Graph.h:"};
    win.attach(graph_h_up_text);

    Text graph_h_in_text1{Point{60,220}, "//graphic interface;"};
    win.attach(graph_h_in_text1);

    Text graph_h_in_text2{Point{60,240}, "struct Shape {...};"};    
    win.attach(graph_h_in_text2);

    /*Arrow from Graph header to FLTK headers*/
    Line graph_h_fltk_h{Point{140,200},Point{300,100}};
    win.attach(graph_h_fltk_h);

    Circle graph_h_fltk_h_arrow{Point{300,100},2};
    graph_h_fltk_h_arrow.set_fill_color(Color::black);
    win.attach(graph_h_fltk_h_arrow);

    /*Arrow from Graph header to point header*/
    Line graph_h_point_h{Point{120,200},Point{120,130}};
    win.attach(graph_h_point_h);

    Circle graph_h_point_h_arrow{Point{120,130},2};
    graph_h_point_h_arrow.set_fill_color(Color::black);
    win.attach(graph_h_point_h_arrow);

    /*GUI header*/
    Rectangle gui_h{Point{390,260},150, 60};
    gui_h.set_fill_color(Color::white);
    win.attach(gui_h);

    Text gui_h_up_text{Point{390,250}, "GUI.h:"};
    win.attach(gui_h_up_text);

    Text gui_h_in_text1{Point{400,280}, "//GUI interface;"};
    win.attach(gui_h_in_text1);

    Text gui_h_in_text2{Point{400,300}, "struct In_box {...};"};    
    win.attach(gui_h_in_text2);

    /*Arrow from GUI header to FLTK headers*/
    Line gui_h_fltk_h{Point{500,260},Point{360,100}};
    win.attach(gui_h_fltk_h);

    Circle gui_h_fltk_h_arrow{Point{360,100},2};
    gui_h_fltk_h_arrow.set_fill_color(Color::black);
    win.attach(gui_h_fltk_h_arrow);

    /*Arrow from GUI header to Window header*/
    Line gui_h_window_h_{Point{460,260},Point{410,205}};
    win.attach(gui_h_window_h_);

    Circle gui_h_window_h_arrow{Point{410,205},2};
    gui_h_window_h_arrow.set_fill_color(Color::black);
    win.attach(gui_h_window_h_arrow);

    /*Simple window header*/
    Rectangle sw_h{Point{200,380},210, 60};
    sw_h.set_fill_color(Color::white);
    win.attach(sw_h);

    Text sw_h_up_text{Point{200,370}, "Simple_window.h:"};
    win.attach(sw_h_up_text);

    Text sw_h_in_text1{Point{210,400}, "//window interface;"};
    win.attach(sw_h_in_text1);

    Text sw_h_in_text2{Point{210,420}, "struct Simple_window {...};"};    
    win.attach(sw_h_in_text2);

    /*Arrow from Simple window header to GUI header*/
    Line sw_h_gui_h{Point{370,380},Point{400,320}};
    win.attach(sw_h_gui_h);

    Circle sw_h_gui_h_arrow{Point{400,320},2};
    sw_h_gui_h_arrow.set_fill_color(Color::black);
    win.attach(sw_h_gui_h_arrow);

    /*Arrow from Simple window header to Window header*/
    Line sw_h_window_h_{Point{350,380},Point{330,230}};
    win.attach(sw_h_window_h_);

    Circle sw_h_window_h__arrow{Point{330,230},2};
    sw_h_window_h__arrow.set_fill_color(Color::black);
    win.attach(sw_h_window_h__arrow);

    /*Chapter code*/
    Rectangle chapter_c{Point{70,500},220, 80};
    chapter_c.set_fill_color(Color::white);
    win.attach(chapter_c);

    Text chapter_c_up_text{Point{70,490}, "chapter12.cpp:"};
    win.attach(chapter_c_up_text);

    Text chapter_c_in_text1{Point{80,520}, "#include \"Graph.h\""};
    win.attach(chapter_c_in_text1);

    Text chapter_c_in_text2{Point{80,540}, "#include \"Simple_window.h\""};    
    win.attach(chapter_c_in_text2);

    Text chapter_c_in_text3{Point{80,560}, "int main() {...}"};
    win.attach(chapter_c_in_text3);
    
    /*Arrow from chapter code to graph header*/
    Line chapter_c_graph_h{Point{190,500},Point{140,260}};
    win.attach(chapter_c_graph_h);

    Circle chapter_c_graph_h_arrow{Point{140,260},2};
    chapter_c_graph_h_arrow.set_fill_color(Color::black);
    win.attach(chapter_c_graph_h_arrow);

    /*Arrow from chapter code to Simple window header*/
    Line chapter_c_sw_h{Point{210,500},Point{240,440}};
    win.attach(chapter_c_sw_h);

    Circle chapter_c_sw_h_arrow{Point{240,440},2};
    chapter_c_sw_h_arrow.set_fill_color(Color::black);
    win.attach(chapter_c_sw_h_arrow);

    /*Graph code*/
    Rectangle graph_c{Point{20,370},100,30};
    graph_c.set_fill_color(Color::white);
    win.attach(graph_c);

    Text graph_c_up_text{Point{20,360}, "Graph.cpp:"};
    win.attach(graph_c_up_text);

    Text graph_c_in_text1{Point{30,390}, "Graph code"};
    win.attach(graph_c_in_text1);

    /*Arrow from graph code to graph header*/
    Line graph_c_graph_h{Point{100,370},Point{120,260}};
    win.attach(graph_c_graph_h);

    Circle graph_c_graph_h_arrow{Point{120,260},2};
    graph_c_graph_h_arrow.set_fill_color(Color::black);
    win.attach(graph_c_graph_h_arrow);

    /*Window code*/
    Rectangle window_c{Point{180,300},120,30};
    window_c.set_fill_color(Color::white);
    win.attach(window_c);

    Text window_c_up_text{Point{180,290}, "Window.cpp:"};
    win.attach(window_c_up_text);

    Text window_c_in_text1{Point{190,320}, "Window code"};
    win.attach(window_c_in_text1);

    /*Arrow from window code to window header*/
    Line window_c_window_h{Point{280,300},Point{310,230}};
    win.attach(window_c_window_h);

    Circle window_c_window_h_arrow{Point{310,230},2};
    window_c_window_h_arrow.set_fill_color(Color::black);
    win.attach(window_c_window_h_arrow);

    /*GUI code*/
    Rectangle gui_c{Point{430,370},80,30};
    gui_c.set_fill_color(Color::white);
    win.attach(gui_c);

    Text gui_c_up_text{Point{430,360}, "GUI.cpp:"};
    win.attach(gui_c_up_text);

    Text gui_c_in_text1{Point{440,390}, "GUI code"};
    win.attach(gui_c_in_text1);

    /*Arrow from gui code to gui header*/
    Line gui_c_gui_h{Point{500,370},Point{480,320}};
    win.attach(gui_c_gui_h);

    Circle gui_c_gui_h_arrow{Point{480,320},2};
    gui_c_gui_h_arrow.set_fill_color(Color::black);
    win.attach(gui_c_gui_h_arrow);

    win.wait_for_button();

}
