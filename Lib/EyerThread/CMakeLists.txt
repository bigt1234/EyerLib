include_directories (../)
include_directories (./)

add_library(
        EyerThread
        EyerThread.cpp
)

target_link_libraries (EyerThread pthread)

set(head_files
        EyerThread.hpp
        )

INSTALL(FILES ${head_files} DESTINATION include/EyerThread)
INSTALL(
        TARGETS EyerThread
        RUNTIME DESTINATION bin
        LIBRARY DESTINATION lib
        ARCHIVE DESTINATION lib
)
