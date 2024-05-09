//
// Created by Housseini on 08/05/2024.
//
#include <vector>
#include <map>
#include <iostream>
#include <SDL.h>
#include "vec2.h"
#include "Animation.h"
#ifndef UNHAPPYKNIGHT_ENTITY_H
#define UNHAPPYKNIGHT_ENTITY_H


class Entity {
private:
    std::string currentState;
public:
    const vec2 &getPosition() const;
    vec2 position;

    void setPosition(const vec2 &pos);

    const std::string &getCurrentState() const;

    void setCurrentState(const std::string &currentState);

    int getCurrentframeIndex() const;

    void setCurrentframeIndex(int currentframeIndex);
    std::map<std::string,Animation> animations;

private:
    int currentframeIndex;
public:
    SDL_Rect getCurrentframe();
    SDL_Texture* getTexture(const std::string& textureName);
    void addTexture(SDL_Texture* texture,const char* animationName);
    explicit Entity(vec2 position);

};


#endif //UNHAPPYKNIGHT_ENTITY_H
