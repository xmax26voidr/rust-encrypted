#pragma once

#include <windows.h>
#include <d3d11.h>
#include <dxgi.h>
#include <DirectXMath.h>
#include <vector>
#include <string>
#include <memory>

using namespace DirectX;

namespace RustTool {

struct Vector3 {
    float x, y, z;
    Vector3() : x(0), y(0), z(0) {}
    Vector3(float x, float y, float z) : x(x), y(y), z(z) {}
    
    Vector3 operator+(const Vector3& other) const { return Vector3(x + other.x, y + other.y, z + other.z); }
    Vector3 operator-(const Vector3& other) const { return Vector3(x - other.x, y - other.y, z - other.z); }
    Vector3 operator*(float scalar) const { return Vector3(x * scalar, y * scalar, z * scalar); }
    float Length() const { return sqrt(x * x + y * y + z * z); }
    Vector3 Normalize() const { float len = Length(); return len > 0 ? *this * (1.0f / len) : Vector3(); }
};

struct Vector2 {
    float x, y;
    Vector2() : x(0), y(0) {}
    Vector2(float x, float y) : x(x), y(y) {}
    
    Vector2 operator+(const Vector2& other) const { return Vector2(x + other.x, y + other.y); }
    Vector2 operator-(const Vector2& other) const { return Vector2(x - other.x, y - other.y); }
    float Length() const { return sqrt(x * x + y * y); }
};

struct Color {
    float r, g, b, a;
    Color() : r(1.0f), g(1.0f), b(1.0f), a(1.0f) {}
    Color(float r, float g, float b, float a = 1.0f) : r(r), g(g), b(b), a(a) {}
    
    static Color Red() { return Color(1.0f, 0.0f, 0.0f); }
    static Color Green() { return Color(0.0f, 1.0f, 0.0f); }
    static Color Blue() { return Color(0.0f, 0.0f, 1.0f); }
    static Color White() { return Color(1.0f, 1.0f, 1.0f); }
    static Color Black() { return Color(0.0f, 0.0f, 0.0f); }
    static Color Yellow() { return Color(1.0f, 1.0f, 0.0f); }
};

enum class BoneType {
    Head,
    Neck,
    Chest,
    Pelvis,
    LeftArm,
    RightArm,
    LeftLeg,
    RightLeg
};

struct Player {
    uintptr_t baseAddress;
    Vector3 position;
    Vector3 headPosition;
    Vector2 screenPosition;
    Vector2 headScreenPosition;
    std::string name;
    float health;
    float maxHealth;
    bool isVisible;
    bool isValid;
    bool isSleeping;
    bool isNPC;
    float distance;
    std::string weaponName;
};

struct LootItem {
    uintptr_t baseAddress;
    Vector3 position;
    Vector2 screenPosition;
    std::string name;
    std::string displayName;
    int amount;
    float distance;
    bool isVisible;
    bool isValid;
    int rarity; // 0=common, 1=uncommon, 2=rare, 3=epic, 4=legendary
};

struct BaseEntity {
    uintptr_t baseAddress;
    Vector3 position;
    Vector2 screenPosition;
    std::string name;
    std::string type;
    float distance;
    bool isVisible;
    bool isValid;
    bool isDestroyed;
};

} // namespace RustTool