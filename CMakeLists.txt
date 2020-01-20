cmake_minimum_required (VERSION 3.1)
project (JNP1-zadanie6 CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_FLAGS "-Wall -Wextra -O2")

# http://stackoverflow.com/questions/10555706/
macro (add_executable _name)
    # invoke built-in add_executable
    _add_executable(${ARGV})
    if (TARGET ${_name})
        target_link_libraries(${_name} ${CMAKE_THREAD_LIBS_INIT} )
    endif()
endmacro()

#add_executable(playlist_example playlist_example.cc Playlist.h PlayingMode.h PlaylistEntry.h)
add_executable(test test.cc File.cc Track.cc TrackFactory.cc Song.cc)
# tu mozna dodac nowe executable

install(TARGETS DESTINATION .)

