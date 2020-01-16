include_directories (../)
include_directories (./)

add_library(
        EyerRender
        EyerRender.hpp
        EyerTgaImage.cpp)

target_link_libraries (EyerRender gtest)

set(head_files
        EyerRender.hpp
        EyerTGA.hpp
        )

INSTALL(FILES ${head_files} DESTINATION include/EyerRender)
INSTALL(
        TARGETS EyerRender
        RUNTIME DESTINATION bin
        LIBRARY DESTINATION lib
        ARCHIVE DESTINATION lib
)
