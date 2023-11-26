cmake_minimum_required(VERSION 3.26)
project(Lab_5)

set(CMAKE_CXX_STANDARD 17)

add_executable(Lab_5 main.cpp
        src/FileUserManager.cpp
        src/FileUserRepository.cpp
        h/FileUserManager.h
        h/FileUserRepository.h
        h/IUserManager.h
        h/IUserRepository.h
        h/User.h
        h/App.h
        src/App.cpp)
