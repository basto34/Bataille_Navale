cmake_minimum_required(VERSION 3.10)

project(TP1)

# Définir le répertoire des sources
set(SOURCES_DIR src)

# Utiliser file(GLOB ...) pour récupérer tous les fichiers sources
file(GLOB SOURCES ${SOURCES_DIR}/*.cpp)

# Ajouter l'exécutable en utilisant tous les fichiers sources
add_executable(battle_ship ${SOURCES})

# Inclure les répertoires d'en-têtes
include_directories(include)

# Définir le standard C++ à 17
set(CMAKE_CXX_STANDARD 17)