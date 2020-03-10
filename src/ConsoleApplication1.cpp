#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<iostream>
#include<fstream>
#include<set>
using namespace std;

const int maxn = 10001;
int countn = 0;

struct node {
	double x, y;
	bool operator <(const struct node &other) const
	{
		if (x < other.x) return true;
		else if (x == other.x && y < other.y) return true;
		else return false;
	}
};

set <struct node> node_set;

class Line
{
public:
	Line();
	Line(double x1, double y1, double x2, double y2);
	~Line();
	bool getExistK() {
		return exist_k;
	}
	double getX1() {
		return x1;
	}
	double getY1() {
		return y1;
	}
	double getX2() {
		return x2;
	}
	double getY2() {
		return y2;
	}
	double getK() {
		return k;
	}
	double getA() {
		return A;
	}
	double getB() {
		return B;
	}
	double getC() {
		return C;
	}

private:
	double x1, y1, x2, y2, k;
	double A, B, C;
	bool exist_k;
};

Line::Line(){
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

Line::Line(double x1,double y1,double x2,double y2)
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

Line::~Line()
{
}

Line *lseq = new Line[maxn];

struct node findIntersection(Line a, Line b)
{
	struct node ans;
	double x = 0, y = 0, d;
	double a1 = a.getA(), b1 = a.getB(), c1 = a.getC();
	double a2 = b.getA(), b2 = b.getB(), c2 = b.getC();
	d = a1 * b2 - a2 * b1;
	if (d != 0) {
		x = (b1 * c2 - b2 * c1) / d;
		y = (a2 * c1 - a1 * c2) / d;
	}
	ans.x = x;
	ans.y = y;
	return ans;
}

void add_node(Line a, Line b)
{
	struct node ans;
	if ((!a.getExistK()) && (!b.getExistK()))//a,b均平行于y轴
	{
		return;
	}
	else if (a.getExistK() && b.getExistK()) //a,b均存在斜率
	{
		if (a.getK() == b.getK())return;
		ans = findIntersection(a, b);
		if (node_set.find(ans) == node_set.end()) {
			countn = countn + 1;
			node_set.insert(ans);
		}
		return;
	}
	else {
		ans = findIntersection(a, b);
		if (node_set.find(ans) == node_set.end()) {
			countn = countn + 1;
			node_set.insert(ans);
		}
		return;
	}
	return;
}

int main(int argc, char** argv)
{
	int n;
	double a, b, c, d;
	char p;
	ifstream infile(argv[2]);  // argv[2]
	ofstream outfile(argv[4]);   // argv[4]
	infile >> n;
	for (int i = 0; i < n; i++)
	{
		infile >> p >> a >> b >> c >> d;
		lseq[i] = Line(a, b, c, d);

		for (int j = 0; j < i; j++) {
			add_node(lseq[i], lseq[j]);
		}
		
	}
	outfile << countn;
	return 0;
}