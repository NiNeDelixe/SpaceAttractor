#include "PhysicsSystem.h"

inline const float E = 0.03f;
inline const float MAX_FIX = 0.1f;

void PhysicsSystem::update(EntityRegistry<DefaultEntityIndentifier> &registry)
{
    auto phys_view = registry.view<RigidBodyComponent, GravityComponent>();

    size_t substeps = 1;
    
    for (auto&& [entity_r, rigidbody_c, gravity_c] : phys_view.each())
    {
        auto delta = Time::deltaTime();

        auto hitbox = rigidbody_c.rigidbody.getHitbox();

        float dt = delta / static_cast<float>(substeps);
        float linearDamping = hitbox.getLinearDamping() * hitbox.getFriction();
        float s = 2.0f / 1;//BLOCK_AABB_GRID;

        auto half = hitbox.getHalfSize();
        glm::vec3 pos = hitbox.getPosition();
        glm::vec3 vel = hitbox.getVelocity();
        float gravityScale = hitbox.getGravityScale();
        
        bool prevGrounded = hitbox.getGrounded();
        hitbox.setGrounded(false);
        for (uint_t i = 0; i < substeps; i++) 
        {
            float px = pos.x;
            float py = pos.y;
            float pz = pos.z;

            auto gravity = gravity_c.force;
            
            vel += gravity * dt * gravityScale;
            if (hitbox.getType() == BodyType::DYNAMIC) 
            {
                // colisionCalc(chunks, hitbox, vel, pos, half, 
                //             (prevGrounded && gravityScale > 0.0f) ? 0.5f : 0.0f);
            }

            pos += vel * dt + gravity * gravityScale * dt * dt * 0.5f;
            if (hitbox.getGrounded() && pos.y < py) 
            {
                pos.y = py;
            }

            if (hitbox.getCrouching() && hitbox.getGrounded())
            {
                float y = (pos.y - half.y - E);
                hitbox.setGrounded(false);
                for (int ix = 0; ix <= (half.x - E) * 2/s; ix++) 
                {
                    float x = (px - half.x + E) + ix * s;
                    for (int iz = 0; iz <= (half.z - E) * 2/s; iz++)
                    {
                        float z = (pos.z - half.z + E) + iz * s;
                        // if (chunks.isObstacleAt(x, y, z))
                        // {
                        //     hitbox.setGrounded(true);
                        //     break;
                        // }
                    }
                }
                if (!hitbox.getGrounded()) 
                {
                    pos.z = pz;
                }
                hitbox.setGrounded(false);
                for (int ix = 0; ix <= (half.x - E) * 2/s; ix++) 
                {
                    float x = (pos.x - half.x + E) + ix * s;
                    for (int iz = 0; iz <= (half.z - E) * 2/s; iz++)
                    {
                        float z = (pz - half.z + E) + iz * s;
                        // if (chunks.isObstacleAt(x, y, z))
                        // {
                        //     hitbox.setGrounded(true);
                        //     break;
                        // }
                    }
                }
                if (!hitbox.getGrounded()) 
                {
                    pos.x = px;
                }
                hitbox.setGrounded(true);
            }
        }
        vel.x /= 1.0f + delta * linearDamping;
        vel.z /= 1.0f + delta * linearDamping;
        if (hitbox.getVerticalDamping() > 0.0f) 
        {
            vel.y /= 1.0f + delta * linearDamping * hitbox.getVerticalDamping();
        }

        AABB aabb;
        aabb.a(hitbox.getPosition() - hitbox.getHalfSize());
        aabb.b(hitbox.getPosition() + hitbox.getHalfSize());

        hitbox.setPosition(pos);
        hitbox.setVelocity(vel);

        rigidbody_c.rigidbody.setHitbox(hitbox);

        SensorsComponent* sensors_c = registry.try_get<SensorsComponent>(entity_r);

        if (!sensors_c)
        {
            continue;
        }

        auto sensors = sensors_c->sensors;

        for (size_t i = 0; i < sensors.size(); i++) 
        {
            auto& sensor = *sensors[i];

            auto entity = entt::entt_traits<entt::entity>::to_entity(entity_r);

            if (sensor.entity == entity) 
            {
                continue;
            }

            bool triggered = false;
            switch (sensor.type) 
            {
                case SensorType::AABB:
                    triggered = aabb.intersect(sensor.calculated.aabb);
                    break;
                case SensorType::RADIUS:
                    triggered = glm::distance(hitbox.getPosition(), glm::vec3(sensor.calculated.radial)) < 
                        sensor.calculated.radial.w;
                    break;
            }
            if (triggered) 
            {
                if (sensor.prev_entered.find(entity) == sensor.prev_entered.end()) 
                {
                    sensor.enter_callback(sensor.entity, sensor.index);
                }
                sensor.next_entered.insert(entity);
            }
        }
    }
}