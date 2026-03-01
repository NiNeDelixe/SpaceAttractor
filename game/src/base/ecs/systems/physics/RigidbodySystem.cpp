#include "RigidbodySystem.h"

void RigidbodySystem::update(EntityRegistry<DefaultEntityIndentifier> &registry)
{
    auto rigid_view = registry.view<RigidBodyComponent, RenderTransform, WorldSpaceCache, SpaceTransform>();

    for (auto&& [entity_r, rigidbody_c, render_trans_c, world_cache_c, space_trans_c] : rigid_view.each())
    {
        //world_cache_c.world_position = rigidbody_c.rigidbody.getHitbox().getPosition();
        world_cache_c.world_position += rigidbody_c.rigidbody.getHitbox().getVelocity();
        //space_trans_c.local_position = rigidbody_c.rigidbody.getHitbox().getPosition();
        //space_trans_c.local_position += rigidbody_c.rigidbody.getHitbox().getVelocity();
        
        //render_trans_c.relative_position = rigidbody_c.rigidbody.getHitbox().getPosition();
        //render_trans_c.relative_position += rigidbody_c.rigidbody.getHitbox().getVelocity();
    }
}