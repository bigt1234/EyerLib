include_directories (../)
include_directories (./)

add_library(
        EyerGLRenderTask
        EyerGLRenderTask.cpp
        EyerGLRenderTaskQueue.cpp
        JuliaRenderTask.cpp
        )

target_link_libraries (EyerGLRenderTask EyerGL)
target_link_libraries (EyerGLRenderTask EyerCore)

set(head_files
        EyerGLRenderTask.hpp
        )

INSTALL(FILES ${head_files} DESTINATION include/EyerGLRenderTask)
INSTALL(
        TARGETS EyerGLRenderTask
        RUNTIME DESTINATION bin
        LIBRARY DESTINATION lib
        ARCHIVE DESTINATION lib
)
