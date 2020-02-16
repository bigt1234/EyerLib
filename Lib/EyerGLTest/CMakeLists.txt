add_executable(
        EyerGLTest
        Main.cpp
)

include_directories (../)

target_link_libraries (EyerGLTest EyerCore)
target_link_libraries (EyerGLTest EyerGL)
target_link_libraries (EyerGLTest EyerType)

INSTALL(
        TARGETS EyerGLTest
        RUNTIME DESTINATION bin
        LIBRARY DESTINATION lib
        ARCHIVE DESTINATION lib
)
