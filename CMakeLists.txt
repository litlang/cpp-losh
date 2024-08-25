cmake_minimum_required(VERSION 3.15)
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

project(losh)
set(SOURCE_DIR src)

# add_compile_options(-Xlinker --unresolved-symbols=ignore-in-shared-libs)

file(GLOB_RECURSE SOURCES ${SOURCE_DIR}/implement/*.cpp)

# find_library(CODEC_LIB NAMES codec PATHS deps/codec/lib NO_DEFAULT_PATH REQUIRED)

add_library(${PROJECT_NAME}_STATIC STATIC ${SOURCES})
add_library(${PROJECT_NAME}_SHARED SHARED ${SOURCES})
set_target_properties(${PROJECT_NAME}_STATIC PROPERTIES OUTPUT_NAME ${PROJECT_NAME})
set_target_properties(${PROJECT_NAME}_SHARED PROPERTIES OUTPUT_NAME ${PROJECT_NAME})

target_include_directories(${PROJECT_NAME}_STATIC PUBLIC ${SOURCE_DIR}/interface)
target_include_directories(${PROJECT_NAME}_STATIC PRIVATE deps/codec/include)
target_include_directories(${PROJECT_NAME}_SHARED PUBLIC ${SOURCE_DIR}/interface)
target_include_directories(${PROJECT_NAME}_SHARED PRIVATE deps/codec/include)
# target_link_libraries(${PROJECT_NAME}_STATIC PRIVATE CODEC_LIB)
# target_link_libraries(${PROJECT_NAME}_STATIC PRIVATE CODEC_LIB)

install(TARGETS ${PROJECT_NAME}_STATIC #[[${PROJECT_NAME}_SHARED]]
	LIBRARY DESTINATION lib
	ARCHIVE DESTINATION lib
)
install(DIRECTORY ${SOURCE_DIR}/interface/ DESTINATION include)