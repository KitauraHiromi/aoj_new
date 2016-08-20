#ifndef __VECD__
#define __VECD__
#include <vector>
#include <numeric>
#include <iomanip>
#define rep(n) for(int i=0;i<n;i++)
#define PB push_back
#endif

class VecD;
// class Vec3D;
// class Vec2D;
// void send(FILE* f, char* p, int n);
// void send(std::ostream* f, char* p, int n);
const VecD projection(const VecD &p1, const VecD &p2);

class VecD{
friend const double operator*(const VecD&, const VecD&);
template <class T> friend const VecD operator*(const T&, const VecD&);
template <class T> friend const VecD operator*(const VecD&, const T&);
friend const VecD operator+(const VecD&, const VecD&);
template <class T> friend const VecD operator+(const T&, const VecD&);
template <class T> friend const VecD operator+(const VecD&, const T&);
friend const VecD operator-(const VecD&);
friend const VecD operator-(const VecD&, const VecD&);
template <class T> friend const VecD operator-(const T&, const VecD&);
template <class T> friend const VecD operator-(const VecD&, const T&);
// template <class W> friend W& operator<<(W&, const VecD&);
friend std::ostream& operator<<(std::ostream&, const VecD&);

public:
	VecD(){};
	VecD(std::vector<double> v){
		vec = v;
	}
	std::vector<double> vec;
};

// class Vec3D: public VecD{
// public:
// 	Vec3D(){};
// 	Vec3D(std::vector<double> v){
// 		vec = v;
// 	}
// 	std::vector<double> vec;
// };

// class Vec2D: public VecD{
// 	public:
// 		Vec2D(std::vector<double> v){
// 			VecD(v);
// 			if(vec.size()!=2){
// 				std::cout << "size error" << std::endl;
// 			}
// 		}
// 	friend const Vec2D cross(const Vec2D, const Vec2D);
// };

const double operator*(const VecD &p0, const VecD &p1){ return inner_product( p0.vec.begin(), p0.vec.end(), p1.vec.begin(), 0); }
template <class T>
const VecD operator*(const T &a, const VecD &p1){
	std::vector<double> v;
	for(std::vector<double>::const_iterator iter1=p1.vec.begin();iter1!=p1.vec.end();iter1++) v.PB(*iter1 * a);
	const VecD p(v);
	return p;
}
template <class T>
const VecD operator* (const VecD &p, const T &a){return a*p;}
const VecD operator+(const VecD &p0, const VecD &p1){
	std::vector<double> v;
	std::vector<double>::const_iterator iter0 = p0.vec.begin();
	for(std::vector<double>::const_iterator iter1=p1.vec.begin();iter1!=p1.vec.end();iter1++){
		v.PB(*iter0 + *iter1);
		iter0++;
	}
	const VecD p(v);
	return p;
}
template <class T>
const VecD operator+(const T &a, const VecD &p1){
	std::vector<double> v;
	for(std::vector<double>::const_iterator iter1=p1.vec.begin();iter1!=p1.vec.end();iter1++){
		v.PB(*iter1 + a);
	}
	const VecD p(v);
	return p;
}
template <class T>
const VecD operator+(const VecD &p1, const T &a){return a+p1;}
const VecD operator-(const VecD &p1){return (-1)*p1;}
const VecD operator-(VecD &p0, VecD &p1){ return p0+(-p1); }
template <class T>
const VecD operator-(const T &a, VecD &p1){ return a+(-p1); }
template <class T>
const VecD operator-(VecD &p1, const T &a){return (-a)+p1;}

// template <class W>
// W& operator<<(W& w, const VecD& p){
// 	for(std::vector<double>::const_iterator iter=p.vec.begin(); iter!=p.vec.end(); iter++){
// 		char c[8];
// 		sprintf(c, "%lf", *iter);
// 		send(w, c, 1);
// 	}
// 	return w;
// }

const VecD projection(const VecD &p1, const VecD &p2){
	// cout << p1*p2 << endl;
	return ((p1*p2) / (p1*p1)) * p1;
}

std::ostream& operator<<(std::ostream &os, const VecD &p){
	os << std::fixed << std::setprecision(10) << p.vec[0] << " " << std::fixed << std::setprecision(10) << p.vec[1] << std::endl;
}
// void send(FILE* f, char* p, int n){
// 	for (int i=0; i<n; i++){
// 		fputs(p++, f);
// 	}
// }
// void send(std::ostream* o, char* p, int n){
// 	for (int i=0; i<n; i++){
// 		// fputs(p++, f);
// 		o << *p;
// 	}
// }