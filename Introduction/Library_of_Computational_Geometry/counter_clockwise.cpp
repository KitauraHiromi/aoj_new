#include <iostream>
#include <vector>
#include "_point.hpp"
using namespace std;

int main(void){

	double xp0, yp0, xp1, yp1; cin>>xp0>>yp0>>xp1>>yp1;
	int q; cin >> q;
	double v0[2] = {xp0, yp0}; Vec2D p0(v0);
	double v1[2] = {xp1, yp1}; Vec2D p1(v1);
	Vec2D _p0 = p0-p0;
	Vec2D _p1 = p1-p0;
	rep(q){
		double xp2,yp2; cin>>xp2>>yp2;
		double v2[2] = {xp2, yp2}; Vec2D p2(v2);
		Vec2D _p2 = p2-p0;
		double ret1 = _p1.cross(_p2);
		if(ret1>0){
			cout << "COUNTER_CLOCKWISE" << endl;
		}else if(ret1<0){
			cout << "CLOCKWISE" << endl;;
		}else{
			double ret2;
			if(_p1.vec[0]!=0){
				ret2 = _p2.vec[0]/_p1.vec[0];
			}else{
				ret2 = _p2.vec[1]/_p1.vec[1];
			}
			if(ret2<0){
				cout << "ONLINE_BACK" << endl;
			}else if(ret2<1){
				cout << "ON_SEGMENT" << endl;
			}else{
				cout << "ONLINE_FRONT" << endl;
			}
		}
	}
}