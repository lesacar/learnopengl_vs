cmake_minimum_required(VERSION 3.10)
project(Engine)

set_property(DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR} PROPERTY VS_STARTUP_PROJECT Engine)

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/${CMAKE_BUILD_TYPE}/bin)
set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/${CMAKE_BUILD_TYPE}/obj)
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/${CMAKE_BUILD_TYPE}/obj)

file(MAKE_DIRECTORY ${CMAKE_RUNTIME_OUTPUT_DIRECTORY})
file(MAKE_DIRECTORY ${CMAKE_ARCHIVE_OUTPUT_DIRECTORY})
file(MAKE_DIRECTORY ${CMAKE_LIBRARY_OUTPUT_DIRECTORY})

set(SOURCE_DIR ${CMAKE_SOURCE_DIR}/src)
set(INCLUDE_DIR ${SOURCE_DIR}/include)
set(VENDOR_DIR ${CMAKE_SOURCE_DIR}/vendor)

find_package(OpenGL REQUIRED)
include_directories(${OPENGL_INCLUDE_DIRS})

add_subdirectory(${VENDOR_DIR}/glfw)

file(GLOB_RECURSE SRC_FILES ${SOURCE_DIR}/*.cpp)
file(GLOB_RECURSE HEADER_FILES ${SOURCE_DIR}/*.h ${SOURCE_DIR}/include/*.h)

set(SRC_FILES ${SRC_FILES} ${VENDOR_DIR}/glad/glad.c)
# set(SRC_FILES ${SRC_FILES} ${VENDOR_DIR}/imgui/backends/imgui_impl_opengl3.cpp)
# set(SRC_FILES ${SRC_FILES} ${VENDOR_DIR}/imgui/backends/imgui_impl_glfw.cpp)

file(GLOB IMGUI_SRC_FILES ${VENDOR_DIR}/imgui/*.cpp
    ${VENDOR_DIR}/imgui/backends/imgui_impl_opengl3.cpp
    ${VENDOR_DIR}/imgui/backends/imgui_impl_glfw.cpp
)
file(GLOB IMGUI_HEADER_FILES ${VENDOR_DIR}/imgui/*.h)
set(SRC_FILES ${SRC_FILES} ${IMGUI_SRC_FILES})
set(HEADER_FILES ${HEADER_FILES} ${IMGUI_HEADER_FILES})

# Group ImGui source files
source_group("imgui\\src" FILES ${IMGUI_SRC_FILES})
# Group ImGui header files
source_group("imgui\\headers" FILES ${IMGUI_HEADER_FILES})

add_executable(Engine ${SRC_FILES} ${HEADER_FILES})

target_compile_features(Engine PRIVATE cxx_std_17)

target_link_libraries(Engine PRIVATE glfw)

target_include_directories(Engine PRIVATE
    ${INCLUDE_DIR}
    ${VENDOR_DIR}/glfw/include
    ${VENDOR_DIR}/glm/include
    ${VENDOR_DIR}/glad/include
    ${VENDOR_DIR}/stb_image/include
    ${SOURCE_DIR}/include
    ${VENDOR_DIR}/imgui
    ${SOURCE_DIR}
)
