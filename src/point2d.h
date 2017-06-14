class Point2d{
public:
    Point2d(float x, float y):
    x(x),
    y(y) {}

    const float x;
    const float y;

    friend std::ostream& operator<<(std::ostream& os, const Point2d& p);
};