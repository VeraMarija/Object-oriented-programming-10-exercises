#include<iostream>
#include "Pnt.h"

using namespace std;

int main1() {
	Point A,B;
	A.set_pseudorandom (-2.5, 10);
	B.set_pseudorandom (-2.5, 0);
	cout << A.get_x() << "  " << A.get_y() << "  " << A.get_z() << endl;
	cout << B.get_x() << "  " << B.get_y() << "  " << B.get_z() << endl;
	cout << endl << "2D distance--> " << A.calculateDistance2D(A, B) << endl;
	cout << "3D distance--> " <<  A.calculateDistance3D(A, B);

	return 0;
}
