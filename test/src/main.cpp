#include <iostream>
#include <shapes/Point.h>

using namespace std;

void displayPoint(Point& p) {
  cout << p.getX() << "," << p.getY() << "," << p.getZ() << endl;
}

int main()
{
  Point p(1, 2, 3);
  displayPoint(p);

  return 0;
}