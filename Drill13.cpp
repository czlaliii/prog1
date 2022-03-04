
#include "../GUI/Simple_window.h"
#include "../GUI/Graph.h"

#include <string>
#include <iostream>


using namespace Graph_lib;

int main(){

try{

Point t1 {100, 100};
Simple_window win {t1, 800, 1000, "Canvas"};
win.wait_for_button();

Lines grid;
int x_size = 800;
int y_size = 800;
for(int i=100; i<=x_size; i+=100){
	grid.add(Point(i, 0), Point(i, y_size));
	grid.add(Point(0, i), Point(x_size, i));
}
win.attach(grid);
win.wait_for_button();

Vector_ref<Rectangle> vr;
for(int i=0; i<8; ++i){
	vr.push_back(new Rectangle(Point(i*100, i*100),101, 101));
	vr[vr.size()-1].set_fill_color(Color::red);
	win.attach(vr[vr.size()-1]);
}
win.wait_for_button();

Image pizza1{Point{200,0},"pizza.jpeg"};
win.attach(pizza1);
Image pizza2(Point(500,200),"pizza.jpeg");
win.attach(pizza2);
Image pizza3(Point(200,500),"pizza.jpeg");
win.attach(pizza3);
win.wait_for_button();

   Image nike{Point{0,0},"nike.jpg"};
	nike.set_mask(Point{0,0},100,100);
	win.attach(nike);
	win.wait_for_button();
   int dx=0;
int dy=0;
for(int i=0;i<8;i++){
	for(int j=0;j<7;j++){
		dx=+100;
		nike.move(dx,0);
		win.wait_for_button();
	}
	if(i==7)
		break;
	else{
		nike.move(-700,dy=+100);
		win.wait_for_button();
	}
}

 		
return 0;

}
catch (exception& e){
cerr << "exception: " << e.what() << "\n";
return 1;
}
catch (...) {
cerr << "error \n";
return 2;
}
}

