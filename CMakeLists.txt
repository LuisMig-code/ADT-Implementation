cmake_minimum_required(VERSION 3.22)
project(TAD_Implementation C)

set(CMAKE_C_STANDARD 99)

add_executable(TAD_Implementation main.c colecao.c funcoes.c jogador.c colecao.h funcoes.h jogador.h)
