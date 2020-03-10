#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<iostream>
#include<fstream>
#include<set>
#include  "node.h"
#include "Line.h"
#include "intersect.h"
using namespace std;

const int maxn = 10001;
int countn = 0;

set <struct node> node_set;

Line* lseq = new Line[maxn];

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
	ifstream infile("input.txt");  // argv[2]
	ofstream outfile("output.txt");   // argv[4]
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