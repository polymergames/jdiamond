#
# Copyright 2016 Ahnaf Siddiqui
#
# Licensed under the Apache License, Version 2.0 (the "License");
# you may not use this file except in compliance with the License.
# You may obtain a copy of the License at
#
# http://www.apache.org/licenses/LICENSE-2.0
#
# Unless required by applicable law or agreed to in writing, software
# distributed under the License is distributed on an "AS IS" BASIS,
# WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
# See the License for the specific language governing permissions and
# limitations under the License.
#

cmake_minimum_required(VERSION 3.2.0)
project(CDiamondTest)


# Flags
set(CMAKE_CXX_FLAGS -std=c++11)


# Header includes
include_directories(
	../include
	../extern/Diamond/include/backend
	../extern/Diamond/include
	../extern/DiamondUtils/include
	../extern/Quantum2D/include
)


# Libraries
if(APPLE)
	find_library(SDL_2 SDL2)
	find_library(SDL_2_IMAGE SDL2_image)
	find_library(SDL_2_MIXER SDL2_mixer)
	set(LINK_LIBS libDiamond.a libQuantum2D.a ${SDL_2} ${SDL_2_IMAGE} ${SDL_2_MIXER} -stdlib=libc++)
else()
	# Windows
	# TODO: linux!
	set(LINK_LIBS Diamond.lib Quantum2D.lib SDL2.lib SDL2_image.lib SDL2_mixer.lib)
endif()

link_directories(../extern/Diamond/lib ../extern/Quantum2D/lib ../extern/SDL2/lib)


# Get source files
set(SOURCES test.cpp)


# Build
add_executable(CDiamondTest ${SOURCES})
target_link_libraries(CDiamondTest ${LINK_LIBS})
install(TARGETS CDiamondTest DESTINATION bin)
