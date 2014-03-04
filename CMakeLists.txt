project(Atenea)
cmake_minimum_required(VERSION 2.6)

#defines
add_definitions(-D UNIX)
add_definitions(-D LINUX)
add_definitions(-D _GNU_SOURCE)

SET(EXECUTABLE_OUTPUT_PATH ${PROJECT_SOURCE_DIR}/bin)

set (QT_USE_QTNETWORK true)
set (QT_USE_QTOPENGL true)

find_package ( Qt4 REQUIRED )

include_directories(${PROJECT_BINARY_DIR})

include ( ${QT_USE_FILE} )

include(src/shared/CMakeLists.txt.proto)
include(src/shared/CMakeLists.txt.inc)

include_directories(${PROJECT_SOURCE_DIR}/src)

set (SRCS
	src/atenea.cpp
)

set (arch ${CMAKE_SYSTEM_PROCESSOR})

message (STATUS "Build Type: ${CMAKE_BUILD_TYPE}")
message (STATUS "Arch: ${arch}")

if (${arch} MATCHES "x86_64")
	#set compiler flags here for x86_64
	set (cc_flags "")
elseif (${arch} MATCHES "x86")
	#set compiler flags here for x86
	set (cc_flags "")
endif()

#flags to set in debug mode
set (CMAKE_CXX_FLAGS_DEBUG "-g -Wl,--no-as-needed")

#flags to set in release mode
set (CMAKE_CXX_FLAGS_RELEASE "-DNDEBUG -O3 -march=native -Wl,--no-as-needed")

message( STATUS "CC Flags: ${CMAKE_CXX_FLAGS_RELEASE}")
message (STATUS "Custom CC Flags: ${cc_flags}")

add_definitions(${cc_flags})

## build the common code
add_library(atenealibs ${CC_PROTO} ${SHARED_SRCS})
add_dependencies(atenealibs GenerateProto)

set (libs ${QT_LIBRARIES} jpeg png protobuf pthread GL GLU atenealibs)

## build the main app
set (target atenea)
add_executable(${target} ${SRCS})
target_link_libraries(${target} ${libs})

