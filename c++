#include <iostream>
using namespace std;
int NOD(int x,int y){
  while(x * y != 0){
    if(x > y){
      x=x%y;
    }else{
      y=y%x;
    }
  }
  return x+y;
}
class Fraction{
  public:
    int numerator;
    int denumenator;
    Fraction(int Num,int Denum){
      if(Num * Denum > 0){
        this->numerator=abs(Num);
      }else{
        this->numerator=-abs(Num);
      }
      this->denumenator=abs(Denum);
    }
    Fraction(int Num){Fraction(Num,1);}
    Fraction(){Fraction(1,1);}
    friend std::ostream& operator <<(std::ostream& out , Fraction& p){
      int N , D, nod;
      N=p.numerator;
      D=p.denumenator;
      nod = NOD(N,D);
      N /= nod;
      D /= nod;
      out << N << "/" << D;
      return out;
    }
    Fraction& operator ++(){
      this->numerator+=this->denumenator;
      return *this;
    }
    Fraction& operator --(){
      this->numerator-=this->denumenator;
      return *this;
    }
    Fraction& operator +=(Fraction Y){
      this->numerator = this->numerator * Y.denumenator + Y.numerator * this->denumenator;
      this->denumenator = this->denumenator * Y.denumenator;
      return *this;
    }
    Fraction& operator -=(Fraction Y){
      this->numerator = this->numerator * Y.denumenator - Y.numerator * this->denumenator;
      this->denumenator = this->denumenator * Y.denumenator;
      return *this;
    }
    Fraction& operator *=(Fraction Y){
      this->numerator = this->numerator * Y.numerator;
      this->denumenator = this->denumenator * Y.denumenator;
      return *this;
    }
    Fraction& operator /=(Fraction Y){
      this->numerator = this->numerator * Y.denumenator;
      this->denumenator = this->denumenator * Y.numerator;
      return *this;
    }
    
};
void one(Fraction &X ,Fraction &Y){
  int n,d;
  n = X.numerator * Y.denumenator;
  d = X.denumenator * Y.denumenator;
  Y.numerator = X.denumenator * Y.numerator;
  Y.denumenator = X.denumenator * Y.denumenator;
  X.numerator = n;
  X.denumenator = d;
}
float ToFloat(Fraction X){
  return X.numerator/X.denumenator;
}
Fraction operator +(Fraction X,Fraction Y){
  int N , D;
  N = X.numerator * Y.denumenator + Y.numerator * X.denumenator;
  D = X.denumenator * Y.denumenator;
  return Fraction(N,D);
}
Fraction operator +(Fraction X,int Y){
  Fraction y(Y,1);
  return X+y;
}
Fraction operator +(int Y,Fraction X){
  Fraction y(Y,1);
  return X+y;
}
Fraction operator -(Fraction X,Fraction Y){
  int N , D;
  N = X.numerator * Y.denumenator - Y.numerator * X.denumenator;
  D = X.denumenator * Y.denumenator;
  return Fraction(N,D);
}
Fraction operator -(Fraction X,int Y){
  Fraction y(Y,1);
  return X-y;
}
Fraction operator -(int Y,Fraction X){
  Fraction y(Y,1);
  return y-X;
}
Fraction operator *(Fraction X,Fraction Y){
  int N , D;
  N = X.numerator * Y.numerator;
  D = X.denumenator * Y.denumenator;
  return Fraction(N,D);
}
Fraction operator *(Fraction X,int Y){
  Fraction y(Y,1);
  return X*y;
}
Fraction operator *(int Y,Fraction X){
  Fraction y(Y,1);
  return X*y;
}
Fraction operator /(Fraction X,Fraction Y){
  int N , D;
  N = X.numerator * Y.denumenator;
  D = X.denumenator * Y.numerator;
  return Fraction(N,D);
}
Fraction operator /(Fraction X,int Y){
  Fraction y(Y,1);
  return X/y;
}
Fraction operator /(int Y,Fraction X){
  Fraction y(Y,1);
  return y/X;
}
bool operator ==(Fraction X,Fraction Y){
  one(X,Y);
  if(X.numerator == Y.numerator){
    return true;
  }
  return false;
}
bool operator ==(Fraction X,int Y){
  Fraction y(Y,1);
  one(X,y);
  if(X.numerator == y.numerator){
    return true;
  }
  return false;
}
bool operator ==(int Y,Fraction X){
  Fraction y(Y,1);
  one(X,y);
  if(X.numerator == y.numerator){
    return true;
  }
  return false;
}
bool operator >=(Fraction X,Fraction Y){
  one(X,Y);
  if(X.numerator >= Y.numerator){
    return true;
  }
  return false;
}
bool operator >=(Fraction X,int Y){
  Fraction y(Y,1);
  one(X,y);
  if(X.numerator >= y.numerator){
    return true;
  }
  return false;
}
bool operator >=(int Y,Fraction X){
  Fraction y(Y,1);
  one(X,y);
  if(X.numerator <= y.numerator){
    return true;
  }
  return false;
}
bool operator <=(Fraction X,Fraction Y){
  one(X,Y);
  if(X.numerator <= Y.numerator){
    return true;
  }
  return false;
}
bool operator <=(Fraction X,int Y){
  Fraction y(Y,1);
  one(X,y);
  if(X.numerator <= y.numerator){
    return true;
  }
  return false;
}
bool operator <=(int Y,Fraction X){
  Fraction y(Y,1);
  one(X,y);
  if(X.numerator >= y.numerator){
    return true;
  }
  return false;
}
bool operator >(Fraction X,Fraction Y){
  one(X,Y);
  if(X.numerator > Y.numerator){
    return true;
  }
  return false;
}
bool operator >(Fraction X,int Y){
  Fraction y(Y,1);
  one(X,y);
  if(X.numerator > y.numerator){
    return true;
  }
  return false;
}
bool operator >(int Y,Fraction X){
  Fraction y(Y,1);
  one(X,y);
  if(X.numerator < y.numerator){
    return true;
  }
  return false;
}
bool operator <(Fraction X,Fraction Y){
  one(X,Y);
  if(X.numerator < Y.numerator){
    return true;
  }
  return false;
}
bool operator <(Fraction X,int Y){
  Fraction y(Y,1);
  one(X,y);
  if(X.numerator < y.numerator){
    return true;
  }
  return false;
}
bool operator <(int Y,Fraction X){
  Fraction y(Y,1);
  one(X,y);
  if(X.numerator > y.numerator){
    return true;
  }
  return false;
}
bool operator !=(Fraction X,Fraction Y){
  one(X,Y);
  if(X.numerator != Y.numerator){
    return true;
  }
  return false;
}
bool operator !=(Fraction X,int Y){
  Fraction y(Y,1);
  one(X,y);
  if(X.numerator != y.numerator){
    return true;
  }
  return false;
}
bool operator !=(int Y,Fraction X){
  Fraction y(Y,1);
  one(X,y);
  if(X.numerator != y.numerator){
    return true;
  }
  return false;
}
int main() {
  Fraction Q(1,2);
  Fraction W(1,3);
  Fraction E(1,2);
  Fraction Z = Q * E;
  Fraction X = Q / E;
  Fraction C = Q + E;
  Fraction V = Q - E;
  Fraction B = ++Q;
  Fraction N = --Q;
  Fraction T(1,1);
  T+=Q;
  Fraction H(1,1);
  T-=Q;
  Fraction I(1,1);
  T*=Q;
  Fraction J(1,1);
  T/=Q;
  Fraction K(1,1);
  Fraction L(2,1);
  bool z = K==L;
  bool x = K>=L;
  bool c = K<=L;
  bool v = K!=L;
  bool b = K<L;
  bool n = K>L;
  cout << Z << " " << X << " " << C << " " << V << " " << B << " " << N << " " << T << " " << H << " " << I << " " << J << " " << K << " " << L << " " << z << " " << x << " " << c << " " << v << " " << b << " " << n;
} 
