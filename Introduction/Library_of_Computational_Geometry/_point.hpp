#define TEST_MODE 1

#ifndef __VECD__
#define __VECD__
#include <vector>
#include <numeric>
#include <iomanip>
#include <stdlib.h>
#define rep(n) for(int i=0;i<n;i++)
#define PB push_back
#define VecND VecD<std::vector<double> >
#define Vec3D _VecD<double, 3>
#define Vec2D _VecD<double, 2>
#endif

template <typename U>                       class VecD;
template <typename TYPE, unsigned int SIZE> class _VecD;

template <typename U> const VecD<U> projection(const VecD<U> &p1, const VecD<U> &p2);

template <typename U> class VecD{
template <typename DUMMY>      friend const double operator*(const VecD&, const VecD&);
template <typename T>          friend const VecD operator*(const T&, const VecD&);
template <typename T, class C> friend const C operator*(const C&, const T&);
template <typename DUMMY>      friend const VecD operator+(const VecD&, const VecD&);
template <typename T>          friend const VecD operator+(const T&, const VecD&);
template <typename T, class C> friend const C operator+(const C&, const T&);
template <class C>             friend const C operator-(const C&);
template <class C>             friend const C operator-(const C&, const C&);
template <typename T, class C> friend const C operator-(const T&, const C&);
template <typename T, class C> friend const C operator-(const C&, const T&);
template <typename DUMMY>      friend std::ostream& operator<<(std::ostream&, const VecD&);
public:
	U vec;
	VecD(){}
	VecD(U v){
		vec = v;
	}
	const double dot(const VecD &p) const{
		return inner_product( this->vec.begin(), this->vec.end(), p.vec.begin(), 0);
	}
};

template <typename TYPE, unsigned int SIZE> class _VecD{
template <typename DUMMY>      friend const double operator*(const _VecD&, const _VecD&);
template <typename T>          friend const _VecD operator*(const T&, const _VecD&);
template <typename T, class C> friend const C operator*(const C&, const T&);
template <typename DUMMY>      friend const _VecD operator+(const _VecD&, const _VecD&);
template <typename T>          friend const _VecD operator+(const T&, const _VecD&);
template <typename T, class C> friend const C operator+(const C&, const T&);
template <class C>             friend const C operator-(const C&);
template <class C>             friend const C operator-(const C&, const C&);
template <typename T, class C> friend const C operator-(const T&, const C&);
template <typename T, class C> friend const C operator-(const C&, const T&);
template <typename DUMMY>      friend std::ostream& operator<<(std::ostream&, const _VecD&);

public:
	TYPE vec[SIZE];
	_VecD(){}
	_VecD(TYPE (&array)[SIZE]){
		for(int i=0; i<SIZE; i++) vec[i] = array[i];
	}
	const double dot(const _VecD &p) const{
		double tmp = 0;
		for(int i=0; i<SIZE; i++) tmp += this->vec[i] * p.vec[i];
		return tmp;
	}
	const double cross(const Vec2D &p) const{
		return this->vec[0]*p.vec[1] - this->vec[1]*p.vec[0];
	}
	const Vec3D cross(const Vec3D &p) const{
		double v[3];
		v[0] = this->vec[1]*p.vec[2] - this->vec[2]*p.vec[1];
		v[1] = this->vec[2]*p.vec[0] - this->vec[0]*p.vec[2];
		v[2] = this->vec[0]*p.vec[1] - this->vec[1]*p.vec[0];
		return Vec3D(v);
	}
};

const double operator*(const VecND &p0, const VecND &p1){ return inner_product( p0.vec.begin(), p0.vec.end(), p1.vec.begin(), 0); }
// template <typename U>
// const double operator*(const VecD<U> &p0, const VecD<U> &p1){ return inner_product( p0.vec.begin(), p0.vec.end(), p1.vec.begin(), 0); }

template <typename T>
const VecND operator*(const T &a, const VecND &p1){
	std::vector<double> v;
	for(std::vector<double>::const_iterator iter1=p1.vec.begin();iter1!=p1.vec.end();iter1++) v.PB(*iter1 * a);
	const VecND p(v);
	return p;
}
template <typename T>
const Vec2D operator*(const T &a, const Vec2D &p1){
	double v[2];
	for(int i=0; i<2; i++) v[i] = p1.vec[i] * a;
	const Vec2D p(v);
	return p;
}
template <typename T>
const Vec3D operator*(const T &a, const Vec3D &p1){
	double v[3];
	for(int i=0; i<3; i++) v[i] = p1.vec[i] * a;
	const Vec3D p(v);
	return p;
}

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
const Vec2D operator+(const Vec2D &p0, const Vec2D &p1){
	double v[2];
	for(int i=0; i<2; i++) v[i] = p0.vec[i] + p1.vec[i];
	const Vec2D p(v);
	return p;
}
const Vec3D operator+(const Vec3D &p0, const Vec3D &p1){
	double v[3];
	for(int i=0; i<3; i++) v[i] = p0.vec[i] + p1.vec[i];
	const Vec3D p(v);
	return p;
}
template <class T>
const VecND operator+(const T &a, const VecND &p1){
	std::vector<double> v;
	for(std::vector<double>::const_iterator iter1=p1.vec.begin();iter1!=p1.vec.end();iter1++){
		v.PB(*iter1 + a);
	}
	const VecND p(v);
	return p;
}
template <class T>
const Vec2D operator+(const T &a, const Vec2D &p1){
	double v[2];
	for(int i=0; i<2; i++) v[i] = p1.vec[i] + a;
	const Vec2D p(v);
	return p;
}
template <class T>
const Vec3D operator+(const T &a, const Vec3D &p1){
	double v[3];
	for(int i=0; i<3; i++) v[i] = p1.vec[i] + a;
	const Vec3D p(v);
	return p;
}
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

// template<class C>
// const C projection(const C &p1, const C &p2){
// 	return ((p1*p2) / (p1*p1)) * p1;
// }
template<typename U>
const VecD<U> projection(const VecD<U> &p1, const VecD<U> &p2){
	return ((p1.dot(p2)) / (p1.dot(p1))) * p1;
}

const Vec2D projection(const Vec2D &p1, const Vec2D &p2){
	return ((p1.dot(p2)) / (p1.dot(p1))) * p1;
}
const Vec3D projection(const Vec3D &p1, const Vec3D &p2){
	return ((p1.dot(p2)) / (p1.dot(p1))) * p1;
}

std::ostream& operator<<(std::ostream &os, const VecND &p){
	os << std::fixed << std::setprecision(10) << p.vec[0] << " " << std::fixed << std::setprecision(10) << p.vec[1] << std::endl;
}
std::ostream& operator<<(std::ostream &os, const Vec2D &p){
	os << std::fixed << std::setprecision(10) << p.vec[0] << " " << std::fixed << std::setprecision(10) << p.vec[1] << std::endl;
}
std::ostream& operator<<(std::ostream &os, const Vec3D &p){
	os << std::fixed << std::setprecision(10) << p.vec[0] << " " << std::fixed << std::setprecision(10) << p.vec[1] << std::endl;
}