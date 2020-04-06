cmake_minimum_required (VERSION 3.8)
add_executable (lab-6 main.cpp)
target_link_libraries(lab-6 utils_static)
#set(CMAKE_EXE_LINKER_FLAGS "${CMAKE_EXE_LINKER_FLAGS} /SUBSYSNEM:WINDOWS /ENTRY:mainCRTStartup")