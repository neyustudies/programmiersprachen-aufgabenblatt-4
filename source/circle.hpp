#ifndef CIRCLE_HPP
#define CIRCLE_HPP
#include "mat2.hpp"
#include "vec2.hpp"
#include "color.hpp"
#include "window.hpp"


class Circle {

  public:
    Circle();
    Circle(float r);
    Circle(Vec2 const& ctr, float r);
    Circle(Vec2 const& ctr, float r, Color const& clr);
    Circle(Vec2 const& ctr, float r, std::string const& name);
    Circle(Vec2 const& ctr, float r, Color const& clr, std::string const& name);
    Circle(Vec2 const& ctr, float r, Color const& clr, float thickness);
    float circumference() const;
    float radius() const;
    Vec2 center() const;
    Color color() const;
    std::string name() const;
    float thickness() const;
    void draw(Window const& win) const;
    void draw(Window const& win, float thickness) const;
    void draw(Window const& win, Color clr) const;
    void draw(Window const& win, Color clr, float thickness) const;
    bool is_inside(Vec2 const& point) const;
    bool is_highlighted(std::string const& highl_name) const;
    std::ostream& print(std::ostream& os) const;

  private:
    Vec2 center_;
    float radius_;
    Color color_;
    std::string name_;
    float thickness_ = 1.0f;

};

bool operator<(Circle const& lhs, Circle const& rhs);
bool operator>(Circle const& lhs, Circle const& rhs);
bool operator==(Circle const& lhs, Circle const& rhs);
std::ostream& operator<<(std::ostream& os, Circle const& c);

#endif // CIRCLE_HPP