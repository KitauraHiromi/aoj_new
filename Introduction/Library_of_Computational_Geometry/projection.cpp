#include <iostream>
#include <vector>
#include "point.hpp"
using namespace std;


int main(void){

	double xp0, yp0, xp1, yp1; cin>>xp0>>yp0>>xp1>>yp1;
	int q; cin >> q;
	vector<double> v0; v0; v0.PB(xp0); v0.PB(yp0); Point p0(v0);
	vector<double> v1; v1.PB(xp1); v1.PB(yp1); Point p1(v1);
	p1 = p1-p0;
	// cout << p1.point[0] << " " << p1.point[1] << endl;
	rep(q){
		double xp2,yp2; cin>>xp2>>yp2;
		VecD v2; v2.PB(xp2); v2.PB(yp2); Point p2(v2);
		p2 = p2-p0;
		Point ret = projection(p1, p2);
		ret = ret+p0;
		cout << ret << endl;
	}
}