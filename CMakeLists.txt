cmake_minimum_required(VERSION 3.5)
project(bf_compiler)
set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -g -O0")
# Add definitions
if(WIN32 AND CMAKE_INSTALL_PREFIX_INITIALIZED_TO_DEFAULT)
  set(CMAKE_INSTALL_PREFIX "C:/local" CACHE PATH "Installation directory" FORCE)
endif()
if(MSVC)
  add_definitions(-D_WIN32_WINNT=0x0501)
  set(CMAKE_CONFIGURATION_TYPES "Debug;Release" CACHE STRING "Configs")
else()
  set(CMAKE_BUILD_TYPE "Release" CACHE STRING "Choose the type of build")
  set(CMAKE_CXX_FLAGS "-std=c++11 ${CMAKE_CXX_FLAGS}")
endif()

# Set dependent libraries
set(HEADER_DIR "" CACHE PATH "The path to dependent headers")
set(LIBRARY_DIR "" CACHE PATH "The path to dependent libraries")
set(DEPENDENT_LIBS rs_navi opencv_highgui)
include_directories(
  ${HEADER_DIR}
)
link_directories(
  ${LIBRARY_DIR}
)

# Build information
set(EXECUTABLES "bf_compiler")
foreach(target IN LISTS EXECUTABLES)
  message("${target}")
  add_executable(${target} ${target}.cpp)
  target_link_libraries(${target} ${DEPENDENT_LIBS})
endforeach()

# Set installation
foreach(target IN LISTS EXECUTABLES)
  install(
    TARGETS ${target}
    RUNTIME DESTINATION bin
  )
endforeach()