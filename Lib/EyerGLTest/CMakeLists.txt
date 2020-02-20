add_executable(
        EyerGLTest
        Main.cpp
)

include_directories (../)

target_link_libraries (EyerGLTest EyerCore)
target_link_libraries (EyerGLTest EyerGL)
target_link_libraries (EyerGLTest EyerType)

file(COPY
        ${CMAKE_CURRENT_SOURCE_DIR}/Manjari-Bold.otf
        DESTINATION
        ${CMAKE_CURRENT_BINARY_DIR}/
        )

INSTALL(
        TARGETS EyerGLTest
        RUNTIME DESTINATION bin
        LIBRARY DESTINATION lib
        ARCHIVE DESTINATION lib
)
