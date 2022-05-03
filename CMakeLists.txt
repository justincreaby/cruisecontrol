cmake_minimum_required(VERSION 3.16)

# set the project name
project(CRUISE_CONTROL VERSION 0.1 LANGUAGES CXX)

# C++ 11
# GoogleTest requires at least C++11
set(CMAKE_CXX_STANDARD 11)

set(THREADS_PREFER_PTHREAD_FLAG ON)
find_package (Threads REQUIRED)

# GoogleTest: https://google.github.io/googletest/quickstart-cmake.html
include(FetchContent)
FetchContent_Declare(
  googletest
  URL https://github.com/google/googletest/archive/609281088cfefc76f9d0ce82e1ff6c30cc3591e5.zip
)
# For Windows: Prevent overriding the parent project's compiler/linker settings
set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)
FetchContent_MakeAvailable(googletest)

enable_testing()

# Prepend function
# https://stackoverflow.com/questions/4346412/how-to-prepend-all-filenames-on-the-list-with-common-path/27630120
# To use: PREPEND(FILES_TO_TRANSLATE ${CMAKE_CURRENT_SOURCE_DIR} ${SRC_FILES})
FUNCTION(PREPEND var prefix)
   SET(listVar "")
   FOREACH(f ${ARGN})
      LIST(APPEND listVar "${prefix}/${f}")
   ENDFOREACH(f)
   SET(${var} "${listVar}" PARENT_SCOPE)
ENDFUNCTION(PREPEND)

# Library subdirectories
add_subdirectory("libs/pid_controller")
add_subdirectory("libs/vehicle_model")

# Target subdirectories
add_subdirectory("targets")