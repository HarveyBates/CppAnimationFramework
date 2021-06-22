cmake_minimum_required(VERSION "3.19.2")

project("AnimationFramework")

find_package(raylib 3.0 REQUIRED)
find_package(OpenGL REQUIRED)

set(NAME_SRC 
	src/main.cpp
	src/transform.cpp
	src/graph.cpp
	src/shapes.cpp
	src/waves.cpp
	src/boids.cpp)

set(NAME_HEADERS
	include/main.h
	include/transform.hpp
	include/graph.hpp
	include/shapes.h
	include/waves.hpp
	include/boids.hpp)

set(EXECUTABLE_OUTPUT_PATH 
	${CMAKE_BINARY_DIR}/bin)

set(CMAKE_EXE_LINKER_FLAGS "${CMAKE_EXE_LINKER_FLAGS} -framework Cocoa -framework OpenGL -framework IOKit")

include_directories(${CMAKE_SOURCE_DIR}/include)

add_executable(${PROJECT_NAME} ${NAME_SRC} ${NAME_HEADERS})

target_compile_features(${PROJECT_NAME} PUBLIC cxx_std_14)

target_include_directories(${PROJECT_NAME} PRIVATE ${CMAKE_SOURCE_DIR}/include)

target_link_libraries(${PROJECT_NAME} raylib OpenGL::GL)
