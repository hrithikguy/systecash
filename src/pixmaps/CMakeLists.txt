
INSTALL(DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR} DESTINATION share/systecash
        PATTERN Makefile.* EXCLUDE
        PATTERN CMakeLists.txt EXCLUDE
)

IF (GNC_BUILD_AS_INSTALL)
  FILE(COPY .
     DESTINATION ${DATADIR_BUILD}/systecash/pixmaps
     PATTERN Makefile.* EXCLUDE
     PATTERN CMakeLists.txt EXCLUDE
  )
ENDIF()

FOREACH(dir 256x256 128x128 96x96 64x64 48x48)
  INSTALL(
      FILES ${CMAKE_CURRENT_SOURCE_DIR}/systecash-icon-${dir}.png
      RENAME systecash-icon.png
      DESTINATION share/icons/hicolor/${dir}/apps)
  IF(GNC_BUILD_AS_INSTALL)    
    FILE(COPY ${CMAKE_CURRENT_SOURCE_DIR}/systecash-icon-${dir}.png
         DESTINATION ${DATADIR_BUILD}/icons/hicolor/${dir}/apps/systecash-icon-${dir}.png)
  ENDIF()
ENDFOREACH(dir)

INSTALL(
    FILES ${CMAKE_SOURCE_DIR}/art/tango/32x32/systecash.png
    RENAME systecash-icon.png
    DESTINATION share/icons/hicolor/32x32/apps
)

INSTALL(
    FILES ${CMAKE_SOURCE_DIR}/art/tango/22x22/systecash-22x22.png
    RENAME systecash-icon.png
    DESTINATION share/icons/hicolor/22x22/apps
)
INSTALL(
    FILES ${CMAKE_SOURCE_DIR}/art/tango/22x22/systecash-24x24.png
    RENAME systecash-icon.png
    DESTINATION share/icons/hicolor/24x24/apps
)
INSTALL(
    FILES ${CMAKE_SOURCE_DIR}/art/tango/16x16/systecash.png
    RENAME systecash-icon.png
    DESTINATION share/icons/hicolor/16x16/apps
)
INSTALL(
    FILES ${CMAKE_SOURCE_DIR}/art/tango/scalable/systecash.svg
    RENAME systecash-icon.svg
    DESTINATION share/icons/hicolor/scalable/apps
)
INSTALL(
    FILES ${CMAKE_SOURCE_DIR}/art/tango/16x16/systecash.png
    RENAME systecash-icon-16x16.png
    DESTINATION share/systecash/pixmaps
)
INSTALL(
    FILES ${CMAKE_SOURCE_DIR}/art/tango/32x32/systecash.png
    RENAME systecash-icon-32x32.png
    DESTINATION share/systecash/pixmaps
)

IF (GNC_BUILD_AS_INSTALL)
  FILE(
    COPY ${CMAKE_SOURCE_DIR}/art/tango/32x32/systecash.png
    DESTINATION ${DATADIR_BUILD}/icons/hicolor/32x32/apps
  )
  FILE(RENAME ${DATADIR_BUILD}/icons/hicolor/32x32/apps/systecash.png
    ${DATADIR_BUILD}/icons/hicolor/32x32/apps/systecash-icon.png
    )

  FILE(
    COPY ${CMAKE_SOURCE_DIR}/art/tango/22x22/systecash-22x22.png
    DESTINATION ${DATADIR_BUILD}/icons/hicolor/22x22/apps
  )
  FILE(RENAME ${DATADIR_BUILD}/icons/hicolor/22x22/apps/systecash-22x22.png
    ${DATADIR_BUILD}/icons/hicolor/22x22/apps/systecash-icon.png
    )
  FILE(
    COPY ${CMAKE_SOURCE_DIR}/art/tango/22x22/systecash-24x24.png
    DESTINATION ${DATADIR_BUILD}/icons/hicolor/24x24/apps
  )
  FILE(RENAME ${DATADIR_BUILD}/icons/hicolor/24x24/apps/systecash-24x24.png
    ${DATADIR_BUILD}/icons/hicolor/24x24/apps/systecash-icon.png
  )

  FILE(
    COPY ${CMAKE_SOURCE_DIR}/art/tango/16x16/systecash.png
    DESTINATION ${DATADIR_BUILD}/icons/hicolor/16x16/apps
  )
  FILE(RENAME ${DATADIR_BUILD}/icons/hicolor/16x16/apps/systecash.png
    ${DATADIR_BUILD}/icons/hicolor/16x16/apps/systecash-icon.png
  )

  FILE(
    COPY ${CMAKE_SOURCE_DIR}/art/tango/scalable/systecash.svg
    DESTINATION ${DATADIR_BUILD}/icons/hicolor/scalable/apps
  )
  FILE(RENAME ${DATADIR_BUILD}/icons/hicolor/scalable/apps/systecash.svg
    ${DATADIR_BUILD}/icons/hicolor/scalable/apps/systecash-icon.svg
  )

  FILE(
    COPY ${CMAKE_SOURCE_DIR}/art/tango/16x16/systecash.png
    DESTINATION ${DATADIR_BUILD}/systecash/pixmaps
  )
  FILE(RENAME ${DATADIR_BUILD}/systecash/pixmaps/systecash.png
              ${DATADIR_BUILD}/systecash/pixmaps/systecash-icon-16x16.png
  )

  FILE(
    COPY ${CMAKE_SOURCE_DIR}/art/tango/32x32/systecash.png
    DESTINATION ${DATADIR_BUILD}/systecash/pixmaps
  )
  FILE(RENAME ${DATADIR_BUILD}/systecash/pixmaps/systecash.png
    ${DATADIR_BUILD}/systecash/pixmaps/systecash-icon-32x32.png
  )

ENDIF()
