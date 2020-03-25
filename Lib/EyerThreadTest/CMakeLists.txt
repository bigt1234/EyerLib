add_executable(
    EyerThreadTest
    Main.cpp
    )

include_directories (../)

target_link_libraries (EyerThreadTest EyerCore)
target_link_libraries (EyerThreadTest EyerThread)

INSTALL(
    TARGETS EyerThreadTest
    RUNTIME DESTINATION bin        
    LIBRARY DESTINATION lib        
    ARCHIVE DESTINATION lib
)