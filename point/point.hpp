#ifndef POINT_HPP
#define POINT_HPP


class Point {
    public:
        int x, y;

        Point() : x(0), y(0) {};

        Point(int x, int y) : x(x), y(y) {};

        bool operator==(const Point& other) const {
            return x == other.x && y == other.y;
        }

        bool operator!=(const Point& other) const {
            return !(*this == other);
        }
        
};


#endif // POINT_HPP