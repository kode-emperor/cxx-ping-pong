cmake_minimum_required(VERSION 3.29)
project(PingPongXX LANGUAGES CXX)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)

file(GLOB SRC src/*.c++ src/*.cpp)
message("Collected sources files are: ${SRC}")
add_executable(PingPongXX ${SRC})

if(APPLE) 
    list(APPEND CMAKE_PREFIX_PATH "usr/local/lib/cmake/SFML")
elseif(WIN32)
    list(APPEND CMAKE_PREFIX_PATH "C:\\Program Files (x86)\\SFML")
endif()

find_package(Boost 1.84.0 COMPONENTS program_options REQUIRED)
find_package(SFML 2.6.1 COMPONENTS system window graphics REQUIRED)

target_link_libraries(PingPongXX PRIVATE Boost::program_options sfml-graphics)
target_compile_features(PingPongXX PRIVATE cxx_std_20)

if(WIN32)
    add_custom_command(
        TARGET PingPongXX
        COMMENT "Copy OpenAL DLL"
        PRE_BUILD COMMAND ${CMAKE_COMMAND} -E copy ${SFML_SOURCE_DIR}/extlibs/bin/$<IF:$<EQUAL:${CMAKE_SIZEOF_VOID_P},8>,x64,x86>/openal32.dll $<TARGET_FILE_DIR:PingPongXX>
        VERBATIM)
endif()

install(TARGETS PingPongXX)