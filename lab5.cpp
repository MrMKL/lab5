#include <iostream>
#include <string>
#include <sstream>

using namespace std;

class HugeInt {
  
  friend double operator + (HugeInt & Obj, HugeInt & Obj_2);
  friend double operator - (HugeInt & Obj, HugeInt & Obj_2);
  friend istream & operator>> (istream & in, HugeInt & n);
  friend ostream & operator << (ostream & out, const HugeInt & p);
  
  public : 
    HugeInt & operator = (const HugeInt & r) {
        x = r.x;
    }
    HugeInt() {
      x = 0;
      result = 0;
    }
    HugeInt(double j) {
      x = j;
      result = 0;
    }
    HugeInt(string k) {
      ss << k;
      ss >> x;
      result = 0;
    }

  private :
    double x;
    double result;
    stringstream ss;
    
};

double operator + (HugeInt & Obj, HugeInt & Obj_2) { 
  return Obj.x + Obj_2.x; 
}


double operator - (HugeInt & Obj, HugeInt & Obj_2) {
  return Obj.x - Obj_2.x;  
}


istream & operator >>(istream & in, HugeInt& n) {
  in >> n.x;
  return in;
}  


ostream & operator <<(ostream &out, const HugeInt &p) {
  if (p.x) {
    out << p.x;    
  } 
  if (p.result) {
    out << p.result;
  }
  return out;
}


int main() {
  HugeInt x;
  HugeInt y(28825252);
  HugeInt z("314159265358979323846");
  HugeInt result;
  cin >> x;
  result = x + y;
  cout << x << "+" << y << " = " << result << endl;
  result = z - x;
  cout << result << endl;
  return 0;
}

