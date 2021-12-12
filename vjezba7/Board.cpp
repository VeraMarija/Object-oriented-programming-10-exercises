#include "Board.h"
#include<iostream>
#include<iomanip>
#include<cmath>


Board::Board() {
	rows = 10;
	cols = 20;
	character = ('o');
	mtx = new char*[rows];
	for (int i = 0;i < rows;++i) {
		mtx[i] = new char[cols];
	}
	set_board();
	p1.set_xy(get_rows(), get_cols());
	p2.set_xy(get_rows(), get_cols());
	draw_line(p1, p2, 'x');
	std::cout << "default: " << std::endl;
	print_current_board();
}


Board::Board(const Board& other) {
	this->character = other.character;
	this->rows = other.rows;
	this->cols = other.cols;
	this->mtx = new char* [rows];
	for (int i = 0;i < rows;++i) {
		this->mtx[i] = new char[cols];
	}
	this->set_board();
	this->p1 = other.p1;
	this->p2 = other.p2;
	this->p1.set_x(other.p1.get_x());
	this->p1.set_y(other.p1.get_y());
	this->p2.set_x(other.p2.get_x());
	this->p2.set_y(other.p2.get_y());
	draw_line(p1, p2, 'x');
	std::cout << std::endl << "copy: " << std::endl;
	print_current_board();

}

Board::Board(Board&& other) {
	this->character = other.character;
	this->rows = other.rows;
	this->cols = other.cols;
	this->mtx = new char* [rows];
	for (int i = 0;i < rows;++i) {
		this->mtx[i] = new char[cols];
	}
	this->set_board();
	this->p1 = other.p1;
	this->p2 = other.p2;
	this->p1.set_x(other.p1.get_x());
	this->p1.set_y(other.p1.get_y());
	this->p2.set_x(other.p2.get_x());
	this->p2.set_y(other.p2.get_y());
	draw_line(p1, p2, 'x');
	for (int i = 0;i < other.rows;++i)
		other.mtx[i] = nullptr;
	other.mtx = nullptr;
	other.character = 0;
	other.cols = 0;
	other.rows = 0;
	other.p1.set_x(0);
	other.p1.set_y(0);
	other.p2.set_x(0);
	other.p2.set_y(0);
	std::cout << std::endl << "move: " << std::endl;
	print_current_board();
}

Board::Board(int rows, int cols) {
	this->rows = rows;
	this->cols = cols;
	this->character = 'o';
	this->mtx = new char* [rows];
	for (int i = 0;i < this->rows;++i) {
		mtx[i] = new char[this->cols];
	}
	set_board();
	this->p1.set_xy(this->rows, this->cols);
	this->p2.set_xy(this->rows, this->cols);
	draw_line(p1, p2, 'x');
	std::cout << std::endl << "with arguments: " << std::endl;
	print_current_board();
}

void Board::set_board() {
	for (int i = 0;i < this->rows;++i) {
		for (int j = 0;j < this->cols;++j) {
			if (i == 0 || j == 0 || (i == this->rows - 1) || (j == this->cols - 1))
				mtx[i][j] = this->character;
			else
				mtx[i][j] = ' ';
		}
	}
}

void Board::print_current_board() {
	for (int i = 0;i < this->rows;++i) {
		for (int j = 0;j < this->cols;++j)
			std::cout << mtx[i][j];
		std::cout << std::endl;
	}
}

void Board::draw_char(Point p, char character) {
	for (int i = 0;i < this->rows;++i) {
		for (int j = 0;j < this->cols;++j) {
			if (i == p.get_y() && j ==p.get_x() )
				mtx[i][j] = character;
		}
	}
}

void Board::draw_up_line(Point p1, Point p2, char character) {
	if ((p1.get_x() == p2.get_y()) && (p1.get_y() == p2.get_y())) {
		this->draw_char(p1, character);
	}
	else if (p1.get_x() != p2.get_x()) {
		this->draw_char(p1, character);
		this->draw_char(p2, character);
	}
	else {
		for (int i = 0;i < this->rows;++i) {
			for (int j = 0;j < this->cols;++j)
				if (j == p2.get_x() && i>=p1.get_y() && i<=p2.get_y())
					mtx[i][j] = character;
		}
	}
}

void change_two_points(Point& p1, Point& p2) {
	Point temp;
	temp.set_x(p1.get_x());
	temp.set_y(p1.get_y());
	p1.set_x(p2.get_x());
	p1.set_y(p2.get_y());
	p2.set_x(temp.get_x());
	p2.set_y(temp.get_y());
}

void Board::draw_line(Point p1, Point p2, char character) {
	if ((p1.get_x() == p2.get_x()) && (p1.get_y() == p2.get_y()) ){
		this->draw_char(p1, character);
	}
	else if (p1.get_x() == p2.get_x()) {
		if (p2.get_y() < p1.get_y())
			change_two_points(p1, p2);
		draw_up_line(p1, p2, character);
	}
	else if (p1.get_y() ==p2.get_y()) {
		if (p2.get_x() < p1.get_x()) {
			change_two_points(p1, p2);
		}
		int i = p1.get_y();
		int j = p1.get_x();
		int k = p2.get_x();
		for (j ; j <= k;++j)
				mtx[i][j] = character;
	}
	else if ((abs(p1.get_x() - p2.get_x())) == (abs(p1.get_y() - p2.get_y()))) {//|x1−x2|=|y1−y2|
		if ((p1.get_y() > p2.get_y()) && (p1.get_x() > p2.get_x()))
			change_two_points(p1, p2);
		if ((p2.get_y() > p1.get_y()) && (p2.get_x() > p1.get_x())) {
			int i = p1.get_y();
			int j = p1.get_x();
			int k1 = p2.get_y();
			int k2 = p2.get_x();
			for (i;i <= k1;++i) {
				mtx[i][j] = character;
				j++;
			}
		}
		if ((p1.get_y() < p2.get_y()) && (p1.get_x() > p2.get_x()))
			change_two_points(p1, p2);
		if ((p2.get_y() < p1.get_y()) && (p2.get_x() > p1.get_x())) {
			int i = p1.get_y();
			int j = p1.get_x();
			int k1 = p2.get_y();
			int k2 = p2.get_x();
			for (i;i >= k1;--i) {
				mtx[i][j] = character;
				j++;
			}
		}
	}
	else {
		this->draw_char(p1, character);
		this->draw_char(p2, character);
	}
}

void Point::set_xy(double rows, double cols) {
	do {
		std::cout << "enter x coordinate of point: " << std::endl;
		std::cin >> x;
		x = round(x);
		std::cout << "enter y coordinate of point: " << std::endl;
		std::cin >> y;
		y = round(y);

	} while (x<0 || y<0 || x> cols - 1 || y> rows - 1);
}

