include_directories (../)
include_directories (./)

add_library(
        EyerRender
        EyerRender.hpp
        EyerTgaImage.cpp

        EyerLine.hpp
        EyerLine.cpp

        EyerCanvas.hpp
        EyerCanvas.cpp

        EyerObjModel.cpp

        EyerVertex.hpp
        EyerVertex.cpp
        )

target_link_libraries (EyerRender gtest)
target_link_libraries (EyerRender EyerCore)

set(head_files
        EyerRender.hpp
        EyerTGA.hpp
        EyerLine.hpp
        EyerVertex.hpp
        )

INSTALL(FILES ${head_files} DESTINATION include/EyerRender)
INSTALL(
        TARGETS EyerRender
        RUNTIME DESTINATION bin
        LIBRARY DESTINATION lib
        ARCHIVE DESTINATION lib
)
