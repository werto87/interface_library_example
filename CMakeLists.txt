cmake_minimum_required(VERSION 3.19)
project(project VERSION 1.0.0
  DESCRIPTION project
  LANGUAGES CXX
  )

  
OPTION(INTERFACE_LIBRARY "Do not build a library instead add headers and sources into the target linking to this library" OFF)
set(TARGET_NAME_LIB project_lib)
IF(INTERFACE_LIBRARY)
  add_library(${TARGET_NAME_LIB} INTERFACE)
  add_subdirectory(src) 
  target_include_directories(${TARGET_NAME_LIB} INTERFACE ${CMAKE_CURRENT_BINARY_DIR})
  target_include_directories(${TARGET_NAME_LIB} INTERFACE
    $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}>
    $<INSTALL_INTERFACE:${CMAKE_INSTALL_INCLUDEDIR}>
)
ELSE()
  add_library(${TARGET_NAME_LIB} STATIC)
  add_subdirectory(src) 
  target_include_directories(${TARGET_NAME_LIB} PUBLIC ${CMAKE_CURRENT_BINARY_DIR})
  target_include_directories(${TARGET_NAME_LIB} PUBLIC
    $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}>
    $<INSTALL_INTERFACE:${CMAKE_INSTALL_INCLUDEDIR}>
  )    
ENDIF()
set(TARGET_NAME project)
add_executable(${TARGET_NAME}  
  main.cpp
)
target_link_libraries(${TARGET_NAME} PRIVATE
  ${TARGET_NAME_LIB}
)