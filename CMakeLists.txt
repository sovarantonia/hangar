cmake_minimum_required(VERSION 3.17)
project(prj)

set(CMAKE_CXX_STANDARD 14)

add_executable(prj main.cpp Vehicle.cpp Vehicle.h Airplane.cpp Airplane.h Helicopter.cpp Helicopter.h Repository.cpp Repository.h Service.cpp Service.h test_domain.cpp test_domain.h test_repository.cpp test_repository.h test_service.cpp test_service.h all_tests.cpp all_tests.h VehicleException.cpp VehicleException.h VehicleValidator.cpp VehicleValidator.h ServiceException.cpp ServiceException.h UI.cpp UI.h)