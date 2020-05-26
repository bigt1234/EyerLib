include_directories (../)
include_directories (./)

#link_directories()

add_library(EyerImgGen
            EyerImgGen.cpp)

target_link_libraries (EyerImgGen 
                        gtest)