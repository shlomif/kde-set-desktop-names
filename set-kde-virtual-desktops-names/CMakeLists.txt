project(set_kde4_virtual_desktop_names)

find_package(KDE4 REQUIRED)

include_directories( ${KDE4_INCLUDES} )

set(mySources set_names.cpp)

kde4_add_executable(set_kde4_virtual_desktop_names ${mySources})

target_link_libraries(set_kde4_virtual_desktop_names ${KDE4_KDEUI_LIBS} ${KDE4_KPARTS_LIBS} )

install(TARGETS set_kde4_virtual_desktop_names DESTINATION bin)
