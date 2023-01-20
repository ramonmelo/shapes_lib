#ifndef POINT_H
#define POINT_H

#include <shapes_common/utils.h>
#include <core/BasePoint.h>

struct Point : BasePoint
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

#endif // !POINT_H