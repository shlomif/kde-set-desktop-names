project(ksimple)

find_package(KDE4 REQUIRED)

include_directories( ${KDE4_INCLUDES} )

set(mySources set_names.cpp)

kde4_add_executable(ksimple ${mySources})

target_link_libraries(ksimple ${KDE4_KDEUI_LIBS} ${KDE4_KPARTS_LIBS} )

install(TARGETS ksimple DESTINATION bin)
install(FILES kfoo.desktop DESTINATION "foo")
