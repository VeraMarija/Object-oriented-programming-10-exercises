#include<iostream>
#include "Pnt.h"
using namespace std;

int main() {
	int n,i,m;
	double x, y, z;
	Weapon gun;
	cout << "enter how many bullets can fit in your weapon: ";
	cin >> n;
	gun.set_capacity_bullets(n);
	gun.A.set_x(2.5);
	gun.A.set_y(-3.1);
	gun.A.set_z(4.5);

	cout << endl << "enter number of targets: ";
	cin >> m;
	Target* arr = new Target[m];
	cout << "enter the coordinates of your target";
	for (i = 0;i < m;++i) {
		cout <<  endl << "lower left point for the " << i+1 << ".target(x,y,z): ";
		cin >> x >> y >> z;
		arr[i].lower_left.set_x(x);
		arr[i].lower_left.set_y(y);
		arr[i].lower_left.set_z(z);

		cout << endl << "upper right point for the " << i+1 << ".target(x, y, z) : ";
		cin >> x >> y >> z;
		arr[i].upper_right.set_x(x);
		arr[i].upper_right.set_y(y);
		arr[i].upper_right.set_z(z);
		while (arr[i].upper_right.get_z() <= arr[i].lower_left.get_z()) {
			cout << "enter z koordinate again: ";
			cin >> z; 
			arr[i].upper_right.set_z(z);
		}
	}

	gun.reload();
	
	for (i = 0;i < m;++i) {
		gun.shoot();
		if ((gun.A.get_z() >= arr[i].lower_left.get_z()) && (gun.A.get_z() <= arr[i].upper_right.get_z())) {
			arr[i].set_state(1);
		}
		else
			arr[i].set_state(0);
	}

	int cnt = 0;
	for (i = 0;i < m;++i) {
		if (arr[i].get_state())
			cnt++;
	}
	delete[] arr;

	cout << endl << "with one gun tank " << cnt << " targets were hit." << endl;
	return 0;
}