ADD_SUBDIRECTORY(gtkbuilder)
ADD_SUBDIRECTORY(ui)

SET(customer_import_SOURCES
  gnc-plugin-customer_import.c
  libgncmod-customer_import.c
  dialog-customer-import-gui.c
  dialog-customer-import.c
)

# Add dependency on config.h
SET_SOURCE_FILES_PROPERTIES (${customer_import_SOURCES} PROPERTIES OBJECT_DEPENDS ${CONFIG_H})


SET(customer_import_noinst_HEADERS
  gnc-plugin-customer_import.h
  dialog-customer-import-gui.h
  dialog-customer-import.h
)

ADD_LIBRARY(gncmod-customer_import ${customer_import_SOURCES} ${customer_input_noinst_HEADERS})

TARGET_LINK_LIBRARIES(gncmod-customer_import gncmod-business-gnome gncmod-gnome-utils gncmod-app-utils
     gncmod-engine gnc-core-utils gnc-module gnc-qof ${GLIB2_LDFLAGS})

TARGET_COMPILE_DEFINITIONS(gncmod-customer_import PRIVATE -DG_LOG_DOMAIN=\"gnc.plugin.customer_import\")

INSTALL(TARGETS gncmod-customer_import
  LIBRARY DESTINATION lib/systecash
  ARCHIVE DESTINATION lib/systecash
  RUNTIME DESTINATION bin)
# No headers to install.
