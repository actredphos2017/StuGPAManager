cmake_minimum_required(VERSION 3.24)
project(StuGPAManager)

set(CMAKE_CXX_STANDARD 17)

set(nlohmann_json_DIR "/home/sakuno/RequiredLibrarys/json")

add_executable(StuGPAManager main.cpp Student.cpp Student.h CStudent.cpp CStudent.h FStudent.cpp FStudent.h Report.cpp Report.h GStudent.cpp GStudent.h)

target_include_directories(StuGPAManager PRIVATE ${MYSQLCPPCONN_DIR}/include/jdbc)

target_include_directories(StuGPAManager PRIVATE ${nlohmann_json_DIR}/include)