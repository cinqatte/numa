cmake_minimum_required(VERSION 3.10)

project(numa VERSION 0.0.1 LANGUAGES C)

set(CMAKE_C_STANDARD 99)
set(CMAKE_C_STANDARD_REQUIRED ON)

set(INSTALL_DIR "/usr/local" CACHE PATH "installation directory")
option(BUILD_SHARED_LIBS "build as shared library" OFF)

include_directories(${PROJECT_SOURCE_DIR}/include)

set(SOURCE_FILES numa.c)
set(HEADER_FILES numa.h)

if(BUILD_SHARED_LIBS)
    add_library(${PROJECT_NAME} SHARED ${SOURCE_FILES})
else()
    add_library(${PROJECT_NAME} STATIC ${SOURCE_FILES})
endif()

set_target_properties(${PROJECT_NAME} PROPERTIES
    VERSION ${PROJECT_VERSION}
    COMPATIBILITY SameMajorVersion
)

install(TARGETS ${PROJECT_NAME}
    LIBRARY DESTINATION ${INSTALL_DIR}/lib
    ARCHIVE DESTINATION ${INSTALL_DIR}/lib
)

install(FILES ${HEADER_FILES} DESTINATION ${INSTALL_DIR}/include)

message(STATUS "")
message(STATUS "===== numa configuration summary =====")
message(STATUS "library name: ${PROJECT_NAME}")
if(BUILD_SHARED_LIBS)
    message(STATUS "library type: shared")
else()
    message(STATUS "library type: static")
endif()
message(STATUS "install directory: ${INSTALL_DIR}")
message(STATUS "======================================")
message(STATUS "")
