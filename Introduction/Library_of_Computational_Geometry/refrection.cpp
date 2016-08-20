#include <iostream>
#include <vector>
#include "point.hpp"
using namespace std;

int main(void){
	double xp0, yp0, xp1, yp1; cin >> xp0 >> yp0 >> xp1 >> yp1;
	unsigned int q; cin >> q;
	vector<double> v0; v0.PB(xp0); v0.PB(yp0); VecD p0(v0);
	vector<double> v1; v1.PB(xp1); v1.PB(yp1); VecD p1(v1);
	VecD _p0 = p0-p0;
	VecD _p1 = p1-p0;
	rep(q){
		double xp2, yp2; cin >> xp2 >> yp2;
		vector<double> v2; v2.PB(xp2); v2.PB(yp2); VecD p2(v2);
		VecD _p2 = p2-p0;
		VecD _ref = (projection(_p1, _p2) - _p2) * 2;
		VecD ref = _ref+p2;
		cout << ref << endl;
	}
}