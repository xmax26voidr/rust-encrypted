# Troubleshooting Guide

## Common Issues and Solutions

### Installation Issues

#### Issue: "SilentLoader.exe is not recognized"
**Cause**: Antivirus software blocking the executable
**Solution**: 
1. Temporarily disable Windows Defender
2. Add exception for the tool folder
3. Run as administrator

#### Issue: "Access denied" when running loader
**Cause**: Insufficient permissions
**Solution**:
1. Right-click SilentLoader.exe
2. Select "Run as administrator"
3. Confirm UAC prompt

#### Issue: "Missing DLL files"
**Cause**: Incomplete extraction or blocked files
**Solution**:
1. Re-extract the entire archive
2. Ensure all files are in the same folder
3. Check if antivirus quarantined files

### Runtime Issues

#### Issue: Tool menu not appearing in-game
**Cause**: Injection failed or hotkey conflict
**Solution**:
1. Restart the injection process
2. Try different hotkey (default: INSERT)
3. Check if game is running as administrator

#### Issue: Aimbot not working
**Cause**: Incorrect settings or detection avoidance
**Solution**:
1. Check if aimbot is enabled (F1)
2. Verify FOV settings (try increasing to 120)
3. Ensure visibility check is appropriate for situation

#### Issue: ESP not showing players
**Cause**: ESP disabled or distance limits
**Solution**:
1. Toggle ESP on/off (F2)
2. Increase distance limit in settings
3. Check if players are within render distance

### Performance Issues

#### Issue: FPS drops when using tool
**Cause**: High ESP distance or render settings
**Solution**:
1. Reduce ESP distance limit to 100m
2. Lower update rate to 30Hz
3. Disable unnecessary ESP elements

#### Issue: Game crashes randomly
**Cause**: Memory conflicts or outdated drivers
**Solution**:
1. Update graphics drivers
2. Verify Rust game files
3. Reduce tool update rate
4. Close unnecessary background programs

### Detection Issues

#### Issue: Getting banned or warnings
**Cause**: Outdated tool version or suspicious behavior
**Solution**:
1. Update to latest version immediately
2. Use more conservative settings
3. Enable all safety features
4. Reduce usage frequency

#### Issue: Streaming software detecting overlay
**Cause**: Stream protection not enabled
**Solution**:
1. Enable OBS protection in settings
2. Enable Discord protection
3. Use windowed fullscreen mode
4. Restart streaming software

### Network Issues

#### Issue: Auto-update failing
**Cause**: Network restrictions or firewall
**Solution**:
1. Check internet connection
2. Temporarily disable firewall
3. Manual download from releases page
4. Run as administrator

#### Issue: Support links not working
**Cause**: Link expired or network issues
**Solution**:
1. Check for updated links in latest release
2. Clear browser cache
3. Try different browser
4. Use VPN if region-blocked

## Advanced Troubleshooting

### System Compatibility

#### Check System Requirements
Run this PowerShell command to check your system:
```powershell
Get-ComputerInfo | Select-Object WindowsProductName, WindowsVersion, TotalPhysicalMemory
```

#### Verify CPU Features
Check if your CPU supports AVX2:
```powershell
Get-CimInstance -ClassName Win32_Processor | Select-Object Name, Characteristics
```

#### Graphics Driver Check
Ensure latest drivers are installed:
1. NVIDIA: GeForce Experience
2. AMD: Radeon Software
3. Intel: Intel Driver & Support Assistant

### Registry Issues

#### Clean Previous Installations
If upgrading from older version:
1. Delete old configuration files
2. Clear registry entries (advanced users only)
3. Fresh installation in new folder

#### Windows Defender Exclusions
Add these paths to exclusions:
1. Tool installation folder
2. %APPDATA%\RustTool2025\
3. Steam\steamapps\common\Rust\

### Log Files

#### Locate Log Files
Check these locations for diagnostic logs:
- `%APPDATA%\RustTool2025\logs\`
- Tool installation folder
- Windows Event Viewer

#### Common Error Codes
- **0x001**: Injection failed - restart as admin
- **0x002**: Memory access denied - disable antivirus
- **0x003**: Game not found - ensure Rust is running
- **0x004**: Version mismatch - update tool
- **0x005**: Network error - check connection

## Getting Additional Help

### Before Contacting Support
1. Check this troubleshooting guide
2. Verify system requirements
3. Try safe mode configuration
4. Collect relevant log files

### Information to Provide
- Operating system version
- Tool version number
- Error messages or codes
- Steps to reproduce issue
- System specifications

### Emergency Reset
If all else fails, perform emergency reset:
1. Close Rust and tool completely
2. Delete configuration files
3. Fresh extraction of tool
4. Reset to default settings
5. Restart injection process