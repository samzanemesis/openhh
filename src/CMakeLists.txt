file(GLOB_RECURSE PROJECT_SOURCE *.cpp)
file(GLOB_RECURSE PROJECT_MODULES *.ixx)
file(GLOB_RECURSE PROJECT_HEADER *.h)

set( PROJECT_NAME openhh )

add_executable( ${PROJECT_NAME} ${PROJECT_SOURCE} ${PROJECT_MODULES} ${PROJECT_HEADER} )

source_group(TREE ${CMAKE_CURRENT_SOURCE_DIR} FILES ${PROJECT_SOURCE} ${PROJECT_MODULES} ${PROJECT_HEADER})

target_compile_features(${PROJECT_NAME} PRIVATE cxx_std_20)

# Add Libraries to project
target_link_libraries( ${PROJECT_NAME} PRIVATE SDL2::SDL2 SDL2::SDL2main )
target_link_libraries( ${PROJECT_NAME} PRIVATE sdlxx_core )
target_link_libraries( ${PROJECT_NAME} PRIVATE astc-codec astc bgfx bimg bx edtaa3 etc1 etc2 iqa nvtt pvrtc squish tinyexr )
target_link_libraries( ${PROJECT_NAME} PRIVATE HedgeLib )