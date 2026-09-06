#include "ResourceManager.h"

Shader ResourceManager::loadShader(const char *vsPath, const char *fsPath) {
    return LoadShader(vsPath, fsPath);
}
