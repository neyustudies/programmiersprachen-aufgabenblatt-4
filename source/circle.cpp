#include "circle.hpp"
#include "mat2.hpp"
#include <cmath>


Circle::Circle() :
  center_ {400,400},
  radius_ {100.0f},
  color_  {0.7f,0.7f,0.7f} {}


Circle::Circle(Vec2 const& ctr, float r) :
  center_ {ctr},
  radius_ {r} {}


Circle::Circle(Vec2 const& ctr, float r, Color const& clr) :
  center_ {ctr},
  radius_ {r},
  color_  {clr} {}


float Circle::circumference() const {
  float c = M_PI * radius() * 2;
  if(c < 0) {
    return -(c); 
  } return c;
}


float Circle::radius() const {
  return radius_;
}


Vec2 Circle::center() const {
  return center_;
}


Color Circle::color() const {
  return color_;
}


void Circle::draw(Window const& win, Color const& clr) const {
  draw(win, color_);
}


void Circle::draw(Window const& win, Color const& clr, float thickness) const {
  for(int i = 0; i <= 500; ++i) { 
    Vec2 start = make_rotation_mat2((2 * M_PI)/500 * i) * Vec2{radius_, 0} + center_;
    Vec2 end = make_rotation_mat2((2 * M_PI)/500 * (i+1)) * Vec2{radius_, 0} + center_;
    win.draw_line(start.x, start.y, end.x, end.y, color_.r, color_.g, color_.b, thickness);
  }
}


bool Circle::is_inside(Vec2 const& point) const {
  return pow(point.x - center_.x, 2.0) + pow(point.y - center_.y, 2.0) < pow(radius_, 2.0);
}

/*-----------------------------------------------------------------------------------------*/

bool operator<(Circle const& lhs, Circle const& rhs) {
  return lhs.radius() < rhs.radius();
}

bool operator>(Circle const& lhs, Circle const& rhs) {
  return lhs.radius() > rhs.radius();
}

bool operator==(Circle const& lhs, Circle const& rhs) {
  return lhs.radius() == rhs.radius();
}
