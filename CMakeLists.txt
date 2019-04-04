cmake_minimum_required(VERSION 2.6)
project(AudioEngine_SamuelHBurke)

include_directories(
 src
 contrib
)

if(MSVC)
 include_directories(
	 contrib/msvc-2017-windows-x86/SDL2/include
 	 contrib/msvc-2017-windows-x86/glew/include
	 contrib/msvc-2017-windows-x86/openal-soft/include
	 contrib/msvc-2017-windows-x86/ogg/include
	 contrib/msvc-2017-windows-x86/vorbis/include
 )

 link_directories(
 	 ${CMAKE_SOURCE_DIR}/contrib/msvc-2017-windows-x86/SDL2/lib
	 ${CMAKE_SOURCE_DIR}/contrib/msvc-2017-windows-x86/glew/lib
	 ${CMAKE_SOURCE_DIR}/contrib/msvc-2017-windows-x86/openal-soft/lib
	 ${CMAKE_SOURCE_DIR}/contrib/msvc-2017-windows-x86/ogg/lib
	 ${CMAKE_SOURCE_DIR}/contrib/msvc-2017-windows-x86/vorbis/lib
 )

 else()
  include_directories(
  	  /usr/X11R6/include
	  /usr/local/include
  )

  link_directories(
  	  /usr/X11R6/lib
	  /usr/local/lib
  )
endif()

if(MSVC)
	add_definitions(-DSDL_MAIN_HANDLED)
endif()

add_library(audioengine
	src/audioengine/audioengine.h
	src/audioengine/AudioMaster.h
	src/audioengine/Source.h

	src/audioengine/AudioMaster.cpp
	src/audioengine/Source.cpp
)

add_library(foundations
	src/foundations/fundamentals.h
	src/foundations/Foundations.h
	src/foundations/Entity.h
	src/foundations/Component.h
	src/foundations/Camera.h
	src/foundations/Transform.h
	src/foundations/Window.h
	src/foundations/Environment.h
	src/foundations/Input.h

	src/foundations/Foundations.cpp
	src/foundations/Entity.cpp
	src/foundations/Component.cpp
	src/foundations/Camera.cpp
	src/foundations/Transform.cpp
	src/foundations/Window.cpp
	src/foundations/Environment.cpp
	src/foundations/Input.cpp
)

add_executable(game
	src/game/main.cpp

	src/game/Snake.h
	src/game/Player.h

	src/game/Snake.cpp
	src/game/Player.cpp
)

if(MSVC)
	target_link_libraries(audioengine
		SDL2 glew32 opengl32 OpenAL32 ogg vorbis vorbisfile
)
else()
	target_link_libraries(audioengine
		SDL2 GLU GLEW GL AL ogg vorbis vorbisfile
)
endif()


target_link_libraries(game foundations audioengine)

if(MSVC)
	add_custom_command(TARGET game POST_BUILD
		COMMAND ${CMAKE_COMMAND} -E copy_if_different
			"${CMAKE_SOURCE_DIR}/contrib/msvc-2017-windows-x86/SDL2/bin/SDL2.dll"
			"$<TARGET_FILE_DIR:game>"
	)

	add_custom_command(TARGET game POST_BUILD
		COMMAND ${CMAKE_COMMAND} -E copy_if_different
			"${CMAKE_SOURCE_DIR}/contrib/msvc-2017-windows-x86/glew/bin/glew32.dll"
			"$<TARGET_FILE_DIR:game>"
	)

	add_custom_command(TARGET game POST_BUILD
		COMMAND ${CMAKE_COMMAND} -E copy_if_different
			"${CMAKE_SOURCE_DIR}/contrib/msvc-2017-windows-x86/openal-soft/bin/OpenAL32.dll"
			"$<TARGET_FILE_DIR:game>"
	)
endif()