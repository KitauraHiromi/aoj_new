#include <iostream>
#include <iomanip>
using namespace std;
#define rep(n) for(int i=0;i<n;i++)

int main(void){
	int q; cin >> q;
	rep(q){
		double xp0, yp0, xp1, yp1; cin>>xp0>>yp0>>xp1>>yp1;
		double xp2, yp2, xp3, yp3; cin>>xp2>>yp2>>xp3>>yp3;
		double a = yp0-yp1; double b = xp1-xp0; double k01 = xp0*yp1 - yp0*xp1;
		double c = yp2-yp3; double d = xp3-xp2; double k23 = xp2*yp3 - yp2*xp3;
		double adbc = a*d-b*c;
		double v[2] = {(k23*b - k01*d)/adbc, (k01*c - k23*a)/adbc};
		cout << fixed << setprecision(10) << v[0] << " " << fixed << setprecision(10) << v[1] << endl;
	}
}
