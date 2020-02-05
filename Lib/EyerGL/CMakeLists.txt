include_directories (../)
include_directories (./)

include_directories (${CMAKE_SOURCE_DIR}/../../Lib/glfw_install/include)
include_directories (glad/include/)

add_library(
        EyerGL
        EyerGL.hpp
        EyerGLWindow.cpp

        glad/src/glad.c
)

target_link_libraries (EyerGL EyerCore)
target_link_libraries (EyerGL pthread)
target_link_libraries (EyerGL gtest)
target_link_libraries (EyerGL ${CMAKE_SOURCE_DIR}/../../Lib/glfw_install/lib/libglfw3.a)
target_link_libraries (EyerGL dl)
target_link_libraries (EyerGL X11)

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
