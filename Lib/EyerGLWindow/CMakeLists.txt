include_directories (../)
include_directories (./)

include_directories (${CMAKE_SOURCE_DIR}/../../Lib/glfw_install/include)
include_directories (../EyerGLAD/glad/include/)

add_library(
        EyerGLWindow
        EyerGLWindow.hpp
        EyerGLWindow.cpp
        )

target_link_libraries (EyerGLWindow EyerCore)
target_link_libraries (EyerGLWindow pthread)
target_link_libraries (EyerGLWindow gtest)
target_link_libraries (EyerGLWindow EyerType)
target_link_libraries (EyerGLWindow EyerGLAD)
target_link_libraries (EyerGLWindow ${CMAKE_SOURCE_DIR}/../../Lib/glfw_install/lib/libglfw3.a)

IF (CMAKE_SYSTEM_NAME MATCHES "Linux")
        MESSAGE(STATUS "current platform: Linux")
        target_link_libraries (EyerGLWindow dl)
        target_link_libraries (EyerGLWindow X11)
        target_link_libraries (EyerGLWindow bz2)
ELSEIF (CMAKE_SYSTEM_NAME MATCHES "Windows")
        MESSAGE(STATUS "current platform: Windows")
        target_link_libraries (EyerGLWindow bz2)
ELSEIF (CMAKE_SYSTEM_NAME MATCHES "Android")
        MESSAGE(STATUS "current platform: Android")
ELSEIF (CMAKE_SYSTEM_NAME MATCHES "Darwin")
        MESSAGE(STATUS "current platform: Darwin")
ELSE ()
        MESSAGE(STATUS "other platform: ${CMAKE_SYSTEM_NAME}")
ENDIF (CMAKE_SYSTEM_NAME MATCHES "Linux")

set(head_files
        EyerGLWindow.hpp
        )

INSTALL(FILES ${head_files} DESTINATION include/EyerGLWindow)
INSTALL(
        TARGETS EyerGLWindow
        RUNTIME DESTINATION bin
        LIBRARY DESTINATION lib
        ARCHIVE DESTINATION lib
)
