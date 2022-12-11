cmake_minimum_required(VERSION 3.24)
project(StuGPAManager)

set(CMAKE_CXX_STANDARD 17)

set(MYSQLCPPCONN_DIR "/home/sakuno/RequiredLibrarys/mysql-connector-c++-8.0.31-linux-glibc2.27-x86-64bit")

add_executable(StuGPAManager main.cpp Student.cpp Student.h CStudent.cpp CStudent.h FStudent.cpp FStudent.h Report.cpp Report.h GStudent.cpp GStudent.h)

link_directories(StuGPAManager ${MYSQLCPPCONN_DIR}/include)

target_link_libraries(StuGPAManager PRIVATE ${MYSQLCPPCONN_DIR}/lib64/libmysqlcppconn8.so)