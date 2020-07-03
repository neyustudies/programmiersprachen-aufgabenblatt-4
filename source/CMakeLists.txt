add_executable(aufgabe_2_und_3 
  aufgabe_2_und_3.cpp
)

add_executable(aufgabe_5 
  glew.c
  aufgabe_5.cpp
  mat2.cpp
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

add_executable(aufgabe_6_und_7 
  glew.c
  aufgabe_6_und_7.cpp
  mat2.cpp
  vec2.cpp
  circle.cpp
  window.cpp
  )
target_link_libraries(aufgabe_6_und_7
  glfw
  ${GLFW_LIBRARIES}
  nanovg
  ${OPENGL_LIBRARIES} 
)

add_executable(aufgabe_9
  aufgabe_9.cpp)

add_executable(aufgabe_10_und_11
  aufgabe_10_und_11.cpp)

add_executable(aufgabe_12_und_13
  aufgabe_12_und_13.cpp
  glew.c
  vec2.cpp
  mat2.cpp
  circle.cpp
  window.cpp
  )
target_link_libraries(aufgabe_12_und_13
  glfw
  ${GLFW_LIBRARIES}
  nanovg
  ${OPENGL_LIBRARIES} 
)

add_executable(aufgabe_14
  window.cpp
  glew.c
  aufgabe_14.cpp
  mat2.cpp
  vec2.cpp
  circle.cpp
  )
target_link_libraries(aufgabe_14
  glfw
  ${GLFW_LIBRARIES}
  nanovg
  ${OPENGL_LIBRARIES}
  )
add_dependencies(aufgabe_14 glfw nanovg ${COPY_BINARY})

