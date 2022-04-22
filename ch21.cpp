#include "../std_lib_facilities.h"
#include "Matrix.h"
#include "MatrixIO.h"
#include <complex>

using namespace Numeric_lib;

void square(){
cout << "Please, write an integer number\n";
int s;
cin >> s;

errno=0;
double s2 =sqrt(s);

if(errno==EDOM) //the square root and log function is only defined for non-negative numbers so if we pass negative argument in these function they set errno to EDOM(33)
	cerr << "sqrt() not defined for negative argument" << endl;
else
	cerr << "The square is " << s2 << endl;
}


void table(){
int m;
int n;
cout << "Please enter two integers!\n";
cin >> n >> m;
Matrix<int,2> t(n,m);
for(int i=0;i<t.dim1();i++){
	cout << endl; //this isn't needed if you want to print out as a line
	for(int j=0;j<t.dim2();j++){
		t(i,j)=(i+1)*(j+1); //only added the +1 to get nicer numbers and less zeros
		cout << t(i,j) << ' ';
	}
}
cout << "\n\n";

}



int main(){
try{
cout << "The size of char is: " << sizeof(char) << endl;
cout << "The size of short is: " << sizeof(short) << endl;
cout << "The size of int is: " << sizeof(int) << endl;
cout << "The size of long is: " << sizeof(long) << endl;
cout << "The size of float is: " << sizeof(float) << endl;
cout << "The size of double is: " << sizeof(double) << endl;
cout << "The size of int* is: " << sizeof(int*) << endl;
cout << "The size of double* is: " << sizeof(double*) << "\n\n";


Matrix<int>a(10);
Matrix<int>b(100);
Matrix<double>c(10);
Matrix<int,2>d(10,10);
Matrix<int,3>e(10,10,10);

cout << "The size of a is: " << sizeof(a) << endl;
cout << "The size of b is: " << sizeof(b) << endl;
cout << "The size of c is: " << sizeof(c) << endl;
cout << "The size of d is: " << sizeof(d) << endl;
cout << "The size of e is: " << sizeof(e) << "\n\n";;


cout << "The number of elements of a is: " << a.size() << endl;
cout << "The number of elements of b is: " << b.size() << endl;
cout << "The number of elements of c is: " << c.size() << endl;
cout << "The number of elements of d is: " << d.size() << endl;
cout << "The number of elements of e is: " << e.size() << "\n\n";;

/*
just for me, not part of the drill
cout << a.dim1() << endl;
cout << d.dim1() << endl;
cout << d.dim2() << endl;
*/

square();



double val;
Matrix<double>fp(10);
cout << "Please write down 10 double type numbers.\n";
for(int i=0;i<10;i++){
	cin>>val;
	if(cin.fail() || val==floor(val)) error("You mistyped the value.\n");
	fp[i]=val;
}
cout << "The matrix's values are ";
for(int i=0;i<10;i++)
	cout << fp[i] << ' ';
cout << endl;



table();



cout << "Please enter 10 complex numbers in this format:(Real, Imag)\n";
Matrix<complex<double>> compdoub(10);
for(int i=0;i<compdoub.size();i++){
	cin>>compdoub[i];
	if(cin.fail()) error("Problem with reading complex numbers!");
}
complex<double> sum;
cout << "Total " << accumulate(compdoub.data(),compdoub.data()+compdoub.size(),sum) << endl;
//accumulate(first, last, sum);
//not sure about this...




Matrix<int,2> m(2,3);
cout << "Please write 6 integers!\n";
for(int i=0;i<m.dim1();i++){
	for(int j=0;j<m.dim2();j++){
		cin>>m(i,j); // vagy m[i][j]
	}
}
cout << m << endl;



return 0;
	}
catch(exception &e){
	cout << "Exception: " << e.what() << endl;
}
catch(...){
	cout << "Error\n";
}

}