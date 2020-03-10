#include "Line.h"

bool Line::getExistK() {
	return exist_k;
}
double Line::getX1() {
	return x1;
}
double Line::getY1() {
	return y1;
}
double Line::getX2() {
	return x2;
}
double Line::getY2() {
	return y2;
}
double Line::getK() {
	return k;
}
double Line::getA() {
	return A;
}
double Line::getB() {
	return B;
}
double Line::getC() {
	return C;
}


Line::Line() {
	this->x1 = 0;
	this->x2 = 0;
	this->y1 = 0;
	this->y2 = 0;
	this->A = 0;
	this->B = 0;
	this->C = 0;
	this->k = 0;
	this->exist_k = false;
}

Line::Line(double x1, double y1, double x2, double y2)
{
	this->x1 = x1;
	this->x2 = x2;
	this->y1 = y1;
	this->y2 = y2;
	this->A = y1 - y2;
	this->B = x2 - x1;
	this->C = x1 * y2 - x2 * y1;
	this->k = 0;
	if (x1 == x2) {
		this->exist_k = false;
	}
	else {
		this->exist_k = true;
		this->k = (y2 - y1) / (x2 - x1);
	}
}

Line:: ~Line()
{
}