cmake_minimum_required(VERSION 3.5.1)

include(cmake_helpers/helpers_c.cmake)

project(counter_strike)

set(INC_DIR include)
set(SRC_DIR src)
set(INC_DIR_WEAPONS include/Weapons)
set(INC_DIR_PLAYERS include/Players)
set(INC_DIR_UTILITIES include/Utilities)
set(SRC_DIR_WEAPONS src/Weapons)
set(SRC_DIR_PLAYERS src/Players)
set(SRC_DIR_UTILITIES src/Utilities)

#generate project binary
add_executable(
        ${PROJECT_NAME}
        ${INC_DIR}/BattleField.h
        ${INC_DIR_PLAYERS}/Player.h
        ${INC_DIR_PLAYERS}/PlayerVitalData.h
        ${INC_DIR_UTILITIES}/Defines.h
        ${INC_DIR_UTILITIES}/ErrorHandling.h
        ${INC_DIR_UTILITIES}/Utilities.h
        ${INC_DIR_WEAPONS}/Pistol.h


        ${SRC_DIR}/main.c
        ${SRC_DIR}/BattleField.c
        ${SRC_DIR_PLAYERS}/Player.c
        ${SRC_DIR_PLAYERS}/PlayerVitalData.c
        ${SRC_DIR_UTILITIES}/ErrorHandling.c
        ${SRC_DIR_UTILITIES}/Utilities.c
        ${SRC_DIR_WEAPONS}/Pistol.c
)

add_subdirectory(Vector)
target_include_directories(
        ${PROJECT_NAME}
        PRIVATE
        ${INC_DIR}
        PUBLIC
        Vector
)



target_link_directories(${PROJECT_NAME} PRIVATE Vector)

target_link_libraries(${PROJECT_NAME} vector)

set_target_c_standard(${PROJECT_NAME} 11)
enable_target_c_warnings(${PROJECT_NAME})
