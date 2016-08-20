#ifndef __VECD__
#define __VECD__
#include <vector>
#include <numeric>
#include <iomanip>
// #include <stdlib.h>
#define rep(n) for(int i=0;i<n;i++)
#define PB push_back
#define VecND VecD<std::vector<double> >
// #define Vec3D VecD<double (&) [3]>
// #define Vec2D VecD<double (&) [2]>
#endif

// void initialize(double &v){
// 	for(int i=0; i<sizeof(v); i++) v[i] = 0;
// }

template <typename U>
class VecD;

template <typename U>
const VecD<U> projection(const VecD<U> &p1, const VecD<U> &p2);

template <typename U>
class VecD{
friend const double operator*(const VecD&, const VecD&);

template <typename T>          friend const VecD operator*(const T&, const VecD&);
template <typename T, class C> friend const C operator*(const C&, const T&);
                               friend const VecD operator+(const VecD&, const VecD&);
template <typename T>          friend const VecD operator+(const T&, const VecD&);
template <typename T, class C> friend const C operator+(const C&, const T&);
template <class C>             friend const C operator-(const C&);
template <class C>             friend const C operator-(const C&, const C&);
template <typename T, class C> friend const C operator-(const T&, const C&);
template <typename T, class C> friend const C operator-(const C&, const T&);
                               friend std::ostream& operator<<(std::ostream&, const VecD&);

public:
	VecD(){};
	VecD(U& v){
		// vec = (U)malloc(sizeof(U));
		vec = v;
	}
	U vec;
};

const double operator*(const VecD<std::vector<double> > &p0, const VecD<std::vector<double> > &p1){ return inner_product( p0.vec.begin(), p0.vec.end(), p1.vec.begin(), 0); }
// template <typename U>
// const double operator*(const VecD<U> &p0, const VecD<U> &p1){ return inner_product( p0.vec.begin(), p0.vec.end(), p1.vec.begin(), 0); }

template <typename T>
const VecND operator*(const T &a, const VecND &p1){
	std::vector<double> v;
	for(std::vector<double>::const_iterator iter1=p1.vec.begin();iter1!=p1.vec.end();iter1++) v.PB(*iter1 * a);
	const VecND p(v);
	return p;
}
// template <typename T>
// const Vec2D operator*(const T &a, const Vec2D &p1){
// 	double v[2] = {0, 0};
// 	for(int i=0; i<2; i++) v[i] = p1.vec[i] * a;
// 	const Vec2D p(v);
// 	return p;
// }
// template <typename T>
// const Vec3D operator*(const T &a, const Vec3D &p1){
// 	double v[3] = {0, 0, 0};
// 	for(int i=0; i<3; i++) v[i] = p1.vec[i] * a;
// 	const Vec3D p(v);
// 	return p;
// }
template <typename T, class C>
const C operator* (const C &p, const T &a){return a*p;}
const VecND operator+(const VecND &p0, const VecND &p1){
	std::vector<double> v;
	std::vector<double>::const_iterator iter0 = p0.vec.begin();
	for(std::vector<double>::const_iterator iter1=p1.vec.begin();iter1!=p1.vec.end();iter1++){
		v.PB(*iter0 + *iter1);
		iter0++;
	}
	const VecND p(v);
	return p;
}
// const Vec2D operator+(const Vec2D &p0, const Vec2D &p1){
// 	double v[2] = {0, 0};
// 	for(int i=0; i<2; i++) v[i] = p0.vec[i] + p1.vec[i];
// 	const Vec2D p(v);
// 	return p;
// }
// const Vec3D operator+(const Vec3D &p0, const Vec3D &p1){
// 	double v[3] = {0, 0, 0};
// 	for(int i=0; i<3; i++) v[i] = p0.vec[i] + p1.vec[i];
// 	const Vec3D p(v);
// 	return p;
// }
template <class T>
const VecND operator+(const T &a, const VecND &p1){
	std::vector<double> v;
	for(std::vector<double>::const_iterator iter1=p1.vec.begin();iter1!=p1.vec.end();iter1++){
		v.PB(*iter1 + a);
	}
	const VecND p(v);
	return p;
}
// template <class T>
// const Vec2D operator+(const T &a, const Vec2D &p1){
// 	double v[2];
// 	for(int i=0; i<2; i++) v[i] = p1.vec[i] + a;
// 	const Vec2D p(v);
// 	return p;
// }
// template <class T>
// const Vec3D operator+(const T &a, const Vec3D &p1){
// 	double v[3];
// 	for(int i=0; i<3; i++) v[i] = p1.vec[i] + a;
// 	const Vec3D p(v);
// 	return p;
// }
template <typename T, class C>
const C operator+(const C &p1, const T &a){return a+p1;}
template <class C>
const C operator-(const C &p1){return (-1)*p1;}
template <class C>
const C operator-(C &p0, C &p1){ return p0+(-p1); }
template <typename T, class C>
const C operator-(const T &a, C &p1){ return a+(-p1); }
template <typename T, class C>
const C operator-(C &p1, const T &a){return (-a)+p1;}

const VecD<std::vector<double> > projection(const VecD<std::vector<double> > &p1, const VecD<std::vector<double> > &p2){
	// cout << p1*p2 << endl;
	return ((p1*p2) / (p1*p1)) * p1;
}
// template<typename U>
// const VecD<U> projection(const VecD<U> &p1, const VecD<U> &p2){
// 	// cout << p1*p2 << endl;
// 	return ((p1*p2) / (p1*p1)) * p1;
// }

std::ostream& operator<<(std::ostream &os, const VecD<std::vector<double> > &p){
	os << std::fixed << std::setprecision(10) << p.vec[0] << " " << std::fixed << std::setprecision(10) << p.vec[1] << std::endl;
}
// template <typename U>
// std::ostream& operator<<(std::ostream &os, const VecD<U> &p){
// 	os << std::fixed << std::setprecision(10) << p.vec[0] << " " << std::fixed << std::setprecision(10) << p.vec[1] << std::endl;
// }