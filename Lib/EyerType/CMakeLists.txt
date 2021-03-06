include_directories (../)
include_directories (./)
include_directories (${CMAKE_SOURCE_DIR}/../../Lib/freetype_install/include/freetype2)

add_library(
        EyerType
        EyerType.cpp
        EyerTypeBitmap.cpp
        EyerTypePrivate.hpp
)

target_link_libraries (EyerType EyerCore)
target_link_libraries (EyerType pthread)
target_link_libraries (EyerType ${CMAKE_SOURCE_DIR}/../../Lib/freetype_install/lib/libfreetype.a)
target_link_libraries (EyerType ${CMAKE_SOURCE_DIR}/../../Lib/libpng_install/lib/libpng.a)

IF (CMAKE_SYSTEM_NAME MATCHES "Linux")
    MESSAGE(STATUS "current platform: Linux ")
    target_link_libraries (EyerType z)
    target_link_libraries (EyerType harfbuzz)
    target_link_libraries (EyerType ${CMAKE_SOURCE_DIR}/../../Lib/libpng_install/lib/libpng.a)
    target_link_libraries (EyerType bz2)
ELSEIF (CMAKE_SYSTEM_NAME MATCHES "Windows")
    MESSAGE(STATUS "current platform: Windows")
    target_link_libraries (EyerType z)
    target_link_libraries (EyerType bz2)
    
ELSEIF (CMAKE_SYSTEM_NAME MATCHES "Android")
    MESSAGE(STATUS "current platform: Android")
ELSEIF (CMAKE_SYSTEM_NAME MATCHES "Darwin")
    MESSAGE(STATUS "current platform: Darwin")
    target_link_libraries (EyerType bz2)
    target_link_libraries (EyerType z)
    target_link_libraries (EyerType ${CMAKE_SOURCE_DIR}/../../Lib/libpng_install/lib/libpng.a)
ELSE ()
    MESSAGE(STATUS "other platform: ${CMAKE_SYSTEM_NAME}")
ENDIF (CMAKE_SYSTEM_NAME MATCHES "Linux")

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
