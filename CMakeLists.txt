cmake_minimum_required(VERSION 3.16)
project(LeetCode)

# -------------------------
# C++ 基础配置
# -------------------------
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -O2 -Wall")

# 可执行文件输出目录
set(EXECUTABLE_OUTPUT_PATH ${CMAKE_CURRENT_SOURCE_DIR}/Target_run)

# -------------------------
# 定义宏：为每个 .cpp 文件生成可执行文件
# -------------------------
macro(add_single_cpp FILE)
    get_filename_component(NAME ${FILE} NAME_WE)
    add_executable(${NAME} ${FILE})
    set_target_properties(${NAME} PROPERTIES
            RUNTIME_OUTPUT_DIRECTORY ${EXECUTABLE_OUTPUT_PATH}
    )
endmacro()

# -------------------------
# 自动递归扫描所有 .cpp 文件
# -------------------------
file(GLOB_RECURSE ALL_CPP_FILES "${CMAKE_CURRENT_SOURCE_DIR}/*.cpp")

foreach(FILE_PATH ${ALL_CPP_FILES})
    add_single_cpp(${FILE_PATH})
endforeach()

# -------------------------
# 输出提示信息（方便确认）
# -------------------------
message(STATUS "Detected source files:")
foreach(FILE_PATH ${ALL_CPP_FILES})
    message(STATUS "  ${FILE_PATH}")
endforeach()
message(STATUS "Executables will be in: ${EXECUTABLE_OUTPUT_PATH}")
