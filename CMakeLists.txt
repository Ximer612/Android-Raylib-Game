cmake_minimum_required(VERSION 3.28)
project(AndroidRaylibGame)

# Enable Hot Reload for MSVC compilers if supported.
if (POLICY CMP0141)
  cmake_policy(SET CMP0141 NEW)
  set(CMAKE_MSVC_DEBUG_INFORMATION_FORMAT "$<IF:$<AND:$<C_COMPILER_ID:MSVC>,$<CXX_COMPILER_ID:MSVC>>,$<$<CONFIG:Debug,RelWithDebInfo>:EditAndContinue>,$<$<CONFIG:Debug,RelWithDebInfo>:ProgramDatabase>>")
endif()

# Adding Raylib
include(FetchContent)
set(BUILD_EXAMPLES OFF CACHE BOOL "" FORCE) # don't build the supplied examples
set(BUILD_GAMES    OFF CACHE BOOL "" FORCE) # don't build the supplied example games
FetchContent_Declare(raylib GIT_REPOSITORY https://github.com/raysan5/raylib.git GIT_TAG master)
FetchContent_MakeAvailable(raylib)


set(EXEC_TARGET AppPrj)
file(GLOB_RECURSE SOURCES ${CMAKE_SOURCE_DIR}/src/*.cpp)
file(GLOB_RECURSE HEADERS ${CMAKE_SOURCE_DIR}/include/*.h)

add_executable(${EXEC_TARGET} ${HEADERS} ${SOURCES})
target_include_directories(${EXEC_TARGET} PRIVATE include src)
target_link_libraries(${EXEC_TARGET} PRIVATE raylib)

# Post build: Copy Resources to bin
set(ResourcesPath ${CMAKE_CURRENT_SOURCE_DIR}/assets)
add_custom_command(TARGET ${EXEC_TARGET} POST_BUILD
  COMMAND ${CMAKE_COMMAND} -E cmake_echo_color --cyan "Copy Assets..."
  COMMAND ${CMAKE_COMMAND} -E copy_directory ${ResourcesPath} $<TARGET_FILE_DIR:${EXEC_TARGET}>/assets
)

