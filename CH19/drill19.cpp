
#include "std_lib_facilities.h"

template<typename T> struct S {
private:
                T val;


public:
		S(){};
	        S(T value) : val{value}{}
                T& get();
                const T& get() const;
              /* void setT(T vv){
                        val=vv;
                }*/
                S<T>& operator=(const T&);
                void read_val(T& v);

				};
template<typename T> T& S<T>::get(){
        return val;
}
template<typename T> const T& S<T>::get() const{
        return val;
}


template<typename T> S<T>& S<T>::operator=(const T& s){
        val = s;
        return *this;
}
template<typename T>void read_val(T& v){
        cin >> v;
}



int main(){
S<int> num {10};
S<char> charac {'c'};
S<double> num2 {21.2};
S<string> st {"String"};
S<vector<int>> vec {vector<int>{1, 1, 2, 3, 5, 8}};


cout << "S<int> : " << num.get() <<endl;
cout << "S<char> : " << charac.get() <<endl;
cout << "S<double> : " << num2.get() <<endl;
cout << "S<string> : " << st.get() <<endl;


for(auto endvec: vec.get()){
                cout<< endvec <<' ';
        }
        cout<<endl;


/*charac.setT('s');
cout << "S<char> : " << charac.get() <<endl;*/

charac={'o'};
cout <<"S<char> : " << charac.get() <<endl;

cout << "Please write an integer: ";
int num3;
read_val(num3);
S<int>num32{num3};

cout << "Please write a character: ";
char charac2;
read_val(charac2);
S<char>charac22{charac2};

cout << "Please write a double: ";
double num4;
read_val(num4);
S<double>num42{num4};

cout << "Please write a string: ";
string st2;
read_val(st2);
S<string>st22{st2};

cout << "S<int> : " << num32.get() <<endl;
cout << "S<char> : " << charac22.get() <<endl;
cout << "S<double> : " << num42.get() <<endl;
cout << "S<string> : " << st22.get() <<endl;


	return 0;
}
