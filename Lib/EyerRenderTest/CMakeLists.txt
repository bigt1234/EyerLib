add_executable(
    EyerRenderTest
    Main.cpp
    )

include_directories (../)

target_link_libraries (EyerRenderTest EyerRender)

INSTALL(
    TARGETS EyerRenderTest
    RUNTIME DESTINATION bin        
    LIBRARY DESTINATION lib        
    ARCHIVE DESTINATION lib
    )