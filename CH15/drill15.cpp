
#include "Simple_window.h"
#include "Graph.h"

double one(double x) { return 1; }
double slope(double x) { return x/2; }
double square(double x) { return x*x; }
double sloping_cos(double x) { return cos(x)+slope(x); }

int main(){
try{

Point tl{100,100};
Simple_window win {tl,600,600,"Function graphs"};

Axis xa {Axis::x, Point{100,300}, 400, 20, "1 == 20 pixels"};
xa.set_color(Color::red);
win.attach(xa);

Axis ya {Axis::y, Point{300,500}, 400, 20, "1 == 20 pixels"};
ya.set_color(Color::red);
win.attach(ya);


constexpr int xmax=600;
constexpr int ymax=600;

constexpr int r_min=-10;
constexpr int r_max=11;

constexpr int x_orig=xmax/2;
constexpr int y_orig=ymax/2;
const Point orig {x_orig,y_orig};

constexpr int n_points=400;

constexpr int x_scale = 20;
constexpr int y_scale = 20;


Text sp {Point{100,ymax-230},"x/2"};
Function s {one,r_min,r_max,orig,n_points,x_scale,y_scale};
Function s2 {slope,r_min,r_max,orig,n_points,x_scale,y_scale};
Function s3 {square,r_min,r_max,orig,n_points,x_scale,y_scale};
Function s4 {cos,r_min,r_max,orig,400,20,20};
Function s5 {sloping_cos, r_min,r_max,orig,400,20,20};


s4.set_color(Color::blue);


win.attach(sp);
win.attach(s);
win.attach(s2);
win.attach(s3);
win.attach(s4);
win.attach(s5);


win.wait_for_button();

}
catch(exception& e){
	cerr << "Exception:" << e.what() << '\n';
	return 1;
}
catch(...){
	cerr << "Error\n";
	return 2;
}


	}
