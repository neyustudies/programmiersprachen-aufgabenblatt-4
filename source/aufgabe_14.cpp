#include "window.hpp"
#include "circle.hpp"
#include <GLFW/glfw3.h>
#include <utility>
#include <cmath>
#include <vector>
#include <iostream>
#include <set>


std::multiset<Circle, std::function<bool(Circle, Circle)>> circles (
  [](Circle const& c1, Circle const& c2) -> bool { 
    return c1.radius() < c2.radius();});


int main(int argc, char* argv[]) {

  std::string highl_name;
  std::cout << "Name(Anzahl): eins(4), zwei(4), drei(1), vier(1)\n";
  std::cout << "Welchen Kreis möchtest Du für 10 sec highlighten? : ";
  std::cin  >> highl_name;
  std::cout << "\n";
  Window win{std::make_pair(800,800)};

  Color     highlight {1.0, 0.0, 0.4};
  Color     green     {0.6, 0.9, 0.6};
  Color     blue      {0.6, 0.9, 1.0};
  Color     bluec     {0.2, 0.7, 9.0};
  Color     turq      {0.1, 0.8, 0.7};

  Circle    cir_1     {{500, 500}, 130, blue,   "eins"};
  Circle    cir_2     {{400, 400}, 60,  blue,   "zwei"};
  Circle    cir_3     {{180, 200}, 120, green,  "drei"};
  Circle    cir_4     {{540, 200}, 100, bluec,  "vier"};
  Circle    cir_5     {{170, 500}, 40,  blue,   "eins"};
  Circle    cir_6     {{270, 650}, 90,  turq,   "eins"};
  Circle    cir_7     {{370, 200}, 40,  turq,   "eins"};
  Circle    cir_8     {{630, 650}, 30,  green,  "zwei"};
  Circle    cir_9     {{270, 400}, 20,  turq,   "zwei"};
  Circle    cir_10    {{530, 550}, 20,  bluec,  "zwei"};

  circles.insert(cir_1);
  circles.insert(cir_2);
  circles.insert(cir_3);
  circles.insert(cir_4);
  circles.insert(cir_5);
  circles.insert(cir_6);
  circles.insert(cir_7);
  circles.insert(cir_8);
  circles.insert(cir_9);
  circles.insert(cir_10);

  while (!win.should_close()) {
    if (win.get_key(GLFW_KEY_ESCAPE) == GLFW_PRESS) {
      win.close();
    }

    auto t = win.get_time();
    int  second    = int(t) % 60;
    int  minute    = t / 60;
    int  hour      = t / 3600;

    std::string time_to_string = "time: " + std::to_string(hour)   + "h " 
                                          + std::to_string(minute) + "min "
                                          + std::to_string(second) + "sec";

    win.draw_text(10, 760, 30, time_to_string);
    win.draw_text(710, 760, 30, "by Lisa");

    float x1 = 400.f + 380.f * std::sin(t);
    float y1 = 400.f + 380.f * std::cos(t);
    float x2 = 400.f + 380.f * std::sin(2.0f*t);
    float y2 = 400.f + 380.f * std::cos(2.0f*t);
    float x3 = 400.f + 380.f * std::sin(t-10.f);
    float y3 = 400.f + 380.f * std::cos(t-10.f);

    win.draw_point(x1, y1, 1.0f, 0.0f, 0.0f);
    win.draw_point(x2, y2, 0.0f, 1.0f, 0.0f);
    win.draw_point(x3, y3, 0.0f, 0.0f, 1.0f);

    bool found = false;
    if (t < 10) {
      for (auto const& item : circles) {
        if (item.is_highlighted(highl_name)) {
          item.draw(win, highlight);
          found = true;
          if(item.is_inside({(float)std::get<0>(win.mouse_position()), 
                             (float)std::get<1>(win.mouse_position())})) {
                               item.draw(win, item.thickness()*2);}   
        } else {item.draw(win);}
      } if(!found) { 
        win.draw_text(10, 5, 28, "Der Name existiert nicht!");}
    } else {
      for (auto const& item : circles) {
        item.draw(win);
      }
    }


    win.update();
  }

  return 0;
}

