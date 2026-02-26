cmake_minimum_required(VERSION 3.5)
project(mini-shell)


add_executable(mini-shell
  src/main.c
)

target_include_directories(mini-shell PRIVATE
  src/
)
