//
// Created by Housseini on 08/05/2024.
//
#include <iostream>
#include <SDL.h>
#define LOG(x) std::cout << x << stderr << "\n";
inline float hireTimeInSeconds(){
    return SDL_GetTicks()*0.001f;
}