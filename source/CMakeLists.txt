add_executable(aufgabe_2_und_3 
  aufgabe_2_und_3.cpp
)

add_executable(aufgabe_5 
  glew.c
  aufgabe_5.cpp
  vec2.cpp
  circle.cpp
  window.cpp
  )
target_link_libraries(aufgabe_5
  glfw
  ${GLFW_LIBRARIES}
  nanovg
  ${OPENGL_LIBRARIES}
  
)

#arget_include_directories(tests PRIVATE thirdparty/catch/include)
#catch ${CATCH_DIRECTORY}