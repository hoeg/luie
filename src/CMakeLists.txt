#list of source files
set(LUIE_SRC_FILES luie/main.c)
 
add_executable(luie ${LUIE_SRC_FILES})

include_directories(
  ${PROJECT_SOURCE_DIR}/include
  ${PROJECT_SOURCE_DIR}/deps/lua
)

target_link_libraries(luie ${PROJECT_SOURCE_DIR}/deps/lua/liblua.a)
target_link_libraries(luie ${CMAKE_DL_LIBS})
target_link_libraries(luie m)

install(DIRECTORY ${PROJECT_SOURCE_DIR}/include
  DESTINATION .
  COMPONENT headers
)
