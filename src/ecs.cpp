#include <array>
#include <bitset>
#include <cassert>
#include <cstdint>
#include <queue>

const int MAX_ENTITIES = 5000;
const int MAX_COMPONENTS = 32;

using Entity = std::uint32_t;
using Signature = std::bitset<MAX_COMPONENTS>;

class EntityManager {
public:
  EntityManager() {
    for (Entity entity = 0; entity < MAX_ENTITIES; entity++) {
      m_available_entities.push(entity);
    }
  }

  Entity create_entity() {
    assert(m_living_entity_count < MAX_ENTITIES && "too many entities");

    Entity id = m_available_entities.front();
    m_available_entities.pop();
    m_living_entity_count++;
    return id;
  }

  void destroy_entity(Entity entity) {
    assert(entity < MAX_ENTITIES && "entity out of range");

    m_signatures[entity].reset();
    m_available_entities.push(entity);
    m_living_entity_count--;
  }

  void set_signature(Entity entity, Signature signature) {
    assert(entity < MAX_ENTITIES);
    m_signatures[entity] = signature;
  }

  Signature get_signature(Entity entity) {
    assert(entity < MAX_ENTITIES);
    return m_signatures[entity];
  }

private:
  std::queue<Entity> m_available_entities;
  std::array<Signature, MAX_ENTITIES> m_signatures;
  std::uint32_t m_living_entity_count = 0;
};
