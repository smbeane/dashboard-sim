add_library (
    fonts INTERFACE
)

target_include_directories ( fonts INTERFACE "${CMAKE_CURRENT_SOURCE_DIR}/headers")
target_compile_definitions ( fonts INTERFACE FONTS_VERSION=1.0)