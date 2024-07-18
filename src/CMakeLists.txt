cmake_minimum_required(VERSION 3.5)
project(ModelViewer)

find_program(CCACHE_FOUND ccache)
if(CCACHE_FOUND)
    set_property(GLOBAL PROPERTY RULE_LAUNCH_COMPILE ccache)
    set_property(GLOBAL PROPERTY RULE_LAUNCH_LINK ccache) # Less useful to do it for linking, see edit2
endif(CCACHE_FOUND)
set(CMAKE_INCLUDE_CURRENT_DIR ON)
set(LASlib_DIR "/home/zhang/bycode/local/lib/cmake/LASlib")

find_package(Qt5 REQUIRED Widgets)
find_package(PCL REQUIRED)
find_package(LASlib REQUIRED)

add_subdirectory(log)
include_directories(${PCL_INCLUDE_DIRS})
include_directories(/home/zhang/bycode/LAStools/LASzip/include/laszip)
include_directories(${LASlib_INCLUDE_DIRS})

# message(STATUS "CMake Source Directory:" ${PCL_INCLUDE_DIRS})
# message(STATUS "CMake Source Directory:" ${PCL_DIRS})
# message(STATUS "CMake Source Directory:" ${PCL_LIBRARY_DIRS})
link_directories(${PCL_LIBRARY_DIRS})
add_definitions(${PCL_DEFINITIONS})

# find source files, header files and ui files
# aux_source_directory(. DIR_SRCS)
file(GLOB_RECURSE DIR_SRCS ${CMAKE_CURRENT_SOURCE_DIR}/*.cpp)
file(GLOB_RECURSE DIR_HEADERS ${CMAKE_CURRENT_SOURCE_DIR}/*.h)
file(GLOB_RECURSE DIR_UIS ${CMAKE_CURRENT_SOURCE_DIR}/*.ui)
message(STATUS ${DIR_HEADERS})
# add resource
set(RESOURCE ${CMAKE_CURRENT_SOURCE_DIR}/viewer.qrc)
qt5_add_resources(RESOURCE_ADDED ${RESOURCE})
# init qt
set(CMAKE_AUTOMOC ON) # for meta object compiler
set(CMAKE_AUTORCC ON) # resource files
set(CMAKE_AUTOUIC ON) # UI files
add_executable(${PROJECT_NAME}
        ${DIR_SRCS}
        ${DIR_HEADERS}
        ${DIR_UIS}
        ${RESOURCE_ADDED}
        function.h
        function.cpp
        aabb.h aabb.cpp
    )
message(STATUS dir=${LASlib_LIBRARIES})
target_link_libraries(${PROJECT_NAME}
        ${PCL_LIBRARIES}
        "/home/zhang/bycode/local/lib/LASlib/libLASlib.a"
        Qt5::Widgets
        glog::glog
        )
