#pragma once

#include "Point.h"

class Figure {
public:
    virtual void Render(const sdl::renderer& renderer) const = 0;
    virtual void Save(std::ostream& os) const = 0;
    virtual void Load(std::istream& is) = 0;
    virtual bool PointBelongsTo(Point p) const = 0;
    void SetColor(int r, int g, int b);
    virtual ~Figure() = default;

protected:
    int rcolor = 255, gcolor = 0, bcolor = 0;
};
