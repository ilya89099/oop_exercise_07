#pragma once

#include "../Figure.h"

class Circle : public Figure {
public:
    Circle() = default;
    Circle(const Point& p1, double radius);
    Circle(const Point& p1, const Point& p2);
    void Load(std::istream& is) override;
    void Save(std::ostream& os) const override;
    void Render(const sdl::renderer& renderer) const override;
    bool PointBelongsTo(Point p) const override;

private:
    Point center_;
    double radius_ = 0;
};