cmake_minimum_required(VERSION 3.30)
project(MyProject LANGUAGES CXX)


find_package(Qt6 REQUIRED COMPONENTS
        Widgets
        Quick
)
qt_standard_project_setup(REQUIRES 6.5)

set_source_files_properties(
        UntitledProject2/Constants.qml
        PROPERTIES
        QT_QML_SINGLETON_TYPE true
)


qt_add_executable(MyProject main.cpp
        Controller/controller.h
        Model/model.h
        )

qt_add_qml_module(MyProject
        URI "Example"
        VERSION 1.0
        NO_PLUGIN
        QML_FILES UntitledProject2Content/App.qml UntitledProject2/Constants.qml UntitledProject2/EventListModel.qml UntitledProject2/EventListSimulator.qml UntitledProject2Content/My_item.qml
)
qt_add_resources(MyProject "configuration"
        PREFIX "/"
        BASE "view"
        FILES
        qtquickcontrols2.conf
)


target_link_libraries(MyProject
        PRIVATE Qt6::Quick
        Qt6::Widgets
)

include(GNUInstallDirs)
install(TARGETS MyProject
        BUNDLE DESTINATION .
        LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
        RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
)
qt_generate_deploy_app_script(
        TARGET MyProject
        OUTPUT_SCRIPT deploy_script
        NO_UNSUPPORTED_PLATFORM_ERROR
)
install(SCRIPT ${deploy_script})

