cmake_minimum_required(VERSION 3.0 FATAL_ERROR)

set(PROJECT_NAME PhysicEngine2D)
project(${PROJECT_NAME})

include(FetchContent)
set(BUILD_SHARED_LIBS OFF)
set(BOOST_ENABLE_CMAKE ON)
FetchContent_Declare(
        SFML
        GIT_REPOSITORY https://github.com/SFML/SFML.git
        GIT_TAG 2.5.1
)
FetchContent_MakeAvailable(SFML)

FetchContent_Declare(
        TGUI
	GIT_REPOSITORY https://github.com/texus/TGUI.git
	GIT_TAG 0.8
)
FetchContent_MakeAvailable(TGUI)

FetchContent_Declare(
        BOOST_ALGORITHM
	GIT_REPOSITORY https://github.com/boostorg/algorithm.git
	GIT_TAG master
)
FetchContent_MakeAvailable(BOOST_ALGORITHM)

FetchContent_Declare(
        BOOST_FILESYSTEM
	GIT_REPOSITORY https://github.com/boostorg/filesystem.git
	GIT_TAG master
)
FetchContent_MakeAvailable(BOOST_ALGORITHM)

FetchContent_Declare(
        BOOST_LEXICAL_CAST
	GIT_REPOSITORY https://github.com/boostorg/lexical_cast.git
	GIT_TAG master
)
FetchContent_MakeAvailable(BOOST_LEXICAL_CAST)

FetchContent_Declare(
        BOX_2D
	GIT_REPOSITORY https://github.com/erincatto/box2d.git
	GIT_TAG v2.4.1
)
FetchContent_MakeAvailable(BOX_2D)


add_executable(${PROJECT_NAME} 
src/main.cpp

src/Graphics/b2GLDraw.cpp
    include/b2GLDraw.h
src/Graphics/gui.cpp
    include/gui.h
src/Graphics/scene.cpp
    include/scene.h
include/date.h
include/window_function.h
include/glext.h
) 

set_target_properties(
     ${PROJECT_NAME} PROPERTIES
     CXX_STANDARD 14
     CXX_STANDARD_REQUIRED ON
     CXX_EXTENSIONS NO
)


target_link_libraries(${PROJECT_NAME}
    PRIVATE
        sfml-audio
        sfml-graphics
        sfml-system
        sfml-window
	sfml-network
	tgui 
	tgui-d
	filesystem
)

