#include <iostream>
#include <SDL.h>
#include <SDL_image.h>
#include "common.h"
#include "Window.h"

int main(int argc, char* argv[]) {
    if (SDL_Init(SDL_INIT_VIDEO | SDL_INIT_TIMER) > 0) {
        LOG("SDL_Init has failed");
        LOG(SDL_GetError());
    }
    if (!(IMG_Init(IMG_INIT_PNG))) {
        LOG("IMG_Init has failed");
        LOG(SDL_GetError());
    }


    Window window("Game v1.0",640,480);
    Entity entity = Entity(vec2(10, 10));
    window.loadTexture("..\\gfx\\Run.png","run",entity);
    entity.animations[entity.getCurrentState()].makeFrameArray(0,4,0,2,128,64);

    
    bool gameRunning = true;
    SDL_Event event;
    const float timeStep = 0.01f;
    float currentTime = hireTimeInSeconds();
    float accumulator = 0.0f;
    int i = 0;
    bool entityMove = false;
    float frameTimeAnimate = 0.0f;
    while(gameRunning)
    {
        float newTime = hireTimeInSeconds();
        uint32_t startTicks = SDL_GetTicks();
        float frameTime = newTime - currentTime;
        frameTimeAnimate+=frameTime;
        currentTime = newTime;
        accumulator+=frameTime;

        //should reason on the timeStep instead of this
        if(entityMove){
            if(frameTimeAnimate > (float(window.getRefreshRate())*0.001)/8*10){
                entity.setCurrentframeIndex(i);
                i == 7 ? i = 0: ++i;
                frameTimeAnimate = 0;
            }
        }


        while (accumulator>=timeStep)
        {
            while(SDL_PollEvent(&event)){
                if(event.type == SDL_QUIT)
                    gameRunning = false;
                // Handle Events, Call game loop callables
                if(event.type == SDL_KEYDOWN){
                    entityMove = true;
                    entity.setPosition(vec2(entity.getPosition().getX()+2,entity.getPosition().getY()));
                }
                if(event.type == SDL_KEYUP){
                    entityMove = false;
                }
            }
            accumulator-=timeStep  ;//fps varies according to speed of processing
        }

        //linear interpolation for physics state
        //const float alpha = accumulator/timeStep;// percentage of the timeStep that got realised, to guess physics movement between 2 updates

        window.clear();
        // Entity or Entity& or auto
//        for(const Entity& entity: entitiesVector){
//        }

        window.renderEntity(entity,2,"run");
        window.display();

        uint32_t endTicks = SDL_GetTicks()-startTicks;
        if(endTicks<1000/window.getRefreshRate()){//faster than refresh rate
            SDL_Delay(1000/window.getRefreshRate()-endTicks);//wait
        }
    }
    window.CleanUp();
    SDL_Quit();
    return 0;
}