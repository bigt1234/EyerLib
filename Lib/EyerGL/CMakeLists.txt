include_directories (../)
include_directories (./)

add_library(
        EyerGL
        EyerGL.hpp
        EyerGLWindow.cpp)

target_link_libraries (EyerGL pthread)
target_link_libraries (EyerGL gtest)

set(head_files
        EyerGL.hpp
        )

INSTALL(FILES ${head_files} DESTINATION include/EyerGL)
INSTALL(
        TARGETS EyerGL
        RUNTIME DESTINATION bin
        LIBRARY DESTINATION lib
        ARCHIVE DESTINATION lib
)
