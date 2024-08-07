cmake_minimum_required(VERSION 3.6)

# Set the project name
project(Engine)

set_property(DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR} PROPERTY VS_STARTUP_PROJECT Engine)

# Set output directories for binaries and object files
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/${CMAKE_BUILD_TYPE}/bin)
set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/${CMAKE_BUILD_TYPE}/obj)
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/${CMAKE_BUILD_TYPE}/obj)

# Set the source and include directories
set(SOURCE_DIR ${CMAKE_SOURCE_DIR}/src)
set(INCLUDE_DIR ${SOURCE_DIR})
set(VENDOR_DIR ${CMAKE_SOURCE_DIR}/vendor)
set(INCLUDE_DIR)

# Include OpenGL
find_package(OpenGL REQUIRED)
include_directories(${OPENGL_INCLUDE_DIRS})

# Add GLFW as a subdirectory
add_subdirectory(${VENDOR_DIR}/glfw)

# Find all .cpp files in the src directory
file(GLOB_RECURSE SRC_FILES ${SOURCE_DIR}/*.cpp)
file(GLOB_RECURSE HEADER_FILES ${SOURCE_DIR}/*.h ${SOURCE_DIR}/include/*.h)

# Add vendor/glad/glad.c explicitly
set(SRC_FILES ${SRC_FILES} ${VENDOR_DIR}/glad/glad.c)
set(SRC_FILES ${SRC_FILES} ${VENDOR_DIR}/imgui/backends/imgui_impl_opengl3.cpp)
set(SRC_FILES ${SRC_FILES} ${VENDOR_DIR}/imgui/backends/imgui_impl_glfw.cpp)

file(GLOB IMGUI_SRC_FILES ${VENDOR_DIR}/imgui/*.cpp)
file(GLOB IMGUI_HEADER_FILES ${VENDOR_DIR}/imgui/*.h)
set(SRC_FILES ${SRC_FILES} ${IMGUI_SRC_FILES})
set(HEADER_FILES ${HEADER_FILES} ${IMGUI_HEADER_FILES})

# Specify the executable target
add_executable(Engine ${SRC_FILES} ${HEADER_FILES})

target_compile_features(Engine PRIVATE cxx_std_17)

# Link the GLFW library to your project
target_link_libraries(Engine PRIVATE glfw)

# Include directories for the project
target_include_directories(Engine PRIVATE ${INCLUDE_DIR}/include ${INCLUDE_DIR} ${VENDOR_DIR}/glfw/include ${VENDOR_DIR}/glm/include ${VENDOR_DIR}/glad/include ${VENDOR_DIR}/stb_image/include ${SOURCE_DIR}/include ${VENDOR_DIR}/imgui ${SOURCE_DIR} )

# Additional configurations and dependencies as necessary

