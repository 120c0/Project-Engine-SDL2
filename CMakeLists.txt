cmake_minimum_required(VERSION 3.16.3)
project(Quantum_Invasion VERSION 0.0.1)

file(GLOB SRC_FILES_CLASS "src/**/**.c*")
file(GLOB INL_FILES "lib/**/**.inl")
file(GLOB LIB_FILES "lib/**/**.c*")

add_executable(${PROJECT_NAME}
  src/main.cpp
  ${SRC_FILES_CLASS}
  ${INL_FILES}
  ${LIB_FILES}
)
find_package(tmx REQUIRED)
target_link_libraries(${PROJECT_NAME} PRIVATE tmx)
target_link_libraries( ${PROJECT_NAME} PUBLIC
  SDL2_image
  SDL2
  GLU
  GL
  tmx
  z
)
target_include_directories(${PROJECT_NAME} PUBLIC
  src
  lib
)
target_compile_options(${PROJECT_NAME} PUBLIC
  -O0
)