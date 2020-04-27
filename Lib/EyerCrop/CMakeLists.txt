include_directories (../)
include_directories (./)

add_library(
    EyerCrop
    EyerAVCropUtil.cpp
)

target_link_libraries (EyerCrop EyerCore)

set(head_files 
    EyerCrop.hpp
)

INSTALL(FILES ${head_files} DESTINATION include/EyerCrop)
INSTALL(
    TARGETS EyerCrop
    RUNTIME DESTINATION bin        
    LIBRARY DESTINATION lib
    ARCHIVE DESTINATION lib
    )
