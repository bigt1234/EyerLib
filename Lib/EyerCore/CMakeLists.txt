include_directories (../)
include_directories (./)

add_library(
    EyerCore

    RedThread.cpp
    RedTime.cpp
    RedLog.cpp
    RedArg.cpp
    RedFile.cpp
    RedFileList.cpp
    RedString.cpp
    RedYuv.cpp
    RedYuvQueue.cpp
    RedQueue.cpp
    RedMap.cpp
    RedLruMap.cpp
    RedByte.cpp

    EyerString.cpp

    EyerCore.hpp
    EyerString.hpp
)

target_link_libraries (EyerCore pthread)
target_link_libraries (EyerCore gtest)

set(head_files 
    Red.hpp 
    RedArg.hpp
    RedByte.hpp
    RedFile.hpp
    RedIPAddr.hpp
    RedLog.hpp
    RedLruMap.hpp
    RedMap.hpp
    RedQueue.hpp
    RedString.hpp
    RedYuv.hpp
    RedYuvQueue.hpp
    EyerString.hpp
    EyerCore.hpp
)

INSTALL(FILES ${head_files} DESTINATION include/EyerCore)
INSTALL(
    TARGETS EyerCore
    RUNTIME DESTINATION bin        
    LIBRARY DESTINATION lib
    ARCHIVE DESTINATION lib
    )
