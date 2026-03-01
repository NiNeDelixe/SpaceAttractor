#pragma once
#ifndef RENDER_WORLDRENDERER_H_
#define RENDER_WORLDRENDERER_H_

#include <unordered_map>

#define GLM_ENABLE_EXPERIMENTAL
#include <glm/gtx/quaternion.hpp>

#include <enginecore/core/EngineCoreApplication.h>

#include <enginecore/core/graphics/render/ModelRenderer.h>

#include <enginecore/core/ecs/components/PlayerComponent.h>
#include <enginecore/core/ecs/components/physics/GravityComponent.h>
#include <enginecore/core/ecs/components/physics/RigidBodyComponent.h>

#include "base/ecs/components/FloatingOrigin.h"
#include "base/ecs/components/RenderTransform.h"
#include "base/ecs/components/SpaceTransform.h"
#include "base/ecs/components/WorldSpaceCache.h"

#include "base/world/Level.h"

class WorldRenderer 
{
public:
    WorldRenderer(const std::weak_ptr<Level>& world);
    ~WorldRenderer() = default;

public:
    void render();

private:
    void prepareShaders();

private:
    std::weak_ptr<Level> m_world;

    std::shared_ptr<ModelRenderer> m_model_renderer;
};

#undef GLM_ENABLE_EXPERIMENTAL

#endif // !RENDER_WORLDRENDERER_H_