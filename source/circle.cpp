#include "circle.hpp"
#include "mat2.hpp"
#include <cmath>
#include <iostream>


Circle::Circle() :
  center_ {400,400},
  radius_ {100.0f},
  color_  {0.7f,0.7f,0.7f} {}

Circle::Circle(float r) :
  radius_ {r} {}

Circle::Circle(Vec2 const& ctr, float r) :
  center_ {ctr},
  radius_ {r} {}

Circle::Circle(Vec2 const& ctr, float r, std::string const& name) :
  center_ {ctr},
  radius_ {r},
  name_   {name} {}

Circle::Circle(Vec2 const& ctr, float r, Color const& clr) :
  center_ {ctr},
  radius_ {r},
  color_  {clr} {}

Circle::Circle(Vec2 const& ctr, float r, Color const& clr, std::string const& name) :
  center_ {ctr},
  radius_ {r},
  color_  {clr},
  name_   {name} {}

Circle::Circle(Vec2 const& ctr, float r, Color const& clr, float thickness) :
  center_   {ctr},
  radius_   {r}, 
  color_    {clr}, 
  thickness_{thickness} {}


float Circle::circumference() const {
  float c = M_PI * radius() * 2;
  if(c < 0) {return -(c);} 
  return c;
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

std::string Circle::name() const {
  return name_;
}

float Circle::thickness() const {
  return thickness_;
}

void Circle::draw(Window const &win) const {
    draw(win, 1.0f);
}

void Circle::draw(Window const &win, float thickness) const {
    Mat2 rotation = make_rotation_mat2((2 * M_PI) / 360);
    Vec2 start{radius_};
    for (int i = 1; i <= 1000; ++i) {
      Vec2 end = start * rotation;
      win.draw_line(center_.x + start.x, center_.y + start.y, 
                    center_.x + end.x, center_.y + end.y, color_.r,
                    color_.g, color_.b, thickness_);
                    start = end;
    }
}

void Circle::draw(Window const &win, Color clr) const {
    Mat2 rotation = make_rotation_mat2((2 * M_PI) / 360);
    Vec2 start{radius_};
    for (int i = 1; i <= 1000; ++i) {
        Vec2 end = start * rotation;
        win.draw_line(center_.x + start.x, center_.y + start.y, 
                      center_.x + end.x, center_.y + end.y, 1, 0, 0.4, thickness_);
                      start = end;
    }
}

bool Circle::is_inside(Vec2 const& point) const {
  return pow(point.x - center_.x, 2.0) + pow(point.y - center_.y, 2.0) < pow(radius_, 2.0);
}

bool Circle::is_highlighted(std::string const& highl_name) const {
  return name_ == highl_name;
}

std::ostream& Circle::print(std::ostream& os) const {
  os << "\n"
     << "Name:     " << name_      << "\n"
     << "Position: " << center_.x  << ", " << center_.y << "\n" 
     << "Radius:   " << radius_    << "\n"
     << "Color:    " << color_.r   << ", " << color_.g << ", " << color_.b << "\n";
     return os;  
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

std::ostream& operator<<(std::ostream& os, Circle const& c) {
  std::ostream::sentry const os_sentry(os);
  return os_sentry ? c.print(os) : os;
}

