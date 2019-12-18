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
)


target_link_libraries(EyerCore pthread)

INSTALL(
    TARGETS EyerCore
    RUNTIME DESTINATION bin        
    LIBRARY DESTINATION lib
    ARCHIVE DESTINATION lib
    )