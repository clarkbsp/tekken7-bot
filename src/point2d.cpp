#include <iostream>
#include "point3d.h"
#include "point2d.h"

std::ostream& operator<<(std::ostream& os, const Point2d& p){
    os << "(" << p.x << ", " << p.y << ")";
    return os;
}