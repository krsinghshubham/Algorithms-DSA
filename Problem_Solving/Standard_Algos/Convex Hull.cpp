#include<iostream>
using namespace std;
struct Point {
	int x, y;
};

//point p0;
void swap(Point& p1, Point& p2) {
	Point t;
	t = p1;
	p1 = p2;
	p2 = t;
}
void printPath(Point points[], int sz) {
	//	find lowest point
		int minp = points[0].y, min = 0;
	for (int i = 1;i < sz;i++) {
		if ((points[i].y < minp) || (points[i].y == minp && points[i].x < points[min].x))
		{
			minp = points[i].y;
			min = i;
		}
	}
	swap(points[0], points[min]);
}
int main()
{
	Point points[] = { {0, 3}, {1, 1}, {2, 2}, {4, 4},
					   {0, 0}, {1, 2}, {3, 1}, {3, 3} };
	int n = sizeof(points) / sizeof(points[0]);
	printPath(points, n);
	return 0;
	}