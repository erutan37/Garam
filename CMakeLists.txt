cmake_minimum_required(VERSION 3.3)
project(JeuFourmi)


set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++14")


file(

        GLOB_RECURSE

        SOURCE_FILES

        src/*
)

file(
        GLOB_RECURSE

        INCLUDES_FILES

        includes/*
)



include_directories(${CMAKE_SOURCE_DIR}/includes)

set (EXECUTABLE_NAME "Garam")
add_executable(${EXECUTABLE_NAME} ${INCLUDES_FILES} ${SOURCE_FILES} main.cpp)


set(CMAKE_MODULE_PATH "${CMAKE_SOURCE_DIR}/cmake_modules" ${CMAKE_MODULE_PATH})
find_package(SFML 2.3 REQUIRED system window graphics)
if(SFML_FOUND)
    include_directories(${SFML_INCLUDE_DIR})
    target_link_libraries(${EXECUTABLE_NAME} ${SFML_LIBRARIES})
endif()
