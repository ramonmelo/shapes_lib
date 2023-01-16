#pragma once

struct Point
{
public:
  Point(double, double, double);
  double getX();
  double getY();
  double getZ();

private:
  double x;
  double y;
  double z;
};
