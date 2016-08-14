#include <iostream>
#include <vector>
#include "point.hpp"
using namespace std;

int main(void){
	double xp0, yp0, xp1, yp1; cin >> xp0 >> yp0 >> xp1 >> yp1;
	unsigned int q; cin >> q;
	VecD v0; v0.PB(xp0); v0.PB(yp0); Point p0(v0);
	VecD v1; v1.PB(xp1); v1.PB(yp1); Point p1(v1);
	Point _p0 = p0-p0;
	Point _p1 = p1-p0;
	rep(q){
		double xp2, yp2; cin >> xp2 >> yp2;
		VecD v2; v2.PB(xp2); v2.PB(yp2); Point p2(v2);
		Point _p2 = p2-p0;
		Point _ref = (projection(_p1, _p2) - _p2) * 2;
		Point ref = _ref+p2;
		cout << ref << endl;
	}
}