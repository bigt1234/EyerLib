include_directories (../)
include_directories (./)

add_library(
        EyerImg
        EyerImg.cpp
)

target_link_libraries (EyerImg gtest)

set(head_files
        stb_image.h
        )

INSTALL(FILES ${head_files} DESTINATION include/EyerImg)
INSTALL(
        TARGETS EyerImg
        RUNTIME DESTINATION bin
        LIBRARY DESTINATION lib
        ARCHIVE DESTINATION lib
)
