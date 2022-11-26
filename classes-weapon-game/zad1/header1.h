#ifndef HEADER1_H
#define HEADER1_H
#include<iostream>
#include<random>
#include<math.h>
using namespace std;

class Point {
	private:
		double x;
		double y;
		double z;

	public:
		void set_x(double _x = 0) {
			x = _x;
		}

		void set_y(double _y = 0) {
			y = _y;
		}

		void set_z(double _z = 0) {
			z = _z;
		}

		void set_pseudorandom(double min, double max) {
			x = min + static_cast <double>  (rand()) / (static_cast <double> (RAND_MAX / (max - min)));
			y = min + static_cast <double>  (rand()) / (static_cast <double> (RAND_MAX / (max - min)));
			z = min + static_cast <double>  (rand()) / (static_cast <double> (RAND_MAX / (max - min)));
		}

		double get_x() {
			return x;
		}

		double get_y() {
			return y;
		}

		double get_z() {
			return z;
		}

		double calculateDistance2D(Point A, Point B) {
			return sqrt(pow(A.get_x() - B.get_x(), 2) + pow(A.get_y() - B.get_y(), 2));
		}

		double calculateDistance3D(Point A, Point B) {
			return sqrt(pow(A.get_x() - B.get_x(), 2) + pow(A.get_y() - B.get_y(), 2) + pow(A.get_z() - B.get_z(), 2));
		}
	};




#endif
