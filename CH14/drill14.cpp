#include "std_lib_facilities.h"
/*#include <iostream>
	using namespace std;*/


class B1{
public:
	virtual void vf() { cout << "B1::vf()\n";}
	void f() {cout << "B1::f()\n";}
	virtual void pvf()=0;

};
class D1 : public B1{
public:
	void vf() override {cout << "D1::vf()\n";}
	void f() {cout << "D1::f()\n";}
};

class D2 : public D1{
public:
	void pvf() override {cout << "D2::pvf()\n";}
};

class B2{
public:
	virtual void pvf()=0;
};

class D21 : public B2{
public:
	string s="string";
	void pvf() override {cout << "D21::pvf(): " << s << '\n';}
};
class D22 : public B2{
public:
	int i=2;
	void pvf() override {cout << "D21::pvf(): " << i << '\n';}
};


void f(B2& b2){
	b2.pvf();
}

int main(){

/*B1 b1;
D1 d1;
B1& rb1 = d1;
rb1.vf();
rb1.f();*/



cout << "Calling:\n";



D2 d2;
D21 d21;
D22 d22;

/*b1.vf();
b1.f();
d1.vf();
d1.f();*/

d2.vf();
d2.f();
d2.pvf();

cout << "Calling with f function:\n";

//f(d1);

f(d21);
f(d22);


	return 0;
}
