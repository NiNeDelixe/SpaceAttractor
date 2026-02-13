#include "PhysicsSystem.h"

void PhysicsSystem::update(EntityRegistry<DefaultEntityIndentifier> &registry)
{
    // float dt = delta / static_cast<float>(substeps);
    // float linearDamping = hitbox.linearDamping * hitbox.friction;
    // float s = 2.0f / BLOCK_AABB_GRID;

    // auto half = hitbox.getHalfSize();
    // glm::vec3& pos = hitbox.position;
    // glm::vec3& vel = hitbox.velocity;
    // float gravityScale = hitbox.gravityScale;
    
    // bool prevGrounded = hitbox.grounded;
    // hitbox.grounded = false;
    // for (uint_t i = 0; i < substeps; i++) {
    //     float px = pos.x;
    //     float py = pos.y;
    //     float pz = pos.z;
        
    //     vel += gravity * dt * gravityScale;
    //     if (hitbox.type == BodyType::DYNAMIC) {
    //         colisionCalc(chunks, hitbox, vel, pos, half, 
    //                      (prevGrounded && gravityScale > 0.0f) ? 0.5f : 0.0f);
    //     }

    //     pos += vel * dt + gravity * gravityScale * dt * dt * 0.5f;
    //     if (hitbox.grounded && pos.y < py) {
    //         pos.y = py;
    //     }

    //     if (hitbox.crouching && hitbox.grounded){
    //         float y = (pos.y-half.y-E);
    //         hitbox.grounded = false;
    //         for (int ix = 0; ix <= (half.x-E)*2/s; ix++) {
    //             float x = (px-half.x+E) + ix * s;
    //             for (int iz = 0; iz <= (half.z-E)*2/s; iz++){
    //                 float z = (pos.z-half.z+E) + iz * s;
    //                 if (chunks.isObstacleAt(x,y,z)){
    //                     hitbox.grounded = true;
    //                     break;
    //                 }
    //             }
    //         }
    //         if (!hitbox.grounded) {
    //             pos.z = pz;
    //         }
    //         hitbox.grounded = false;
    //         for (int ix = 0; ix <= (half.x-E)*2/s; ix++) {
    //             float x = (pos.x-half.x+E) + ix * s;
    //             for (int iz = 0; iz <= (half.z-E)*2/s; iz++){
    //                 float z = (pz-half.z+E) + iz * s;
    //                 if (chunks.isObstacleAt(x,y,z)){
    //                     hitbox.grounded = true;
    //                     break;
    //                 }
    //             }
    //         }
    //         if (!hitbox.grounded) {
    //             pos.x = px;
    //         }
    //         hitbox.grounded = true;
    //     }
    // }
    // vel.x /= 1.0f + delta * linearDamping;
    // vel.z /= 1.0f + delta * linearDamping;
    // if (hitbox.verticalDamping > 0.0f) {
    //     vel.y /= 1.0f + delta * linearDamping * hitbox.verticalDamping;
    // }

    // AABB aabb;
    // aabb.a = hitbox.position - hitbox.getHalfSize();
    // aabb.b = hitbox.position + hitbox.getHalfSize();
    // for (size_t i = 0; i < sensors.size(); i++) {
    //     auto& sensor = *sensors[i];
    //     if (sensor.entity == entity) {
    //         continue;
    //     }

    //     bool triggered = false;
    //     switch (sensor.type) {
    //         case SensorType::AABB:
    //             triggered = aabb.intersect(sensor.calculated.aabb);
    //             break;
    //         case SensorType::RADIUS:
    //             triggered = glm::distance2(
    //                 hitbox.position, glm::vec3(sensor.calculated.radial))
    //                  < sensor.calculated.radial.w;
    //             break;
    //     }
    //     if (triggered) {
    //         if (sensor.prevEntered.find(entity) == sensor.prevEntered.end()) {
    //             sensor.enterCallback(sensor.entity, sensor.index, entity);
    //         }
    //         sensor.nextEntered.insert(entity);
    //     }
    // }
}