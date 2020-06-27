#ifndef RECTANGLE_HPP
#define RECTANGLE_HPP

#include "vec2.hpp"
#include "color.hpp"
#include "window.hpp"


class Rectangle {

  public:
    Rectangle();
    Rectangle(Vec2 const& min, Vec2 const& max);
    Rectangle(Vec2 const& min, Vec2 const& max, Color const& clr);
    float circumference() const;
    Vec2 max() const;
    Vec2 min() const;
    Color color() const;
    void draw(Window const& win) const;
    void draw(Window const& win, Color clr, float thickness, bool const& highlight_color) const;
    bool is_inside(Vec2 const& point) const;

  private:
    Vec2  max_;
    Vec2  min_;
    Color color_;
    Color highlight_color_;

};

#endif // RECTANGLE_HPP