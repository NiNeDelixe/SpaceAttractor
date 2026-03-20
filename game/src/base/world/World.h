#pragma once
#ifndef WORLD_WORLD_H_
#define WORLD_WORLD_H_

#include <memory>

#include "base/world/Level.h"

class World : public std::enable_shared_from_this<World>
{
public:
    World() = default;
    ~World() = default;

public:
    bool setLevel(const std::shared_ptr<Level>& level);
    [[nodiscard]] bool hasLevel() const { return static_cast<bool>(m_level); }
    [[nodiscard]] const std::shared_ptr<Level>& level() const { return m_level; }

private:
    std::shared_ptr<Level> m_level;
};

#endif  // WORLD_WORLD_H_
