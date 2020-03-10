#ifndef CIRCLE_H
#define CIRCLE_H

struct node {
	double x, y;
	bool operator <(const struct node& other) const
	{
		if (x < other.x) return true;
		else if (x == other.x && y < other.y) return true;
		else return false;
	}
};
#endif