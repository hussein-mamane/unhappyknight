//
// Created by Housseini on 08/05/2024.
//

#include "Window.h"
#include "common.h"
#include "Entity.h"
#include <SDL_image.h>
#include <iostream>


void Window::CleanUp(){
    SDL_DestroyWindow(window);
}

void Window::clear(){
//    SDL_SetRenderDrawColor(renderer,255,255,255,0);//white
    SDL_SetRenderDrawColor(Renderer,0,0,0,0);//black
    SDL_RenderClear(Renderer);
}

int Window::getRefreshRate() {
    int displayIndex= SDL_GetWindowDisplayIndex(window);
    SDL_DisplayMode  displayMode;
    SDL_GetDisplayMode(displayIndex,0,&displayMode);
    return displayMode.refresh_rate;
}

void Window::display() {
    SDL_RenderPresent(Renderer);
}

void Window::renderEntity(Entity& p_ent,int scale,const char* textureName){
    SDL_Rect src,dst;


    src.x = p_ent.getCurrentframe().x;
    src.y = p_ent.getCurrentframe().y;
    src.w = p_ent.getCurrentframe().w;
    src.h = p_ent.getCurrentframe().h;

    dst.x = p_ent.getPosition().getX() * scale;
    dst.y = p_ent.getPosition().getY() * scale;
    dst.w = p_ent.getCurrentframe().w*scale;
    dst.h = p_ent.getCurrentframe().h*scale;

    SDL_RenderCopy(Renderer,p_ent.getTexture(textureName),&src,&dst);
}

void Window::loadTexture(const char *path, const char *animationName, Entity &e) {
    SDL_Texture* texture = nullptr;
    texture = IMG_LoadTexture(Renderer,path);
    if(texture==nullptr){
        LOG("texture loading : SDL_GetError");
        LOG(SDL_GetError());
    }
    e.addTexture(texture,animationName);
}

Window::Window(const char *title, int width, int height) {
    window = SDL_CreateWindow(title,SDL_WINDOWPOS_UNDEFINED,SDL_WINDOWPOS_UNDEFINED,
                              width,height,SDL_WINDOW_SHOWN);
    if (window != nullptr) {}
    else {
        LOG("Window initialisation failed");
        LOG(SDL_GetError());
    }
    Renderer = SDL_CreateRenderer(window,-1,SDL_RENDERER_ACCELERATED|SDL_RENDERER_PRESENTVSYNC);

}
