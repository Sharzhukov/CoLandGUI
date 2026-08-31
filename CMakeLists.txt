cmake_minimum_required(VERSION 3.15)
project(CoLand VERSION 1.0.0 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

option(ENABLE_GUI "Build with Raylib GUI" OFF)

# ============================================
# ЯВНО перечисляем все файлы проекта
# ============================================
set(BASE_SOURCES
    src/main.cpp
    src/core/Colony.cpp
    src/core/Colonist.cpp
    src/core/Wedding.cpp
    src/core/Event.cpp
    src/core/Enum.cpp
    src/core/DayReport.cpp
    src/common/common.cpp
    src/common/FileManager.cpp
    src/common/Logger.cpp
    src/gui/lib/initWindowApp.cpp
)

# ============================================
# Добавляем правильную реализацию
# ============================================
if(ENABLE_GUI)
    list(APPEND BASE_SOURCES src/gui/GuiApp.cpp)
    message(STATUS "🔵 Building with GUI support (Raylib)")
    
    include(FetchContent)
    FetchContent_Declare(
        raylib
        GIT_REPOSITORY "https://github.com/raysan5/raylib.git"
        GIT_TAG "5.5"
        GIT_SHALLOW TRUE
    )
    FetchContent_MakeAvailable(raylib)
    
else()
    list(APPEND BASE_SOURCES src/tui/ConsoleUI.cpp)
    message(STATUS "🟢 Building with TUI support (Console)")
endif()

# ============================================
# Создаём исполняемый файл
# ============================================
add_executable(${PROJECT_NAME} ${BASE_SOURCES})
target_include_directories(${PROJECT_NAME} PRIVATE include)

# Подключаем Raylib, если нужно
if(ENABLE_GUI)
    target_link_libraries(${PROJECT_NAME} PRIVATE raylib)
endif()

# ============================================
# ИКОНКИ
# ============================================
if(WIN32)
    # Windows: .ico файл
    set(ICON_FILE "${CMAKE_SOURCE_DIR}/resources/assets/appIcon.ico")
    if(EXISTS ${ICON_FILE})
        # Создаём .rc файл (ресурсы)
        configure_file(
            "${CMAKE_SOURCE_DIR}/resources/assets/appIcon.rc.in"
            "${CMAKE_CURRENT_BINARY_DIR}/appIcon.rc"
            @ONLY
        )
        target_sources(${PROJECT_NAME} PRIVATE "${CMAKE_CURRENT_BINARY_DIR}/appIcon.rc")
        message(STATUS "✅ Windows icon added")
    else()
        message(WARNING "⚠️ Windows icon not found: ${ICON_FILE}")
    endif()

elseif(APPLE)
    # macOS: .icns файл
    set(ICON_FILE "${CMAKE_SOURCE_DIR}/resources/assets/appIcon.icns")
    if(EXISTS ${ICON_FILE})
        set_source_files_properties(${ICON_FILE} PROPERTIES
            MACOSX_PACKAGE_LOCATION Resources
        )
        target_sources(${PROJECT_NAME} PRIVATE ${ICON_FILE})
        set_target_properties(${PROJECT_NAME} PROPERTIES
            MACOSX_BUNDLE_ICON_FILE appIcon
        )
        message(STATUS "✅ macOS icon added")
    else()
        message(WARNING "⚠️ macOS icon not found: ${ICON_FILE}")
    endif()
endif()

# ============================================
# macOS настройки
# ============================================
if(APPLE)
    set_target_properties(${PROJECT_NAME} PROPERTIES
        XCODE_ATTRIBUTE_CODE_SIGN_IDENTITY ""
        XCODE_ATTRIBUTE_CODE_SIGNING_ALLOWED "NO"
    )
    
    if(ENABLE_GUI)
        target_link_libraries(${PROJECT_NAME} PRIVATE
            "-framework CoreVideo"
            "-framework IOKit"
            "-framework Cocoa"
            "-framework GLUT"
            "-framework OpenGL"
        )
    endif()
endif()

# ============================================
# Добавление resources в исполняемый
# ============================================
add_custom_command(TARGET ${PROJECT_NAME} POST_BUILD
    COMMAND ${CMAKE_COMMAND} -E copy_directory
    "${CMAKE_CURRENT_SOURCE_DIR}/resources"
    "$<TARGET_FILE_DIR:${PROJECT_NAME}>/resources"
)

# ============================================
# Информация о сборке
# ============================================
message(STATUS "")
message(STATUS "=====================================")
message(STATUS "Project: ${PROJECT_NAME}")
message(STATUS "Version: ${PROJECT_VERSION}")
message(STATUS "Build Type: ${CMAKE_BUILD_TYPE}")
message(STATUS "C++ Standard: ${CMAKE_CXX_STANDARD}")
message(STATUS "GUI Support: ${ENABLE_GUI}")
message(STATUS "=====================================")
message(STATUS "")