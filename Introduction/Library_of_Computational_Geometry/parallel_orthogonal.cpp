#include <iostream>
#include <vector>
#include "_point.hpp"
using namespace std;


int main(void){

	int q; cin >> q;
	rep(q){
		double xp0, yp0, xp1, yp1; cin>>xp0>>yp0>>xp1>>yp1;
		double xp2, yp2, xp3, yp3; cin>>xp2>>yp2>>xp3>>yp3;
		double _v1[2] = {xp1-xp0, yp1-yp0}; Vec2D _p1(_v1);
		double _v3[2] = {xp3-xp2, yp3-yp2}; Vec2D _p3(_v3);
		if (_p1.cross(_p3)==0) cout << "2" << endl;
		else if (_p1.dot(_p3)==0) cout << "1" << endl;
		else cout << "0" << endl;
	}
}