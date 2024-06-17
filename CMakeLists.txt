cmake_minimum_required(VERSION 3.5.0)

# set proj
set(PRESENT_TARGET "Exec")
project(${PRESENT_TARGET} VERSION 1.0 LANGUAGES CXX)

set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

# add cmake scripts
set(INCLUDE_CAMKES 
    ${PROJECT_SOURCE_DIR}/cmake/AutoSearch.cmake
    ${PROJECT_SOURCE_DIR}/cmake/ColorLog.cmake
    ${PROJECT_SOURCE_DIR}/cmake/QtMust.cmake
    ${PROJECT_SOURCE_DIR}/toolkit/mingw81_64.cmake
    )
foreach(cmake ${INCLUDE_CAMKES})
    include(${cmake})
endforeach()

# set install prefix
set(CMAKE_INSTALL_PREFIX ${PROJECT_SOURCE_DIR}/output)

# add headers dir
FIND_INCLUDE_DIR(INCLUDES ${PROJECT_SOURCE_DIR}/include)
FIND_INCLUDE_DIR(INCLUDES ${PROJECT_SOURCE_DIR}/src)
include_directories(${INCLUDES})

LOG_INFO("include directories:")
foreach(dir ${INCLUDES})
    message(STATUS ${dir})
endforeach()

# set lib dir
link_directories(${PROJECT_SOURCE_DIR}/lib)


# get_filename_component(DIR_NAME ${CMAKE_CURRENT_LIST_DIR} NAME)

# add source code
# set(SRC_DIR ${CMAKE_CURRENT_LIST_DIR}/src)
FIND_SRC_FILE(SRCS ${CMAKE_CURRENT_LIST_DIR}/src)

LOG_INFO("source files:")
foreach(file ${SRCS})
    message(STATUS ${file})
endforeach()

add_executable(${PRESENT_TARGET} ${SRCS})
# add_library()

# target_link_libraries()
# target_include_directories(${PROJ_NAME} PUBLIC include)

install(TARGETS ${PRESENT_TARGET}
        LIBRARY DESTINATION ${PRESENT_TARGET}                   # 动态库安装路径
        ARCHIVE DESTINATION ${PRESENT_TARGET}                   # 静态库安装路径
        RUNTIME DESTINATION ${PRESENT_TARGET}                   # 可执行文件安装路径
        PUBLIC_HEADER DESTINATION ${PRESENT_TARGET}/include/    # 头文件安装路径
        )

find_package(Qt5 COMPONENTS widgets Qml REQUIRED)
target_link_libraries(${PRESENT_TARGET} Qt5::Widgets Qt5::Qml)


