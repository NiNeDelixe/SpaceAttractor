#include "FloatingOriginSystem.h"

void FloatingOriginSystem::update(EntityRegistry<DefaultEntityIndentifier> &registry)
{
    auto camera_view = registry.view<Camera, WorldSpaceCache, FloatingOrigin>();

    auto camera = camera_view.front();
    
    if (!camera_view.contains(camera))
    {
        return;
    }
    

    auto& camera_cache = camera_view.get<WorldSpaceCache>(camera);
    auto& origin = camera_view.get<FloatingOrigin>(camera);

    origin.origin = camera_cache.world_position;

    auto view = registry.view<WorldSpaceCache, RenderTransform>();

    for (auto&& [e, world, render] : view.each())
    {
        glm::dvec3 relative = world.world_position - origin.origin;

        render.relative_position = glm::vec3(relative);
    }
}