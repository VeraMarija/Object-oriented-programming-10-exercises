#ifndef BOARD_H
#define BOARD_H
#include<cmath>
#include<iostream>

struct Point {
private:
	double x, y;
public:
	void set_xy( double rows, double cols);
	double get_x() const { return x; }
	double get_y() const { return y; }
	void set_x(double x) { this->x = round(x); }
	void set_y(double y) { this->y = round(y); }
};


class Board {
	char** mtx;
	int rows;
	int cols;
	char character;
public:
	Point p1, p2;
	Board();
	Board(const Board& other);
	Board(Board&& other);
	Board(int rows, int cols);
	~Board() { std::cout << std::endl<<"destruktor"; }
	void set_board();
	char** get_matrix() { return mtx; }
	int get_rows() const{ return rows; }
	int get_cols() const{ return cols; } 
	void draw_char(Point p, char character);
	void print_current_board();
	void draw_up_line(Point p1, Point p2, char character);
	void draw_line(Point p1, Point p2, char character);
};

#endif