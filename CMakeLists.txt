cmake_minimum_required(VERSION 3.25)
project(CPP_Foundations LANGUAGES CXX)

# C++ standard
set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Use MSVC debug/release CRTs automatically
set(CMAKE_MSVC_RUNTIME_LIBRARY "MultiThreaded$<$<CONFIG:Debug>:Debug>DLL")

# Grab all .cpp files in this directory
file(GLOB SOURCES CONFIGURE_DEPENDS *.cpp)

# Make one executable per .cpp, named after the file
foreach(src IN LISTS SOURCES)
  get_filename_component(name "${src}" NAME_WE)
  add_executable("${name}" "${src}")
  if (MSVC)
    target_compile_options("${name}" PRIVATE /W4 /EHsc /permissive- /Zi)
  endif()
endforeach()
