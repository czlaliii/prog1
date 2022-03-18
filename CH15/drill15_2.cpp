#include "std_lib_facilities.h"

struct Person{
private:
string Fname;
string Lname;
int Age;


public:
Person(){};
Person(string fname, string lname, int age):
	Fname{fname}, Lname{lname}, Age{age}{
	

		for(int i=0;i<fname.size();i++){
			if(fname[i]=='\'' || fname[i]=='"' || fname[i]==';' || fname[i]==':' || fname[i]=='[' || fname[i]==']' || fname[i]=='*' ||
				fname[i]=='&' || fname[i]=='^' || fname[i]=='&' || fname[i]=='#' || fname[i]=='%' || fname[i]=='#' || fname[i]=='@' ||
				fname[i]=='!')
				error("Invalid first name");
		}
		for(int i=0;i<lname.size();i++){
			if(lname[i]=='\'' || lname[i]=='"' || lname[i]==';' || lname[i]==':' || lname[i]=='[' || lname[i]==']' || lname[i]=='*' ||
				lname[i]=='&' || lname[i]=='^' || lname[i]=='&' || lname[i]=='#' || lname[i]=='%' || lname[i]=='#' || lname[i]=='@' ||
				lname[i]=='!')
				error("Invalid last name");
		}

			if (0>age || age>=150)
			 error("Invalid age");
	}

	string fname()const{
		return Fname;
	}
	string lname()const{
		return Lname;
	}
	int age()const{
		return Age;
	}




};



ostream &operator << (ostream& os, const Person &p){ //if I write this line with friend type in struct, it works with protected and private too
	os << "The person's name is " << p.fname() << " " << p.lname() <<" and the age is " << p.age() << '\n';
	return os;
}


istream &operator >> (istream& is, Person &p){
	string fname;
	string lname;
	int age;

	is >> fname;
	for(int i=0;i<fname.size();i++){
	if(isdigit(fname[i]))
		error("You mistyped the first name!\n");}


	is >> lname;
	for(int i=0;i<lname.size();i++){
	if(isdigit(lname[i]))
		error("You mistyped the last name!\n");}
	is >> age;
	
	if(cin.fail()) // or: if(!is)
		error("You mistyped the age!\n");

	p = Person(fname, lname, age);
	return is;

}


int main(){
try{

	Person p1 = Person("Goofy","Goofy",63);
	cout << p1.fname()  << " " << p1.lname()  << " " << p1.age() << endl;
	//person.Name="Goofy";
	//person.Age=63;
	//cout << "The person's name is " << person.Name <<" and the age is " << person.Age << '\n';
	cout << "Please write a first name, a last name and an age.\n";
	Person p2;
	cin >> p2;
	cout << p2;


	cout << "Please write the names and the ages you want to put in the vector. If you want to exit, please write: 'exit vector 0'!\n";
	vector<Person> p3;
	Person p;
	while(cin>>p){
		if(p.fname() == "exit" && p.lname()=="vector" && p.age()==0) break;
			p3.push_back(p);

					}

	for(Person pvegso : p3){
			cout << pvegso <<  endl;
							}	


	return 0;
			}

catch(exception &e){
	cerr << "Exception:" << e.what() << endl;
	return 1;
}
catch(...){
	cerr << "Error\n";
	return 2;
}


}
