#include <vector>
#include "point2d.h"

class Player{
public:
    Player();
    unsigned long long xAddr;
    unsigned long long yAddr;
    unsigned long long zAddr;
    unsigned long long macroStateAddr;
    unsigned long long animStateAddr;
    unsigned long long attackStateAddr;
    unsigned long long blockStateAddr;
    int macroState;
    int animState;
    int attackState;
    int blockState;
    float x;
    float y;
    float z;
    std::vector<Point2d> geometry2d;

    Point2d getCentroid2d();
    Point2d getPosition2d();
    void update();
    void updateGeometry2d();
    friend std::ostream& operator<<(std::ostream& os, const Player& p);
};