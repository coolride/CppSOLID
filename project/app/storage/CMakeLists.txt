project(Storage)

add_subdirectory(ut)

set(HEADERS
    ${PROJECT_SOURCE_DIR}/include/storage/JsonStorage.hpp
    ${PROJECT_SOURCE_DIR}/include/storage/XmlStorage.hpp
    ${PROJECT_SOURCE_DIR}/include/storage/YamlStorage.hpp
    ${PROJECT_SOURCE_DIR}/include/storage/ValidatedStorage.hpp
    ${PROJECT_SOURCE_DIR}/include/storage/StorageFactory.hpp
)

set(SOURCES
    ${PROJECT_SOURCE_DIR}/src/JsonStorage.cpp
    ${PROJECT_SOURCE_DIR}/src/XmlStorage.cpp
    ${PROJECT_SOURCE_DIR}/src/YamlStorage.cpp
    ${PROJECT_SOURCE_DIR}/src/ValidatedStorage.cpp
    ${PROJECT_SOURCE_DIR}/src/StorageFactory.cpp
)

add_library(${PROJECT_NAME} STATIC ${SOURCES} ${HEADERS})

target_link_libraries(${PROJECT_NAME} PRIVATE
    yaml-cpp::yaml-cpp
    Common
    Interfaces
    External
)

target_include_directories(${PROJECT_NAME} PUBLIC ${PROJECT_SOURCE_DIR}/include)
