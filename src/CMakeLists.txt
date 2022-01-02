IF(INTERFACE_LIBRARY)
    target_sources(${TARGET_NAME_LIB} INTERFACE 
    hello.hpp
    hello.ipp
    allTheIppFiles.cpp
    allTheIppFiles.hpp
)
ELSE()
    target_sources(${TARGET_NAME_LIB} PUBLIC 
    hello.hpp
    hello.ipp
    allTheIppFiles.cpp
    allTheIppFiles.hpp
)
ENDIF()