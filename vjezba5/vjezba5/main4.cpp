#include<iostream>
#include "Pnt.h"
using namespace std;

int main() {
	int i,min=-10,max=10,n,p;
	Weapon gun;
	cout << "enter how many bullets can fit in your weapon: ";
	cin >> n;
	gun.set_capacity_bullets(n);
	gun.A.set_pseudorandom(min,max);
	cout << "coordinates of the weapon:  " << " " << gun.A.get_x() << " " << gun.A.get_y() << " " << gun.A.get_z() << endl;
	cout << endl << "enter number of targets: ";
	cin >> p;
	Target* arr = new Target[p];
	for (i = 0;i < p;++i) {
		arr[i].lower_left.set_pseudorandom(min, max);
		arr[i].upper_right.set_pseudorandom(min, max);
		while (arr[i].upper_right.get_z() <= arr[i].lower_left.get_z()) {
			arr[i].upper_right.set_pseudorandom(min, max);
		}
	}

	gun.reload();
	
	for (i = 0;i < p;++i) {
		if (gun.shoot()==1) {
			if ((gun.A.get_z() >= arr[i].lower_left.get_z()) && (gun.A.get_z() <= arr[i].upper_right.get_z())) {
				arr[i].set_state(1);
			}

			else
				arr[i].set_state(0);
		}
	}

	int cnt = 0;
	for (i = 0;i < p;++i) {
		if (arr[i].get_state())
			cnt++;
	}

	delete[] arr;

	cout << endl << "with one gun tank " << cnt << " targets were hit." << endl;

	return 0;
}