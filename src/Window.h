//
// Created by Housseini on 08/05/2024.
//
#ifndef UNHAPPYKNIGHT_WINDOW_H
#define UNHAPPYKNIGHT_WINDOW_H
#include <SDL.h>
#include <vector>
#include "Entity.h"

class Window {
    SDL_Window* window;
    SDL_Renderer* Renderer;
public:
    void CleanUp();
    void clear();
    void display();
    void renderEntity(Entity& p_ent,int scale,const char* textureName);
    void loadTexture(const char* path,const char* animationName, Entity& e);
    int getRefreshRate();
    Window(const char* title,int width,int height);
};


#endif //UNHAPPYKNIGHT_WINDOW_H
