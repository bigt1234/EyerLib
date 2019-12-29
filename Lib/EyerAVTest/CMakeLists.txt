add_executable(
        EyerAVTest

        Test.cpp

        EyerAVDecoderTest.hpp
        EyerAVEncoderTest.hpp
        Path.hpp
        EyerAVFrameTest.hpp
)

include_directories (../)

target_link_libraries (EyerAVTest EyerCore)
target_link_libraries (EyerAVTest EyerAV)

INSTALL(
        TARGETS EyerAVTest
        RUNTIME DESTINATION bin
        LIBRARY DESTINATION lib
        ARCHIVE DESTINATION lib
        )
