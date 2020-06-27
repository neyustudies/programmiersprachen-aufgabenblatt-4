/**
 * Programmiersprachen SoSe 2020
 * Aufgabensammlung 2
 * Lisa P.
 * vec2.cpp
*/

#include "vec2.hpp"
#include <iostream>


// definition addition for Vec2
Vec2& Vec2::operator+=(Vec2 const& v) {
  x += v.x;
  y += v.y;
  return *this;
}

// definition multiplication for Vec2
Vec2& Vec2::operator*=(float s) {
  x *= s;
  y *= s;
  return *this;
}

// definition subtraction for Vec2
Vec2& Vec2::operator-=(Vec2 const& v) {
  x -= v.x;
  y -= v.y;
  return *this;
}

// definition division for Vec2
Vec2& Vec2::operator/=(float s) {
  if(s == 0) {
    std::cerr << "Error: divsion by zero\n";
  } x /= s;
    y /= s;
    return *this;
}

/*--- Free Functions of vec2 -------------------------*/

Vec2 operator+(Vec2 const& u, Vec2 const& v) {
  return Vec2(u) += v;
}

Vec2 operator-(Vec2 const& u, Vec2 const& v) {
  return Vec2(u) -= v;
}

Vec2 operator*(Vec2 const& v, float s) {
  return Vec2(v) *= s;
}

Vec2 operator/(Vec2 const& v, float s) {
  return Vec2(v) /= s;
}

Vec2 operator*(float s, Vec2 const& v) {
  return Vec2(v) *= s;
}