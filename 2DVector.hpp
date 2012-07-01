#ifndef INC_VECTOR_H
#define INC_VECTOR_H
template<class T> class Vector {
private:
  T _x;
  T _y;
public:
  Vector(T x, T y):_x(x),_y(y){}
  Vector():_x(T()),_y(T()){}
  ~Vector(){}

  inline T GetX() const {return _x;}
  inline T GetY() const {return _y;}

  inline void SetX(T x) {_x = x;}
  inline void SetY(T y) {_y = y;}

  Vector& operator+(const Vector<T>& v) {
    return Vector(v._x + _x, v._y + _y);
  }
  bool	  operator<(const Vector<T>& v);
  template<class X> friend  bool operator<(const Vector<X>&,const Vector<X>&);
 	
  
  
};

template<class T> bool Vector<T>::operator<(const Vector<T>& v) {
	if(_x < v._x) {
		return true;
	} else if(_x == v._x) {
		if(_y < v._y) return true;
	}
		return false;
}

template<class T>
bool operator<(const Vector<T>& a, const Vector<T>& b) {
	if(a._x < b._x) {
		return true;
	} else if(a._x == b._x) {
		if(a._y < b._y) {
			return true;
		}
	}
	return false;
}
#endif

