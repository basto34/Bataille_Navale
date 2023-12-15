# Nous voulons un cmake "récent" pour utiliser les dernières fonctionnalités
cmake_minimum_required(VERSION 3.0)

# Notre projet est étiqueté toto
project(Bataille_Navale)

# On indique que l'on veut un exécutable "toto" compilé à partir des fichiers
add_executable(Bataille_Navale src/main.cpp src/Board.cpp src/IA.cpp src/Bateau.cpp src/Utilisateur.cpp)

# Dossier de .h include
include_directories (include) 
