cmake_minimum_required(VERSION 3.25)
project(Minimum_Spanning_Tree_Application_Examples)

set(CMAKE_CXX_STANDARD 17)


#ege图形库导入，我的是F:/My_Clion/mycenv/EGE20.08
include_directories(F:/My_Clion/mycenv/EGE20.08/include)
link_directories(F:/My_Clion/mycenv/EGE20.08/lib/mingw64)


add_executable(Minimum_Spanning_Tree_Application_Examples main.cpp head.cpp head.h)


#ege图形库的包
target_link_libraries(Minimum_Spanning_Tree_Application_Examples libgraphics64.a
        libgdi32.a libimm32.a libmsimg32.a libole32.a
        liboleaut32.a libwinmm.a libuuid.a libgdiplus.a)

