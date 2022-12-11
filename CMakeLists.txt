cmake_minimum_required(VERSION 3.24)
project(StuGPAManager)

set(CMAKE_CXX_STANDARD 17)

set(MYSQLCPPCONN_DIR "/home/sakuno/RequiredLibrarys/mysql-connector-c++-8.0.31-linux-glibc2.27-x86-64bit")

add_executable(StuGPAManager main.cpp Student.cpp Student.h CStudent.cpp CStudent.h FStudent.cpp FStudent.h Report.cpp Report.h GStudent.cpp GStudent.h)

target_include_directories(StuGPAManager PRIVATE ${MYSQLCPPCONN_DIR}/include/jdbc)

target_link_libraries(StuGPAManager ${MYSQLCPPCONN_DIR}/lib64/libmysqlcppconn.so)