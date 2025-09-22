#pragma once

#include "types.h"
#include <vector>
#include <unordered_map>

namespace RustTool {

class ESP {
public:
    struct PlayerESPSettings {
        bool enabled = true;
        bool showBox = true;
        bool showName = true;
        bool showHealth = true;
        bool showDistance = true;
        bool showWeapon = true;
        bool showSkeleton = false;
        bool showSnapLines = false;
        float maxDistance = 300.0f;
        Color enemyColor = Color::Red();
        Color teammateColor = Color::Green();
        Color npcColor = Color::Yellow();
        Color sleepingColor = Color::Blue();
        bool boxFilled = false;
        float boxThickness = 1.0f;
    };
    
    struct LootESPSettings {
        bool enabled = true;
        bool showWeapons = true;
        bool showResources = true;
        bool showCrates = true;
        bool showStashes = true;
        bool showMedical = true;
        bool showFood = true;
        float maxDistance = 200.0f;
        Color weaponColor = Color::Red();
        Color resourceColor = Color::Green();
        Color crateColor = Color::Yellow();
        Color stashColor = Color::Blue();
        Color medicalColor = Color(1.0f, 0.5f, 1.0f); // Pink
        Color foodColor = Color(1.0f, 0.5f, 0.0f); // Orange
        bool distanceFiltering = true;
        int minRarity = 0; // 0=all, 1=uncommon+, 2=rare+, etc.
    };
    
    struct BaseESPSettings {
        bool enabled = false;
        bool showToolCupboards = true;
        bool showDoors = true;
        bool showSleepingBags = true;
        bool showTurrets = true;
        bool showTraps = true;
        bool showChests = true;
        float maxDistance = 150.0f;
        Color tcColor = Color::Red();
        Color doorColor = Color::Yellow();
        Color bagColor = Color::Green();
        Color turretColor = Color(1.0f, 0.0f, 1.0f); // Magenta
        Color trapColor = Color(1.0f, 0.5f, 0.0f); // Orange
        Color chestColor = Color::Blue();
    };

private:
    PlayerESPSettings m_playerSettings;
    LootESPSettings m_lootSettings;
    BaseESPSettings m_baseSettings;
    
    std::vector<Player> m_players;
    std::vector<LootItem> m_lootItems;
    std::vector<BaseEntity> m_baseEntities;
    
    // Rendering methods
    void DrawPlayerBox(const Player& player);
    void DrawPlayerInfo(const Player& player);
    void DrawPlayerSkeleton(const Player& player);
    void DrawPlayerHealth(const Player& player);
    void DrawSnapLine(const Vector2& from, const Vector2& to, const Color& color);
    
    void DrawLootItem(const LootItem& item);
    void DrawBaseEntity(const BaseEntity& entity);
    
    // Utility methods
    Color GetPlayerColor(const Player& player);
    Color GetLootColor(const LootItem& item);
    Color GetBaseEntityColor(const BaseEntity& entity);
    bool ShouldDrawPlayer(const Player& player);
    bool ShouldDrawLoot(const LootItem& item);
    bool ShouldDrawBaseEntity(const BaseEntity& entity);
    
public:
    ESP();
    ~ESP();
    
    void Update();
    void Render();
    
    // Settings accessors
    PlayerESPSettings& GetPlayerSettings() { return m_playerSettings; }
    LootESPSettings& GetLootSettings() { return m_lootSettings; }
    BaseESPSettings& GetBaseSettings() { return m_baseSettings; }
    
    void SetPlayerSettings(const PlayerESPSettings& settings) { m_playerSettings = settings; }
    void SetLootSettings(const LootESPSettings& settings) { m_lootSettings = settings; }
    void SetBaseSettings(const BaseESPSettings& settings) { m_baseSettings = settings; }
    
    // Toggle methods
    void TogglePlayerESP() { m_playerSettings.enabled = !m_playerSettings.enabled; }
    void ToggleLootESP() { m_lootSettings.enabled = !m_lootSettings.enabled; }
    void ToggleBaseESP() { m_baseSettings.enabled = !m_baseSettings.enabled; }
    
    // Data accessors
    const std::vector<Player>& GetPlayers() const { return m_players; }
    const std::vector<LootItem>& GetLootItems() const { return m_lootItems; }
    const std::vector<BaseEntity>& GetBaseEntities() const { return m_baseEntities; }
};

} // namespace RustTool