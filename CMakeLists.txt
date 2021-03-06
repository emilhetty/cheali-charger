cmake_minimum_required(VERSION 2.6)

SET(CMAKE_SYSTEM_NAME Generic)
SET(CMAKE_C_COMPILER avr-gcc)
SET(CMAKE_CXX_COMPILER avr-g++)

Project(cheali-charger)

set(cheali-charger-version 0.33)
set(cheali-charger-eeprom-calibration-version 8)
set(cheali-charger-eeprom-programdata-version 1)
set(cheali-charger-eeprom-settings-version 5)

configure_file(src/core/Version.h.in src/core/Version.h)


if(ARM-Cortex-M0)
    message(STATUS "target: ARM-Cortex-M0")
    include(arm-compiler.cmake)
    add_subdirectory(src/core)
    add_subdirectory(src/hardware/imaxB6-clone-ARM-Cortex-M0)
else(ARM-Cortex-M0)
    message(STATUS "target: avr")
    include(avr-compiler.cmake)
    add_subdirectory(src/core/atmega32)
    add_subdirectory(src/hardware/GTPowerA6-10-original)
    add_subdirectory(src/hardware/imaxB6-original)
    add_subdirectory(src/hardware/imaxB6-clone)
    add_subdirectory(src/hardware/Turnigy-MEGA-400Wx2)
    add_subdirectory(src/hardware/Turnigy-A-6-10-200W)
    add_subdirectory(src/hardware/Turnigy-Accucel-6-50W-5A)
    add_subdirectory(src/hardware/Turnigy-Accucel-8-150W-7A)
    add_subdirectory(src/hardware//Dual-Power-B6AC-80W-RC)
endif(ARM-Cortex-M0)




