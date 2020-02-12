include_directories (../)
include_directories (./)
include_directories (${CMAKE_SOURCE_DIR}/../../Lib/libyuv_install/include)

add_library(
        EyerYUV
        EyerYUV.cpp
)

target_link_libraries (EyerYUV EyerCore)

set(head_files
        EyerYUV.hpp
        )

INSTALL(FILES ${head_files} DESTINATION include/EyerYUV)
INSTALL(
        TARGETS EyerYUV
        RUNTIME DESTINATION bin
        LIBRARY DESTINATION lib
        ARCHIVE DESTINATION lib
)
