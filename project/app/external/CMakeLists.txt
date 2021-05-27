project(External)

add_subdirectory(yaml-cpp)

set(HEADERS
    ${PROJECT_SOURCE_DIR}/nlohmann/json.hpp
    ${PROJECT_SOURCE_DIR}/tinyxml2/tinyxml2.h
)

set(SOURCES
    ${PROJECT_SOURCE_DIR}/tinyxml2/tinyxml2.cpp
)

add_library(${PROJECT_NAME} STATIC ${SOURCES} ${HEADERS})
add_dependencies(${PROJECT_NAME} yaml-cpp)
target_include_directories(${PROJECT_NAME} INTERFACE ${PROJECT_SOURCE_DIR})

