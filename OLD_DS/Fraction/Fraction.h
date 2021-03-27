#include<iostream> 
#include<math.h>
using namespace std;

class Fraction{
	private:
		int num, deno; 
	public: 
  //Constructor 1 with no arguments
	Fraction(){
	} 
  //Constructor 2 with one argument
	Fraction(int num){
		this-> num = num ;
		this->deno = 1; 
	}
  //Constructor 3 with two arguments  
	Fraction(int num, int den){
		this-> num = (den < 0)?(-num):(num);
		this->deno = abs(den); 
		simplify(*this);
	}
  // Ask for Data; 
	void putData(int num, int deno=1){
		this-> num = (deno < 0)?(-num):(num);
		this->deno = abs(deno); 
		if(this->deno == 0){
			this->deno = 1; 
			cout << "Denominator can't be zero, because it is not defined(Default Value will be 1).\n";
		}
		simplify(*this);
	}
  // Get Data; 
	void getData(){
		cout << this->num;
		(this->deno != 1)?(cout << "/" << this->deno << endl):(cout << endl); 
	}
  
  //Simplify the Fraction; 
	void simplify(Fraction &f){
		int i = 2; 
		while(i <= (min(f.deno, abs(f.num)))){
			if(abs(f.deno)%i==0 && abs(f.num)%i==0){
				int sign = (f.num < 0)?(-1):(+1);
				f.deno = f.deno/i, f.num = sign*abs(f.num)/i; 
			}else{
				i++;
			}
		}
		if(f.num == 0) f.deno = 0; 
		if(f.deno == 0){
			f.deno = -1; 
			cout << "Denominator can't be zero, because it is not defined(Default Value will be -1).\n";
		}
	}
  
  //Operator overloading of Plus(+) Operator
	Fraction operator + (Fraction &f){
		Fraction f3; 
		f3.num = (f.num*this->deno) + (f.deno*this->num);
		f3.deno = f.deno*this->deno;   
		simplify(f3);
		return f3; 
	}
  //Operator overloading of Minus(-) Operator
	Fraction operator - (Fraction &f){
		Fraction f3; 
		f3.num = (f.deno*this->num) - (f.num*this->deno);
		f3.deno = f.deno*this->deno;   
		simplify(f3);
		return f3; 
	}
  //Operator overloading of star(*) Operator
	Fraction operator * (Fraction &f){
		Fraction f3; 
		f3.num = f.num*this->num;
		f3.deno = f.deno*this->deno;   
		simplify(f3);
		return f3; 
	}
  //Operator overloading of Caret(^) Operator
	Fraction operator ^ (int num){
		Fraction f; 
		f.num = pow(this->num, num); 
		f.deno = pow(this->deno, num);
		simplify(f); 
		return f; 
	}
};
