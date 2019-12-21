#pragma once

#include "../../Factory.h"
#include "Line.h"

class LineFactory : public Factory {
public:

    void AddPoint(const Point& p) override;

    std::unique_ptr<Figure> TryCreateObject() const override;

};