#pragma once
#ifndef RENDER_WORLDRENDERER_H_
#define RENDER_WORLDRENDERER_H_

#include <unordered_map>

#define GLM_ENABLE_EXPERIMENTAL
#include <glm/gtx/quaternion.hpp>

#include <enginecore/core/EngineCoreApplication.h>

#include <enginecore/core/graphics/render/ModelRenderer.h>

#include "base/world/World.h"

class WorldRenderer 
{
public:
    WorldRenderer(const std::weak_ptr<World>& world);
    ~WorldRenderer() = default;

public:
    void render();

private:
    void prepareShaders();

private:
    std::weak_ptr<World> m_world;

    std::shared_ptr<ModelRenderer> m_model_renderer;
};

#undef GLM_ENABLE_EXPERIMENTAL

#endif // !RENDER_WORLDRENDERER_H_