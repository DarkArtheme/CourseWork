
set(SOURCE_FILES BaseEnemy.h BaseEnemy.cpp
        BaseTower.h BaseTower.cpp
        Button.h Button.cpp
        ContextMenu.h ContextMenu.cpp
        GridMaker.h GridMaker.cpp
        Loader.h Loader.cpp
        main.cpp
        TmxLevel.h TmxLevel.cpp
        LevelMaker.cpp LevelMaker.h )

#target_link_libraries(${PROJECT_NAME} tinyxml2)

if (CMAKE_BUILD_TYPE STREQUAL "Release")
    add_executable(${PROJECT_NAME} WIN32 ${SOURCE_FILES})
else ()
    add_executable(${PROJECT_NAME} ${SOURCE_FILES})
endif ()

set(EXECUTABLE_OUTPUT_PATH "${CMAKE_SOURCE_DIR}")
set(SFML_ROOT ${CMAKE_SOURCE_DIR}/libs/SFML)
set(SFML_STATIC_LIBRARIES TRUE)

set(CMAKE_MODULE_PATH "${CMAKE_SOURCE_DIR}/modules")
find_package(SFML REQUIRED COMPONENTS audio graphics window system)
if (SFML_FOUND)
    include_directories(${SFML_INCLUDE_DIR})
    target_link_libraries(${PROJECT_NAME} ${SFML_LIBRARIES} ${SFML_DEPENDENCIES} tinyxml2)
endif ()



