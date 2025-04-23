cmake_minimum_required (VERSION 3.8)

if (POLICY CMP0141)
  cmake_policy(SET CMP0141 NEW)
  set(CMAKE_MSVC_DEBUG_INFORMATION_FORMAT "$<IF:$<AND:$<C_COMPILER_ID:MSVC>,$<CXX_COMPILER_ID:MSVC>>,$<$<CONFIG:Debug,RelWithDebInfo>:EditAndContinue>,$<$<CONFIG:Debug,RelWithDebInfo>:ProgramDatabase>>")
endif()

project ("furious-forests")

add_executable (furious-forests 
	"main.cpp" 
	"main.hpp"   
	"Paths.hpp"
	"Constants.hpp"
	"Managers/TexturesManager.hpp"
	"Menu/Menu.hpp"
	"Menu/MenuSettings.hpp"
	"Core/General.hpp"
	"Core/Settings.hpp"
	"Parcers/SettingsParcer.hpp"
	"Parcers/TexturesSizesParcer.hpp"
 )

target_link_libraries(furious-forests ${CMAKE_SOURCE_DIR}/libraries/sfml-graphics-d.lib)
target_link_libraries(furious-forests ${CMAKE_SOURCE_DIR}/libraries/sfml-audio-d.lib)
target_link_libraries(furious-forests ${CMAKE_SOURCE_DIR}/libraries/sfml-network-d.lib)
target_link_libraries(furious-forests ${CMAKE_SOURCE_DIR}/libraries/sfml-system-d.lib)
target_link_libraries(furious-forests ${CMAKE_SOURCE_DIR}/libraries/sfml-window-d.lib)

include_directories(${CMAKE_SOURCE_DIR}/include)
include_directories(${CMAKE_SOURCE_DIR}/libraries)


#if (CMAKE_VERSION VERSION_GREATER 3.12)
# set_property(TARGET furious-forests PROPERTY CXX_STANDARD 17)
#endif()

set_property(TARGET furious-forests PROPERTY CXX_STANDARD 17)
set_property(TARGET furious-forests PROPERTY CXX_STANDARD_REQUIRED ON)

