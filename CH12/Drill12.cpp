#include "Graph.h"
#include "Simple_window.h"
#include "std_lib_facilities.h"

int main()
try{
	using namespace Graph_lib;	

	Point tl {100,100};
	Simple_window win {tl,900,500,"Canvas"};
	win.wait_for_button();
//x tengely----------------------------------------------------------------------------
	Axis xa {Axis::x, Point{20,300}, 270, 10, "x axis"};
	win.attach(xa);
	win.set_label("Canvas #2");
	win.wait_for_button();
//y tengely----------------------------------------------------------------------------
	Axis ya {Axis::y, Point{20,300}, 270, 10, "y axis"};
	ya.set_color(Color::cyan);
	ya.label.set_color(Color::dark_blue);
	win.attach(ya);
	win.set_label("Canvas #3");
	win.wait_for_button(); 
//Szinusz görbe----------------------------------------------------------------------------
	Function sine {sin,0,100,Point{20,150},1000,50,50};
	win.attach(sine);
	win.set_label("Canvas #4");
	win.wait_for_button();
	sine.set_color(Color::red);
//Háromszög----------------------------------------------------------------------------
	Polygon poly2;
	poly2.add(Point{300,200}); 
	poly2.add(Point{350,100});
	poly2.add(Point{400,200});
	poly2.set_color(Color::black);
	poly2.set_style(Line_style::dash);
	win.attach(poly2);
	win.set_label("Canvas #5");
	win.wait_for_button();
//Téglalap----------------------------------------------------------------------------
	Rectangle r {Point{200,200}, 100, 60};
	win.attach(r);
	win.set_label("Canvas #6");
	win.wait_for_button();
//Sokszög----------------------------------------------------------------------------
	Closed_polyline poly_rect;
	poly_rect.add(Point{100,50});
	poly_rect.add(Point{200,50});
	poly_rect.add(Point{200,100});
	poly_rect.add(Point{100,100});
	win.attach(poly_rect);
	poly_rect.add(Point{50,85});
//Kitöltés----------------------------------------------------------------------------
	r.set_fill_color(Color::dark_yellow);
	poly2.set_style(Line_style(Line_style::dash,4));
	poly_rect.set_style(Line_style(Line_style::dash,2));
	poly_rect.set_fill_color(Color::green);
	win.set_label("Canvas #7");
	win.wait_for_button();
//Szöveg----------------------------------------------------------------------------
	Text t {Point{160,200}, "Hello, graphical world!"};
	win.attach(t);
	win.set_label("Canvas #8");
	win.wait_for_button();
//Szöveg formázása----------------------------------------------------------------------------
	t.set_font(Font::times_bold);
	t.set_font_size(40);
	win.set_label("Canvas #9");
	win.wait_for_button();
//Kép beszúrása----------------------------------------------------------------------------
	Image ii {Point{200,50},"kaposzta.jpg"};
	win.attach(ii);
	win.set_label("Canvas #10");
	win.wait_for_button();
//Kép mozgatása----------------------------------------------------------------------------
	ii.move(110,200);
	win.set_label("Canvas #11");
	win.wait_for_button();
//végső leszámolás----------------------------------------------------------------------------
	Circle c {Point{100,200},50};
	Ellipse e {Point{100,200}, 75,25};
	e.set_color(Color::dark_green);
	Mark m {Point{100,200},'x'};
	ostringstream oss;
	oss << "screen size: " << x_max() << "*" << y_max()
	<< "; window size: " << win.x_max() << "*" << win.y_max();
	Text sizes {Point{110,20},oss.str()};
	Image cal {Point{225,50},"spin.gif"};
	cal.set_mask(Point{40,40},200,150);
	win.attach(c);
	win.attach(m);
	win.attach(e);
	win.attach(sizes);
	win.attach(cal);
	win.set_label("Canvas #12");
	win.wait_for_button();

}catch(exception& e){
	return 1;
}
catch(...){
	return 2;
}
