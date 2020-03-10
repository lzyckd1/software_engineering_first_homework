#ifndef LINE_H
#define LINE_H

class Line
{
public:
	Line();
	Line(double x1, double y1, double x2, double y2);
	~Line();
	bool getExistK();
	double getX1();
	double getY1();
	double getX2();
	double getY2();
	double getK();
	double getA();
	double getB();
	double getC();

private:
	double x1, y1, x2, y2, k;
	double A, B, C;
	bool exist_k;
};

#endif