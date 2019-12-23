include_directories (../)
include_directories (./)

add_library(
    EyerAV
    EyerAVPacket.cpp
    EyerAVReader.cpp
    EyerAVDecoder.cpp
    EyerEyeStream.cpp
    EyerAVFrame.cpp
)

target_link_libraries (EyerAV pthread)
target_link_libraries (EyerAV EyerCore)

IF (CMAKE_SYSTEM_NAME MATCHES "Linux")
    MESSAGE(STATUS "current platform: Linux ")

    include_directories (../3rdpart/linux/ffmpeg_install/include)
    target_link_libraries (EyerAV ${CMAKE_SOURCE_DIR}/3rdpart/linux/ffmpeg_install/lib/libavformat.a)
    target_link_libraries (EyerAV ${CMAKE_SOURCE_DIR}/3rdpart/linux/ffmpeg_install/lib/libavdevice.a)
    target_link_libraries (EyerAV ${CMAKE_SOURCE_DIR}/3rdpart/linux/ffmpeg_install/lib/libavcodec.a)
    target_link_libraries (EyerAV ${CMAKE_SOURCE_DIR}/3rdpart/linux/ffmpeg_install/lib/libavutil.a)
    target_link_libraries (EyerAV ${CMAKE_SOURCE_DIR}/3rdpart/linux/ffmpeg_install/lib/libavfilter.a)
    target_link_libraries (EyerAV ${CMAKE_SOURCE_DIR}/3rdpart/linux/ffmpeg_install/lib/libswresample.a)
    target_link_libraries (EyerAV ${CMAKE_SOURCE_DIR}/3rdpart/linux/ffmpeg_install/lib/libswscale.a)
    target_link_libraries (EyerAV ${CMAKE_SOURCE_DIR}/3rdpart/linux/x264_install/lib/libx264.a)
    target_link_libraries (EyerAV dl)

ELSEIF (CMAKE_SYSTEM_NAME MATCHES "Windows")
    MESSAGE(STATUS "current platform: Windows")
ELSEIF (CMAKE_SYSTEM_NAME MATCHES "Android")
    MESSAGE(STATUS "current platform: Android")
ELSEIF (CMAKE_SYSTEM_NAME MATCHES "Darwin")
    MESSAGE(STATUS "current platform: Darwin")
ELSE ()
    MESSAGE(STATUS "other platform: ${CMAKE_SYSTEM_NAME}")

    include_directories (../3rdpart/mac/ffmpeg_install/include)
    target_link_libraries (EyerAV ${CMAKE_SOURCE_DIR}/3rdpart/mac/ffmpeg_install/lib/libavcodec.a)
    target_link_libraries (EyerAV ${CMAKE_SOURCE_DIR}/3rdpart/mac/ffmpeg_install/lib/libavformat.a)
    target_link_libraries (EyerAV ${CMAKE_SOURCE_DIR}/3rdpart/mac/ffmpeg_install/lib/libavfilter.a)
    target_link_libraries (EyerAV ${CMAKE_SOURCE_DIR}/3rdpart/mac/ffmpeg_install/lib/libavdevice.a)
    target_link_libraries (EyerAV ${CMAKE_SOURCE_DIR}/3rdpart/mac/ffmpeg_install/lib/libavutil.a)
    target_link_libraries (EyerAV ${CMAKE_SOURCE_DIR}/3rdpart/mac/ffmpeg_install/lib/libswresample.a)
    target_link_libraries (EyerAV ${CMAKE_SOURCE_DIR}/3rdpart/mac/ffmpeg_install/lib/libswscale.a)
    target_link_libraries (EyerAV bz2)
    target_link_libraries (EyerAV z)
    target_link_libraries (EyerAV lzma)
    target_link_libraries (EyerAV iconv)
    target_link_libraries (EyerAV ${CMAKE_SOURCE_DIR}/3rdpart/mac/x264_install/lib/libx264.a)

ENDIF (CMAKE_SYSTEM_NAME MATCHES "Linux")

set(head_files 
    EyerAV.hpp 
)

INSTALL(FILES ${head_files} DESTINATION include/EyerAV)
INSTALL(
    TARGETS EyerAV
    RUNTIME DESTINATION bin        
    LIBRARY DESTINATION lib
    ARCHIVE DESTINATION lib
    )

