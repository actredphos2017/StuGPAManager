cmake_minimum_required(VERSION 3.24)
project(StuGPAManager)


set(CMAKE_CXX_STANDARD 17)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)
set(CMAKE_AUTOUIC ON)

set(CMAKE_PREFIX_PATH "/home/sakuno/Qt/6.4.1/gcc_64")

find_package(Qt6 COMPONENTS
        Core
        Gui
        Widgets
        REQUIRED)

set(nlohmann_json_DIR "/home/sakuno/RequiredLibrarys/json")

add_executable(StuGPAManager main.cpp Student.cpp Student.h CStudent.cpp CStudent.h FStudent.cpp FStudent.h Report.cpp Report.h GStudent.cpp GStudent.h VisualWindows/Menu.cpp VisualWindows/Menu.h VisualWindows/Menu.ui VisualWindows/InsertDialog.cpp VisualWindows/InsertDialog.h VisualWindows/CStudentScore.cpp VisualWindows/CStudentScore.h VisualWindows/FStudentScore.h VisualWindows/FStudentScore.cpp VisualWindows/GStudentScore.h VisualWindows/GStudentScore.cpp)

target_link_libraries(StuGPAManager
        Qt::Core
        Qt::Gui
        Qt::Widgets
        )

target_include_directories(StuGPAManager PRIVATE ${nlohmann_json_DIR}/include)