cmake_minimum_required(VERSION 3.14.0 FATAL_ERROR)

project(fletcher)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall -Werror")

option(FLETCHER_BUILD_CERATA "Build cerata library" OFF)
option(FLETCHER_BUILD_FLETCHGEN "Build fletchgen" OFF)
option(FLETCHER_BUILD_COMMON "Build common library" OFF)
option(FLETCHER_BUILD_AWS "Build aws platform library" OFF)
option(FLETCHER_BUILD_ECHO "Build echo platform library" OFF)
option(FLETCHER_BUILD_SNAP "Build snap platform library" OFF)
option(FLETCHER_BUILD_RUNTIME "Build runtime library" ON)

include(FetchContent)

FetchContent_Declare(cmake-modules
    GIT_REPOSITORY  https://github.com/abs-tudelft/cmake-modules.git
    GIT_TAG         master
    )
FetchContent_MakeAvailable(cmake-modules)

include(CompileUnits)

if(FLETCHER_BUILD_CERATA)
  add_subdirectory(codegen/cerata)
endif()

if(FLETCHER_BUILD_FLETCHGEN)
  add_subdirectory(codegen/fletchgen)
endif()

if(FLETCHER_BUILD_C)
  add_subdirectory(common/c)
endif()

if(FLETCHER_BUILD_COMMON)
  add_subdirectory(common/cpp)
endif()

if(FLETCHER_BUILD_AWS)
  add_subdirectory(platforms/aws-f1/runtime)
endif()

if(FLETCHER_BUILD_ECHO)
  add_subdirectory(platforms/echo/runtime)
endif()

if(FLETCHER_BUILD_SNAP)
  add_subdirectory(platforms/snap/runtime)
endif()

if(FLETCHER_BUILD_RUNTIME)
  add_subdirectory(runtime/cpp)
endif()
