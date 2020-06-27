#include "rectangle.hpp"

// default initialization
Rectangle::Rectangle():
  max_              {600.0f, 400.0f},
  min_              {400.0f, 200.0f},
  color_            {0.7f, 0.7f, 0.7f},
  highlight_color_  {0.1f,0.8f,0.7f} {}

Rectangle::Rectangle(Vec2 const& max, Vec2 const& min):
  max_    {max},
  min_    {min} {}

Rectangle::Rectangle(Vec2 const& max, Vec2 const& min, Color const& clr):
  max_    {max},
  min_    {min},
  color_  {clr} {}

float Rectangle::circumference() const {
  float width  = max_.x - min_.x;
  float height = max_.y - min_.y;
  float circum = 2 * (width + height);
  if(circum < 0) {
    return circum * (-1);
  } return circum;
}

Vec2 Rectangle::max() const {
  return max_;
}

Vec2 Rectangle::min() const {
  return min_;
}

Color Rectangle::color() const {
  return color_;
}

void Rectangle::draw(Window const& win) const {
  win.draw_line(min_.x, min_.y, max_.x, min_.y, color_.r, color_.g, color_.b);   // to the right
  win.draw_line(max_.x, min_.y, max_.x, max_.y, color_.r, color_.g, color_.b);   // up
  win.draw_line(max_.x, max_.y, min_.x, max_.y, color_.r, color_.g, color_.b);   // to the left
  win.draw_line(min_.x, max_.y, min_.x, min_.y, color_.r, color_.g, color_.b);   // downward
}

void Rectangle::draw(Window const& win, Color clr, float thickness, bool const& highlight_color) const {
  if(highlight_color == true) {
    clr = highlight_color_;
  } win.draw_line(min_.x, min_.y, max_.x, min_.y, color_.r, color_.g, color_.b, thickness); 
    win.draw_line(max_.x, min_.y, max_.x, max_.y, color_.r, color_.g, color_.b, thickness); 
    win.draw_line(max_.x, max_.y, min_.x, max_.y, color_.r, color_.g, color_.b, thickness); 
    win.draw_line(min_.x, max_.y, min_.x, min_.y, color_.r, color_.g, color_.b, thickness); 
}

bool Rectangle::is_inside(Vec2 const& point) const {
  if(point.x < max_.x && point.y < max_.y && point.x > min_.x && point.y > min_.y){
    return true;
  } return false;   
}