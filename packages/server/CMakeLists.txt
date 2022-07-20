

find_package(Boost COMPONENTS system thread REQUIRED)
if (Boost_FOUND)
    message(STATUS "Found Boost: ${FOLLY_LIBRARIES}")
    INCLUDE_DIRECTORIES(${Boost_INCLUDE_DIRS})
    LINK_LIBRARIES(${Boost_LIBRARIES})
endif (Boost_FOUND)

add_executable(sfx-server-api
        src/main.cc
        src/http_connection.h
        src/http_connection.cc
        src/handlers/index.h
        src/handlers/index.cpp
        src/utils/mime.cpp
        src/utils/mime.h)
