ADD_SUBDIRECTORY(test)

SET (register_gnome_SOURCES
  gncmod-register-gnome.c
  combocell-gnome.c
  datecell-gnome.c
  formulacell-gnome.c
  systecash-color.c
  systecash-cursor.c
  systecash-date-picker.c
  systecash-grid.c
  systecash-header.c
  systecash-item-edit.c
  systecash-item-list.c
  systecash-scrolled-window.c
  systecash-sheet.c
  systecash-style.c
  pricecell-gnome.c
  quickfillcell-gnome.c
  table-gnome.c
)

SET (register_gnome_noinst_HEADERS
  formulacell-gnome.h
  systecash-color.h
  systecash-cursor.h
  systecash-date-picker.h
  systecash-grid.h
  systecash-header.h
  systecash-item-edit.h
  systecash-item-list.h
  systecash-scrolled-window.h
  systecash-sheet.h
  systecash-sheetP.h
  systecash-style.h
  pricecell-gnome.h
  quickfillcell-gnome.h
  table-gnome.h
)

# Add dependency on config.h
SET_SOURCE_FILES_PROPERTIES (${register_gnome_SOURCES} PROPERTIES OBJECT_DEPENDS ${CONFIG_H})

ADD_LIBRARY (gncmod-register-gnome ${register_gnome_SOURCES} ${register_gnome_noinst_HEADERS})

TARGET_LINK_LIBRARIES(gncmod-register-gnome gncmod-register-core gnc-qof ${GNOMECANVAS_LDFLAGS} ${GTK2_LDFLAGS})

TARGET_COMPILE_DEFINITIONS(gncmod-register-gnome PRIVATE -DG_LOG_DOMAIN=\"gnc.register.gnome\")

TARGET_INCLUDE_DIRECTORIES(gncmod-register-gnome
    PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}
    PRIVATE ${CMAKE_SOURCE_DIR}/src/register/ledger-core ${GNOMECANVAS_INCLUDE_DIRS}
)

INSTALL(TARGETS gncmod-register-gnome
  LIBRARY DESTINATION lib/systecash
  ARCHIVE DESTINATION lib/systecash
  RUNTIME DESTINATION bin)
# No headers to install
