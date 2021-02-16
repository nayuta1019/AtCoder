/*
ARC042
2020/01/22/ 自力AC
*/
#include <bits/stdc++.h>

using namespace std;

#define EPS 1e-10
#define equals(a, b) (fabs((a) - (b)) < EPS)

struct Point {
  double x, y;
  Point(double x = 0, double y = 0) : x(x), y(y) {}
  Point operator+(Point p) { return Point(x + p.x, y + p.y); }
  Point operator-(Point p) { return Point(x - p.x, y - p.y); }
  Point operator*(double a) { return Point(a * x, a * y); }
  Point operator/(double a) { return Point(x / a, y / a); }
  double abs() { return sqrt(norm()); }
  double norm() { return x * x + y * y; }
  bool operator<(const Point &p) const { return x != p.x ? x < p.x : y < p.y; }
  bool operator==(const Point &p) const {
    return fabs(x - p.x) < EPS && fabs(y - p.y) < EPS;
  }
};
typedef Point Vector;
struct Segment {
  Point p1, p2;
  Segment(Point x = Point(), Point y = Point()) : p1(x), p2(y) {}
};
typedef Segment Line;
typedef vector<Point> Polygon;

double norm(Vector a) { return a.x * a.x + a.y * a.y; }
double abs(Vector a) { return sqrt(norm(a)); }
double dot(Vector a, Vector b) { return a.x * b.x + a.y * b.y; }
double cross(Vector a, Vector b) { return a.x * b.y - a.y * b.x; }
double getDistanceLP(Line l, Point p) {
  return abs(cross(l.p2 - l.p1, p - l.p1) / abs(l.p2 - l.p1));
}
double getDistanceSP(Segment s, Point p) {
  if (dot(s.p2 - s.p1, p - s.p1) < 0.0) return abs(p - s.p1);
  if (dot(s.p1 - s.p2, p - s.p2) < 0.0) return abs(p - s.p2);
  return getDistanceLP(s, p);
}

int main() {
  int n, x, y;
  cin >> x >> y;
  Point s(x, y);
  cin >> n;
  Polygon p;
  for (int i = 0; i < n; i++) {
    cin >> x >> y;
    p.emplace_back(x, y);
  }
  vector<Segment> seg;
  for (int i = 0; i < n; i++) {
    seg.emplace_back(p[i], p[(i + 1) % n]);
  }

  double ans = 1e9;
  for (int i = 0; i < n; i++) {
    double ret = getDistanceSP(seg[i], s);
    ans = min(ans, ret);
  }
  printf("%.12f\n", ans);
  return 0;
}