#include <iostream>
using namespace std;
#define rep(n) for(int i=0;i<n;i++)

double abs(double x){
	if(x>0) return x;
	else return -x;
}

int main(void){
	int q; cin >> q;
	rep(q){
		double xp0, yp0, xp1, yp1; cin>>xp0>>yp0>>xp1>>yp1;
		double xp2, yp2, xp3, yp3; cin>>xp2>>yp2>>xp3>>yp3;
		double t0 = (xp2-xp3)*(yp0-yp2) - (yp2-yp3)*(xp0-xp2);
		double t1 = (xp2-xp3)*(yp1-yp2) - (yp2-yp3)*(xp1-xp2);
		double t2 = (xp0-xp1)*(yp2-yp0) - (yp0-yp1)*(xp2-xp0);
		double t3 = (xp0-xp1)*(yp3-yp0) - (yp0-yp1)*(xp3-xp0);
		double o1 = (xp0+xp1)/2; double o2 = (xp2+xp3)/2; double o3 = (yp0+yp1)/2; double o4 = (yp2+yp3)/2;
		double r1 = abs(xp0-xp1)/2; double r2 = abs(xp2-xp3)/2; double r3 = abs(yp0-yp1)/2; double r4 = abs(yp2-yp3)/2;
		int ret = 0;
		// parallel
		if((t0==0 && t1==0) || (t2==0 && t3==0)){
			if(abs(o1-o2) <= (r1+r2) && abs(o3-o4) <= (r3+r4)) ret = 1;
		}else{
			if(t0*t1 <= 0 && t2*t3 <= 0) ret = 1;
		}
		cout << ret << endl;
	}
}
