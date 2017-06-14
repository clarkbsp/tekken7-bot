class Point2d{
public:
    Point2d():
    x(0),
    y(0) {}
    
    Point2d(float x, float y):
    x(x),
    y(y) {}

    float x;
    float y;

    friend std::ostream& operator<<(std::ostream& os, const Point2d& p);
};