#include "RandomPolygon.h"

RandomPolygon::RandomPolygon(const std::vector<Point>& points)
: Polygon(points) {}

void RandomPolygon::Save(std::ostream &os) const {
    os << "random_polygon\n";
    os << rcolor << " " << gcolor << " " << bcolor << "\n";
    os << points_.size() << "\n";
    for (size_t i = 0; i < points_.size(); ++i) {
        os << points_[i] << "\n";
    }
}

void RandomPolygon::Load(std::istream &is) {
    size_t points_count;
    is >> rcolor >> gcolor >> bcolor;
    is >> points_count;
    points_.resize(points_count);
    for (size_t i = 0; i < points_count; ++i) {
        is >> points_[i];
    }
}


bool RandomPolygon::PointBelongsTo(Point point) const //{} (Point *p, int Number, int x, int y)
{
    const std::vector<Point>& p = points_;
    double x = point.x;
    double y = point.y;
    int i1, i2, n, N, S, S1, S2, S3, flag;
    N = points_.size();
    for (n=0; n<N; n++)
    {
        flag = 0;
        i1 = n < N-1 ? n + 1 : 0;
        while (flag == 0)
        {
            i2 = i1 + 1;
            if (i2 >= N)
                i2 = 0;
            if (i2 == (n < N-1 ? n + 1 : 0))
                break;
            S = abs (p[i1].x * (p[i2].y - p[n ].y) +
                     p[i2].x * (p[n ].y - p[i1].y) +
                     p[n].x  * (p[i1].y - p[i2].y));
            S1 = abs (p[i1].x * (p[i2].y - y) +
                      p[i2].x * (y       - p[i1].y) +
                      x       * (p[i1].y - p[i2].y));
            S2 = abs (p[n ].x * (p[i2].y - y) +
                      p[i2].x * (y       - p[n ].y) +
                      x       * (p[n ].y - p[i2].y));
            S3 = abs (p[i1].x * (p[n ].y - y) +
                      p[n ].x * (y       - p[i1].y) +
                      x       * (p[i1].y - p[n ].y));
            if (S == S1 + S2 + S3)
            {
                flag = 1;
                break;
            }
            i1 = i1 + 1;
            if (i1 >= N)
                i1 = 0;
        }
        if (flag == 0)
            break;
    }
    return flag;
}



//bool RandomPolygon::PointBelongsTo(Point p) const {
//
//
//    Point start = points_[0];
//    for (size_t i = 1; i < points_.size() - 1; ++i) {
//        std::vector<Point> temp_vector(3);
//        temp_vector[0] = start;
//        temp_vector[1] = points_[i];
//        temp_vector[2] = points_[i + 1];
//
//        int first = 0;
//        bool is_ok = true;
//        for (size_t i = 0; i < 3; ++i) {
//            size_t next_index = (i + 1) % points_.size();
//            int elem = (temp_vector[i].x - p.x) * (temp_vector[next_index].y - temp_vector[i].y) - (temp_vector[next_index].x - temp_vector[i].x) * (temp_vector[i].y - p.y);
//            if (i == 0) {
//                first = elem / std::abs(elem);
//            } else {
//                if (first * (elem / std::abs(elem)) < 0) {
//                    is_ok = false;
//                    break;
//                }
//            }
//        }
//        if (is_ok) {
//            return true;
//        }
//
//    }
//    return false;
//}