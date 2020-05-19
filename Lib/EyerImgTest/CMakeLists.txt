add_executable(
        EyerImgTest
        Main.cpp
    )

include_directories (../)

target_link_libraries (EyerImgTest EyerCore)
target_link_libraries (EyerImgTest EyerImg)

INSTALL(
    TARGETS EyerImgTest
    RUNTIME DESTINATION bin        
    LIBRARY DESTINATION lib        
    ARCHIVE DESTINATION lib
)

file(COPY
        ${CMAKE_CURRENT_SOURCE_DIR}/1.jpg
        DESTINATION
        ${CMAKE_CURRENT_BINARY_DIR}/
        )