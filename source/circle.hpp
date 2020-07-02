#ifndef CIRCLE_HPP
#define CIRCLE_HPP

#include "vec2.hpp"
#include "color.hpp"
#include "window.hpp"


class Circle {

  public:
    Circle();
    Circle(float r);
    Circle(Vec2 const& ctr, float r);
    Circle(Vec2 const& ctr, float r, std::string const& name);
    Circle(Vec2 const& ctr, float r, Color const& clr);
    Circle(Vec2 const& ctr, float r, Color const& clr, std::string const& name);
    float circumference() const;
    float radius() const;
    Vec2 center() const;
    Color color() const;
    std::string name() const;
    void draw(Window const& win) const;
    void draw(Window const& win, Color const& clr) const;
    bool is_inside(Vec2 const& point) const;

  private:
    Vec2 center_;
    float radius_;
    Color color_;
    std::string name_;

};

bool operator<(Circle const& lhs, Circle const& rhs);
bool operator>(Circle const& lhs, Circle const& rhs);
bool operator==(Circle const& lhs, Circle const& rhs);

#endif // CIRCLE_HPP