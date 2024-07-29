cmake_minimum_required(VERSION 3.15)
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

project(losh)

# add_compile_options(-Xlinker --unresolved-symbols=ignore-in-shared-libs)

file(GLOB_RECURSE SOURCES src/*.cpp)

# find_library(CODEC_LIB NAMES codec PATHS deps/codec/lib NO_DEFAULT_PATH REQUIRED)

# static lib
add_library(${PROJECT_NAME}_STATIC STATIC ${SOURCES})
set_target_properties(${PROJECT_NAME}_STATIC PROPERTIES
	OUTPUT_NAME ${PROJECT_NAME}
)
target_include_directories(${PROJECT_NAME}_STATIC PUBLIC src/interface)
target_include_directories(${PROJECT_NAME}_STATIC PRIVATE deps/codec/include)
# target_link_libraries(${PROJECT_NAME}_STATIC PRIVATE CODEC_LIB)

# shared lib
#[[add_library(${PROJECT_NAME}_SHARED SHARED ${SOURCES})
set_target_properties(${PROJECT_NAME}_SHARED PROPERTIES
	OUTPUT_NAME ${PROJECT_NAME}
)
target_include_directories(${PROJECT_NAME}_SHARED PUBLIC src/interface)
target_include_directories(${PROJECT_NAME}_SHARED PRIVATE deps/codec/include)]]
# target_link_libraries(${PROJECT_NAME}_STATIC PRIVATE CODEC_LIB)

install(TARGETS ${PROJECT_NAME}_STATIC #[[${PROJECT_NAME}_SHARED]]
	LIBRARY DESTINATION lib
	ARCHIVE DESTINATION lib
)
install(DIRECTORY src/interface/ DESTINATION include)