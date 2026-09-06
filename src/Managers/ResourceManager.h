/**
 * @file ResourceManager.h
 * @author 反六王联盟盟主
 * @date 2026/9/4
 * @brief load the preprocess all the resources outside
 */

#ifndef GUNWAR_RESOURCEMANAGER_H
#define GUNWAR_RESOURCEMANAGER_H
#include "raylib.h"


class ResourceManager {
public:

    static Shader loadShader(const char *vsPath, const char *fsPath) ;
};


#endif //GUNWAR_RESOURCEMANAGER_H
