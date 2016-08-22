#include <iostream>
#include <vector>
#include "_point.hpp"
using namespace std;


int main(void){

	double xp0, yp0, xp1, yp1; cin>>xp0>>yp0>>xp1>>yp1;
	int q; cin >> q;
	// vector<double> v0; v0.PB(xp0); v0.PB(yp0); VecND p0(v0);
	// vector<double> v1; v1.PB(xp1); v1.PB(yp1); VecND p1(v1);
	double v0[2] = {xp0, yp0}; Vec2D p0(v0);
	double v1[2] = {xp1, yp1}; Vec2D p1(v1);
	p1 = p1-p0;
	// cout << p1.point[0] << " " << p1.point[1] << endl;
	rep(q){
		double xp2,yp2; cin>>xp2>>yp2;
		// vector<double> v2; v2.PB(xp2); v2.PB(yp2); VecND p2(v2);
		double v2[2] = {xp2, yp2}; Vec2D p2(v2);
		p2 = 1*(p2-p0);
		// VecND ret = projection(p1, p2);
		Vec2D ret = projection(p1, p2);
		ret = ret+p0;
		cout << ret << endl;
	}
}