cmake_minimum_required(VERSION 3.19)
project(Simple_Callculator LANGUAGES CXX)

find_package(Qt6 6.5 REQUIRED COMPONENTS Core Widgets)

qt_standard_project_setup()

qt_add_executable(Simple_Callculator
    WIN32 MACOSX_BUNDLE

    mainwindow.cpp
    mainwindow.h
    mainwindow.ui
    Logic.cpp
    Logic.h
    main.cpp
)

target_link_libraries(Simple_Callculator
    PRIVATE
        Qt::Core
        Qt::Widgets
)

include(GNUInstallDirs)

install(TARGETS Simple_Callculator
    BUNDLE  DESTINATION .
    RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
)

qt_generate_deploy_app_script(
    TARGET Simple_Callculator
    OUTPUT_SCRIPT deploy_script
    NO_UNSUPPORTED_PLATFORM_ERROR
)
install(SCRIPT ${deploy_script})
