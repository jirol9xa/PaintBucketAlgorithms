cmake_minimum_required(VERSION 3.2)

project(src)

set(MANAGER ActionManager/actionManager.cpp)
set(BUTTON  Button/button.cpp)
set(CANVAS  Canvas/canvas.cpp)
set(BASIS   CoordSys/basis.cpp)
set(RENDER  Render/render.cpp)
set(VEC2    Vec2/vec2.cpp)
set(VEC3    Vec3/vec3.cpp)
set(VECTOR  Vector/vector.cpp)
set(WIDGET  Widget/widget.cpp)

add_library(src STATIC ActionManager/actionManager.cpp Button/button.cpp Canvas/canvas.cpp 
                       CoordSys/basis.cpp Render/render.cpp Vec2/vec2.cpp Vec3/vec3.cpp 
                       Vector/vector.cpp Widget/widget.cpp)
