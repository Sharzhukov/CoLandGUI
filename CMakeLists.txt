cmake_minimum_required(VERSION 3.15)
project(CoLand VERSION 1.0.0 LANGUAGES CXX)

# Требования к компилятору
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Найти все .cpp файлы в src/
file(GLOB_RECURSE SOURCES "src/*.cpp")

# Создать исполняемый файл
add_executable(${PROJECT_NAME} ${SOURCES} ${HEADERS})

# Подключить заголовки
target_include_directories(${PROJECT_NAME} PRIVATE include)

# Настройки для macOS (чтобы не было ошибок подписи)
if(APPLE)
    set_target_properties(${PROJECT_NAME} PROPERTIES
        XCODE_ATTRIBUTE_CODE_SIGN_IDENTITY ""
        XCODE_ATTRIBUTE_CODE_SIGNING_ALLOWED "NO"
    )
endif()

# Информация о проекте
message(STATUS "=====================================")
message(STATUS "Project: ${PROJECT_NAME}")
message(STATUS "Version: ${PROJECT_VERSION}")
message(STATUS "C++ Standard: ${CMAKE_CXX_STANDARD}")
message(STATUS "=====================================")