
add_executable(exe main.cpp Helper.cpp Helper.swift)
target_link_libraries(exe PUBLIC shlib)
target_include_directories(exe PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})

target_compile_options(exe PUBLIC "SHELL:$<$<COMPILE_LANGUAGE:Swift>:-Xcc -std=c++23 -cxx-interoperability-mode=default>")
target_compile_features(exe PUBLIC cxx_std_23)
set_target_properties(exe PROPERTIES Swift_MODULE_NAME "ExeShlib")

_swift_generate_cxx_header(shlib "exe-Swift.h"
    SEARCH_PATHS ${CMAKE_CURRENT_SOURCE_DIR}
)

