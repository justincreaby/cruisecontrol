set(PID_CONTROLLER_SRC_DIR "src")
set(PID_CONTROLLER_INC_DIR "include")

set(PID_CONTROLLER_SRC_FILES
  "pid_controller.cpp"
)

set(PID_CONTROLLER_INC_FILES
  "pid_controller.h"
)

# Prepend src and include files with their directories
PREPEND(PID_CONTROLLER_SRC_FILES ${PID_CONTROLLER_SRC_DIR} ${PID_CONTROLLER_SRC_FILES})
PREPEND(PID_CONTROLLER_INC_FILES ${PID_CONTROLLER_INC_DIR} ${PID_CONTROLLER_INC_FILES})

add_library(PIDController STATIC ${PID_CONTROLLER_SRC_FILES} ${PID_CONTROLLER_INC_FILES})

target_include_directories(PIDController PUBLIC ${PID_CONTROLLER_INC_DIR})

# Testing
add_executable(test_pid_controller test/test_pid_controller.cpp)
target_link_libraries(test_pid_controller gtest_main PIDController)
include(GoogleTest)
gtest_discover_tests(test_pid_controller)