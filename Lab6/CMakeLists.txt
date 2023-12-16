cmake_minimum_required(VERSION 3.26)
project(Lab6)

set(CMAKE_CXX_STANDARD 17)

add_executable(Lab6 main.cpp
        h/Controls.h
        src/Controls.cpp
        src/Control.cpp
        h/Control.h
        src/LinuxControls.cpp
        h/LinuxControls.h
        src/LinuxFactory.cpp
        h/LinuxFactory.h
        src/MacOSControls.cpp
        h/MacOSControls.h
        src/MacOSFactory.cpp
        h/MacOSFactory.h
        h/Factory.h
        src/UIFactory.cpp
        h/WindowsControls.h
        src/WindowsControls.cpp
        h/WindowsFactory.h
        src/WindowsFactory.cpp)
