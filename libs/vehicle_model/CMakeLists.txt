set(VEHICLE_MODEL_SRC_DIR "src")
set(VEHICLE_MODEL_INC_DIR "include")

set(VEHICLE_MODEL_SRC_FILES
  "vehicle_model.cpp"
)

set(VEHICLE_MODEL_INC_FILES
  "vehicle_model.h"
)

# Prepend src and include files with their directories
PREPEND(VEHICLE_MODEL_SRC_FILES ${VEHICLE_MODEL_SRC_DIR} ${VEHICLE_MODEL_SRC_FILES})
PREPEND(VEHICLE_MODEL_INC_FILES ${VEHICLE_MODEL_INC_DIR} ${VEHICLE_MODEL_INC_FILES})

add_library(VehicleModel STATIC ${VEHICLE_MODEL_SRC_FILES} ${VEHICLE_MODEL_INC_FILES})

target_include_directories(VehicleModel PUBLIC ${VEHICLE_MODEL_INC_DIR})

# Testing
add_executable(test_vehicle_model test/test_vehicle_model.cpp)
target_link_libraries(test_vehicle_model gtest_main VehicleModel)
include(GoogleTest)
gtest_discover_tests(test_vehicle_model)