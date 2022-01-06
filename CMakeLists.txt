# cmake最低版本号
cmake_minimum_required( VERSION 3.20.0 )

# 项目名称
project( chibicpp )

# 添加源代码文件
set( SOURCES
  src/main.cc  # 这个项目的驱动文件
)

# 编译参数
add_compile_options( -Wall )

# 可执行文件名称
add_executable( ${PROJECT_NAME} ${SOURCES} )

# 头文件
target_include_directories( ${PROJECT_NAME}
  PRIVATE
    ${PROJECT_SOURCE_DIR}/include
)

# 可执行文件输出到build/bin
set_target_properties( ${PROJECT_NAME}
  PROPERTIES
    RUNTIME_OUTPUT_DIRECTORY ${CMAKE_CURRENT_BINARY_DIR}/bin
)

# 打开C++调试头文件
set(CMAKE_CXX_FLAGS_DEBUG "${CMAKE_CXX_FLAGS_DEBUG} -D_GLIBCXX_DEBUG")
