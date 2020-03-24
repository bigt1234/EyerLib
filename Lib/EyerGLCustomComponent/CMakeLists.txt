include_directories (../)
include_directories (./)

include_directories (${CMAKE_SOURCE_DIR}/../../Lib/glfw_install/include)
include_directories (../EyerGLAD/glad/include/)

add_library(
        EyerGLCustomComponent
        EyerGLCustomComponent.hpp
        EyerGLTextDraw.cpp
        EyerGLMVPTextureDraw.cpp
        EyerGLFrameDraw.cpp
        EyerGLSingleTextureDraw.cpp
        EyerGLYUV2TextureComponent.cpp
        )

target_link_libraries (EyerGLCustomComponent EyerCore)
target_link_libraries (EyerGLCustomComponent pthread)
target_link_libraries (EyerGLCustomComponent gtest)
target_link_libraries (EyerGLCustomComponent EyerType)
target_link_libraries (EyerGLCustomComponent EyerGL)
target_link_libraries (EyerGLCustomComponent EyerGLAD)
target_link_libraries (EyerGLCustomComponent ${CMAKE_SOURCE_DIR}/../../Lib/glfw_install/lib/libglfw3.a)

IF (CMAKE_SYSTEM_NAME MATCHES "Linux")
        MESSAGE(STATUS "current platform: Linux")
        target_link_libraries (EyerGLCustomComponent dl)
        target_link_libraries (EyerGLCustomComponent X11)
        target_link_libraries (EyerGLCustomComponent bz2)
ELSEIF (CMAKE_SYSTEM_NAME MATCHES "Windows")
        MESSAGE(STATUS "current platform: Windows")
        target_link_libraries (EyerGLCustomComponent bz2)
ELSEIF (CMAKE_SYSTEM_NAME MATCHES "Android")
        MESSAGE(STATUS "current platform: Android")
ELSEIF (CMAKE_SYSTEM_NAME MATCHES "Darwin")
        MESSAGE(STATUS "current platform: Darwin")
ELSE ()
        MESSAGE(STATUS "other platform: ${CMAKE_SYSTEM_NAME}")
ENDIF (CMAKE_SYSTEM_NAME MATCHES "Linux")

set(head_files
        EyerGLCustomComponent.hpp
        )

INSTALL(FILES ${head_files} DESTINATION include/EyerGLCustomComponent)
INSTALL(
        TARGETS EyerGLCustomComponent
        RUNTIME DESTINATION bin
        LIBRARY DESTINATION lib
        ARCHIVE DESTINATION lib
)
