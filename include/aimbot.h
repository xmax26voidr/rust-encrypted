#pragma once

#include "types.h"
#include <vector>
#include <memory>

namespace RustTool {

class Aimbot {
public:
    struct Settings {
        bool enabled = false;
        float fov = 90.0f;
        float smoothness = 5.0f;
        BoneType targetBone = BoneType::Head;
        bool visibilityCheck = true;
        bool prediction = true;
        bool autoShoot = false;
        bool silentAim = false;
        bool aimThroughWalls = false;
        int aimKey = VK_LBUTTON; // Left mouse button
        float maxDistance = 300.0f;
        bool teamCheck = true;
    };

private:
    Settings m_settings;
    Player* m_currentTarget = nullptr;
    Vector2 m_screenCenter;
    bool m_isAiming = false;
    
    // Internal methods
    std::vector<Player> GetValidTargets();
    Player* SelectBestTarget(const std::vector<Player>& targets);
    Vector2 CalculateAimAngles(const Vector3& from, const Vector3& to);
    Vector3 PredictTargetPosition(const Player& target);
    bool IsTargetInFOV(const Player& target);
    bool IsTargetVisible(const Player& target);
    void SmoothAim(const Vector2& targetAngles);
    void SnapAim(const Vector2& targetAngles);
    
public:
    Aimbot();
    ~Aimbot();
    
    void Update();
    void Render();
    
    // Settings
    Settings& GetSettings() { return m_settings; }
    void SetSettings(const Settings& settings) { m_settings = settings; }
    
    // State
    bool IsEnabled() const { return m_settings.enabled; }
    void SetEnabled(bool enabled) { m_settings.enabled = enabled; }
    Player* GetCurrentTarget() const { return m_currentTarget; }
    bool IsAiming() const { return m_isAiming; }
    
    // FOV circle rendering
    void DrawFOVCircle();
    void DrawTargetInfo();
};

} // namespace RustTool