add_executable(
        EyerTypeTest
        Main.cpp
)

include_directories (../)

target_link_libraries (EyerTypeTest EyerCore)
target_link_libraries (EyerTypeTest EyerType)

INSTALL(
        TARGETS EyerTypeTest
        RUNTIME DESTINATION bin
        LIBRARY DESTINATION lib
        ARCHIVE DESTINATION lib
)
