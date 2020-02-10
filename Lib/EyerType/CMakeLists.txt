include_directories (../)
include_directories (./)
include_directories (${CMAKE_SOURCE_DIR}/../../Lib/freetype_install/include/freetype2)

add_library(
        EyerType
        EyerType.cpp
        EyerTypePrivate.hpp
)

target_link_libraries (EyerType EyerCore)
target_link_libraries (EyerType pthread)
target_link_libraries (EyerType ${CMAKE_SOURCE_DIR}/../../Lib/freetype_install/lib/libfreetype.a)
target_link_libraries (EyerType png)
target_link_libraries (EyerType z)
target_link_libraries (EyerType harfbuzz)

set(head_files
        EyerType.hpp
        )

INSTALL(FILES ${head_files} DESTINATION include/EyerType)
INSTALL(
        TARGETS EyerType
        RUNTIME DESTINATION bin
        LIBRARY DESTINATION lib
        ARCHIVE DESTINATION lib
)
