PROJECT(EYE_Lib)

CMAKE_MINIMUM_REQUIRED(VERSION 2.6)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

MESSAGE(STATUS "operation system is ${CMAKE_SYSTEM}")

SET(CMAKE_INSTALL_PREFIX ${CMAKE_SOURCE_DIR}/install/)

include_directories (googletest/googletest/include)

IF (CMAKE_SYSTEM_NAME MATCHES "Linux")
    MESSAGE(STATUS "current platform: Linux ")
ELSEIF (CMAKE_SYSTEM_NAME MATCHES "Windows")
    MESSAGE(STATUS "current platform: Windows")
ELSEIF (CMAKE_SYSTEM_NAME MATCHES "Android")
    MESSAGE(STATUS "current platform: Android")
ELSEIF (CMAKE_SYSTEM_NAME MATCHES "Darwin")
    MESSAGE(STATUS "current platform: Darwin")
    set(CMAKE_EXE_LINKER_FLAGS
        "-framework IOKit -framework AudioToolbox -framework CoreGraphics -framework CoreMedia -framework Cocoa -framework VideoToolbox -framework AVFoundation -framework Security -framework CoreFoundation -framework CoreVideo -framework OpenGL -framework AppKit -framework CoreImage -framework VideoDecodeAcceleration"
    )
ELSE ()
    MESSAGE(STATUS "other platform: ${CMAKE_SYSTEM_NAME}")
ENDIF (CMAKE_SYSTEM_NAME MATCHES "Linux")

ADD_SUBDIRECTORY(EyerCore)
ADD_SUBDIRECTORY(EyerCoreTest)
ADD_SUBDIRECTORY(EyerAV)
ADD_SUBDIRECTORY(EyerAVTest)
ADD_SUBDIRECTORY(EyerGL)
ADD_SUBDIRECTORY(EyerGLTest)
ADD_SUBDIRECTORY(EyerRender)
ADD_SUBDIRECTORY(EyerRenderTest)
ADD_SUBDIRECTORY(EyerType)
ADD_SUBDIRECTORY(EyerTypeTest)
ADD_SUBDIRECTORY(EyerYUV)

ADD_SUBDIRECTORY(googletest)