# Configuration Guide

## Default Configuration

The tool comes with optimized default settings, but you can customize everything to match your playstyle.

## Aimbot Settings

### Basic Settings
```
Enabled: true
Aim Key: Mouse1 (Left Click)
FOV: 90
Smoothness: 5.0
Target Bone: Head
```

### Advanced Settings
```
Visibility Check: true
Prediction: true
Auto Shoot: false
Silent Aim: false
Aim Through Walls: false
```

## ESP Settings

### Player ESP
```
Enabled: true
Show Names: true
Show Health: true
Show Distance: true
Box Type: 2D
Color: Red (enemies), Green (teammates)
```

### Loot ESP
```
Enabled: true
Show Weapons: true
Show Resources: true
Show Crates: true
Show Stashes: true
Distance Limit: 200m
```

### Base ESP
```
Enabled: false
Show Tool Cupboards: true
Show Doors: true
Show Sleeping Bags: true
Show Turrets: true
```

## Miscellaneous Settings

### No Recoil
```
Enabled: false
Weapon Specific: true
Compensation: 100%
```

### Auto Farm
```
Enabled: false
Target Types: Trees, Nodes, Barrels
Auto Swing: true
Optimal Distance: 3m
```

### Visual Enhancements
```
Always Day: false
Bright Caves: false
No Fog: false
Enhanced Colors: false
```

## Hotkey Configuration

### Default Hotkeys
```
Toggle Menu: INSERT
Toggle Aimbot: F1
Toggle ESP: F2
Toggle No Recoil: F3
Toggle Fly Hack: F4
Toggle Auto Farm: F5
Save Config: F9
Load Config: F10
```

### Custom Hotkeys
You can rebind any hotkey through the in-game menu:
1. Open the tool menu (INSERT)
2. Go to "Settings" tab
3. Click on "Hotkeys"
4. Select the function to rebind
5. Press the desired key combination
6. Save configuration

## Configuration Files

### Location
Configurations are saved in: `%APPDATA%\RustTool2025\configs\`

### File Format
```json
{
  "aimbot": {
    "enabled": true,
    "fov": 90,
    "smoothness": 5.0,
    "bone": "head"
  },
  "esp": {
    "players": true,
    "loot": true,
    "distance": 200
  },
  "misc": {
    "no_recoil": false,
    "auto_farm": false,
    "always_day": false
  }
}
```

### Sharing Configs
You can share configuration files with other users:
1. Navigate to the configs folder
2. Copy your `.json` config file
3. Share with other users
4. They should place it in their configs folder
5. Load using F10 or the menu

## Performance Optimization

### FPS Optimization
```
ESP Distance Limit: 150m (reduce for better FPS)
Update Rate: 60Hz (lower for weaker systems)
Render Quality: Medium
Thread Priority: Normal
```

### Memory Optimization
```
Cache Size: 256MB
Garbage Collection: Enabled
Memory Cleanup: Every 5 minutes
```

## Safety Settings

### Detection Avoidance
```
Randomization: Enabled
Delay Variance: 10-50ms
Human-like Movement: Enabled
Anti-Screenshot: Enabled
```

### Stream Safety
```
OBS Protection: Enabled
Discord Protection: Enabled
Screenshot Protection: Enabled
Recording Detection: Enabled
```