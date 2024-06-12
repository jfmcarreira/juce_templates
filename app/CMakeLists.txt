set (TargetName "DummyApp")

juce_add_gui_app(${TargetName} PRODUCT_NAME "${TargetName}")
juce_generate_juce_header(${TargetName})

set(SourceFiles
        Main.cpp
        MainWindow.cpp
        MainWindow.h
        HelloWorldLabel.h
        MainComponent.h
        MainComponent.cpp
)

target_sources(${TargetName} PRIVATE ${SourceFiles})

source_group(TREE ${CMAKE_CURRENT_LIST_DIR} PREFIX "SOURCE FILES" FILES ${source_files})

target_compile_definitions(${TargetName} PRIVATE
        JUCE_WEB_BROWSER=0
        JUCE_USE_CURL=0
        JUCE_APPLICATION_NAME_STRING="$<TARGET_PROPERTY:${TargetName},JUCE_PROJECT_NAME>"
        JUCE_APPLICATION_VERSION_STRING="$<TARGET_PROPERTY:${TargetName},JUCE_VERSION>")

target_link_libraries(${TargetName} PRIVATE
        juce::juce_recommended_config_flags
        juce::juce_recommended_lto_flags
        juce::juce_recommended_warning_flags
        juce::juce_gui_extra)