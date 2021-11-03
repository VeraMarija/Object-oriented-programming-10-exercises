#include<iostream>
#include<math.h>
using namespace std;

typedef struct {
	float x;
	float y;
}Point;

typedef struct {
	Point s;
	float r;
}Circle;

typedef struct {
	Point a, b;
}Rectangle;

int intersect( Rectangle*& r_r, int n, const Circle& r_c)  {
	float Xn = max(r_r[0].a.x, min(r_c.s.x, r_r[0].b.x));
	float Yn = max(r_r[0].a.y, min(r_c.s.y, r_r[0].b.y));
	int i,cnt=0;
	for (i = 0;i < n;++i) {
		float Xn = max(r_r[i].a.x, min(r_c.s.x, r_r[i].b.x));
		float Yn = max(r_r[i].a.y, min(r_c.s.y, r_r[i].b.y));
		float Dx = Xn - r_c.s.x;
		float Dy = Yn - r_c.s.y;
		if ((Dx * Dx + Dy * Dy) <= r_c.r * r_c.r) {
			cnt++;
		}
	}
	return cnt;
}

int main() {	
	Circle circle;
	circle.r = 1;
	circle.s.x = 1;
	circle.s.y = 1;
	int n;
	cout << "enter the number of rectangles:" << endl;
	cin >> n;
	Rectangle* arr_rect = new Rectangle[n]; //niz od n pravokutnika
	Rectangle*& r_r = arr_rect; 
	const Circle r_c = circle;
	int i;
	cout << "enter the points of rectangle: " << endl;
	for (i = 0;i < n; ++i) {
		cout << i << ".rectangle" << endl;
		cout << "x1: ";
		cin >> arr_rect[i].a.x;
		cout << "y1: ";
		cin >> arr_rect[i].a.y;
		cout << "x2: ";
		cin >> arr_rect[i].b.x;
		cout << "y2: ";
		cin >> arr_rect[i].b.y;
	}
	cout << "the number of rectangles that intersect the circle is: " << intersect(r_r, n, r_c) << endl;
	return 0;
}

