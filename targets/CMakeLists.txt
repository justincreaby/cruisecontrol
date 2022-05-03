add_executable(CruiseControl cruise_control_target.cpp)

target_compile_options(CruiseControl PRIVATE -Wall -Wextra -Werror)

target_link_libraries(CruiseControl PRIVATE
  PIDController  
  Threads::Threads)