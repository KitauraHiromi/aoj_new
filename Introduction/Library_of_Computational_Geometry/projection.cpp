#include <vector>
#include <numeric>
#include <iostream>
#include <stdio.h>
#include <stdlib.h>
using namespace std;
typedef vector<double> VecD;
#define rep(n) for(int i=0;i<n;i++)
#define PB push_back

class Point{
friend const double operator*(Point &, Point &);
friend const Point operator*(double, Point &);
friend const Point operator*(Point &, double);
friend const Point operator+(Point &, Point &);
friend const Point operator+(double, Point &);
friend const Point operator+(Point &, double);
friend const Point operator-(Point &);
friend const Point operator-(Point &, Point &);
friend const Point operator-(double, Point &);
friend const Point operator-(Point &, double);

public:
	Point(){};
	Point(VecD v){
		point = v;
	}
	VecD point;
};

const double operator*(Point &p0, Point &p1){ return inner_product( p0.point.begin(), p1.point.begin(), p0.point.end(), 0); }
const Point operator*(double a, Point &p1){
	VecD v;
	Point p(v);
	for(VecD::iterator iter1=p1.point.begin();iter1!=p1.point.end();iter1++) v.PB(*iter1 * a);
	return p; 
}
//const Point operator* (Point &p, double a){return a*p;}
const Point operator+(Point &p0, Point &p1){
	VecD v;
	Point p(v);
	VecD::iterator iter0 = p0.point.begin();
	for(VecD::iterator iter1=p1.point.begin();iter1!=p1.point.end();iter1++){
		v.PB(*iter0 + *iter1);
		iter0++;
	}
	return p;
}
const Point operator+(double a, Point &p1){
	VecD v;
	Point p(v);
	for(VecD::iterator iter1=p1.point.begin();iter1!=p1.point.end();iter1++){
		v.PB(*iter1 + a);
	}
	return p;
}
//const Point operator+(Point &p1, double a){return a+p1;}
const Point operator-(Point &p1){
	VecD v;
	Point p(v);
	for(VecD::iterator iter1=p1.point.begin();iter1!=p1.point.end();iter1++) v.PB(*iter1 * (-1));
	return p; 
}
//const Point operator-(Point &p0, Point &p1){ return p0+(-p1); }
//const Point operator-(double a, Point &p1){ return a+(-p1); }
//const Point operator-(Point &p1, double a){return (-a)+p1;}



const Point projection(Point v1, Point v2){
	return (v1*v2) / (v1*v1) * v1;
}

int main(void){
	VecD v0(3,1);
	VecD v1(3,2);
	Point p0(v0);
	Point p1(v1);
	Point p = p0+p1;
	double a = 1;
	cout << p.point[0] << endl;
/*
	double xp0, yp0, xp1, yp1; cin>>xp0>>yp0>>xp1>>yp1;
	int q; cin >> q;
	VecD v0; v0.PB(xp0); v0.PB(yp0); Point p0(v0);
	VecD v1; v1.PB(xp1); v1.PB(yp1); Point p1(v1);
	p1 = p1+p0;
	rep(q){
		double xp2,yp2; cin>>xp2>>yp2;
		VecD v2; v2.PB(xp2); v2.PB(yp2); Point p2(v2);
		Point ret = projection(p1, p2);
		cout << "%f %f", %(ret.point[0], ret.point[1]) << endl;;
	}
	*/
}