cmake_minimum_required(VERSION 3.2)

project(src)

set(MANAGER ActionManager.cpp)
set(BUTTON  Button.cpp)
set(CANVAS  Canvas.cpp)
set(BASIS   Basis.cpp)
set(RENDER  Render.cpp)
set(VEC2    Vec2.cpp)
set(VEC3    Vec3.cpp)
set(VECTOR  Vector.cpp)
set(WIDGET  Widget.cpp)
set(TOOL    FillToolc.cpp)

add_library(src STATIC ActionManager.cpp Button.cpp Canvas.cpp 
                       Basis.cpp Render.cpp Vec2.cpp Vec3.cpp 
                       Vector.cpp Widget.cpp FillTool.cpp)
