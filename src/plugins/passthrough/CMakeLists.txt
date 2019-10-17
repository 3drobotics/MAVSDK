add_library(mavsdk_passthrough
    passthrough.cpp
    passthrough_impl.cpp
)

target_link_libraries(mavsdk_passthrough
    mavsdk
)

set_target_properties(mavsdk_passthrough
    PROPERTIES COMPILE_FLAGS ${warnings}
)

target_include_directories(mavsdk_passthrough PUBLIC
    $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include>
    $<INSTALL_INTERFACE:include/mavsdk>
    )

install(TARGETS mavsdk_passthrough
    EXPORT mavsdk-targets
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
    ARCHIVE DESTINATION ${CMAKE_INSTALL_LIBDIR}
    )

install(FILES
    include/plugins/passthrough/passthrough.h
    DESTINATION ${CMAKE_INSTALL_INCLUDEDIR}/mavsdk/plugins/passthrough
)
