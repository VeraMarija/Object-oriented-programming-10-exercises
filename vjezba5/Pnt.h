#ifndef PNT_H
#define PNT_H
#include<iostream>
#include<random>
#include<math.h>
using namespace std;

//1.task
class Point {
	private:
		double x;
		double y;
		double z;

	public:
		void set_x(double _x=0) {
			x = _x;
		}

		void set_y(double _y=0) {
			y = _y;
		}

		void set_z(double _z = 0) {
			z = _z;
		}

		void set_pseudorandom(double min, double max) {
			x = min + ((double)rand() / RAND_MAX) * (max - min);
			y = min + ((double)rand() / RAND_MAX) * (max - min);
			z = min + ((double)rand() / RAND_MAX) * (max - min);
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

//2.task
class Weapon {
	private:
		int capacity_bullets;
		int current_bullets=0;

	public:
		Point A;

		void shoot() {
			if (current_bullets > 0) {
				--current_bullets;
			}
			else {
				cout << "you have no bullets in your weapon!";
			}
		}

		void reload() {
			current_bullets = capacity_bullets;
		}

		void set_capacity_bullets(int n) {
			capacity_bullets = n;
		}

		void set_current_bullets(int n) {
			while (n > capacity_bullets) {
				cout << "error: you tried to set the num of bullets more than the capacity is! enter num of bullets again: ";
				cin >> n;
			}
			current_bullets = n;
		}

		int get_capacity_bullets() {
			return capacity_bullets;
		}

		int get_current_bullets() {
			return current_bullets;
		}
};

//3.task
class Target {
	private:
		bool state;

	public:
		Point lower_left;
		Point upper_right;

		void set_state(bool n) {
			if (n)
				state = true;
			else
				state = false;
		}

		bool get_state() {
			return state;
		}

};

#endif