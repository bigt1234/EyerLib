include_directories (../)
include_directories (./)

include_directories (../3rdpart/mac/ffmpeg_install/include)

add_library(
    EyerAV
    EyerAVPacket.cpp
    EyerAVReader.cpp
)

target_link_libraries (EyerAV pthread)

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

