#pragma once

#include <windows.h>
#include <string>
#include <memory>

namespace RustTool {

class Utils {
public:
    // String utilities
    static std::wstring StringToWString(const std::string& str);
    static std::string WStringToString(const std::wstring& wstr);
    static std::string ToLowerCase(const std::string& str);
    static std::string ToUpperCase(const std::string& str);
    static bool Contains(const std::string& str, const std::string& substr);
    
    // File utilities
    static bool FileExists(const std::wstring& path);
    static std::string ReadFileToString(const std::wstring& path);
    static bool WriteStringToFile(const std::wstring& path, const std::string& content);
    static std::wstring GetExecutablePath();
    static std::wstring GetExecutableDirectory();
    
    // Math utilities
    static float DegreesToRadians(float degrees);
    static float RadiansToDegrees(float radians);
    static float Clamp(float value, float min, float max);
    static float Lerp(float a, float b, float t);
    static float Distance2D(float x1, float y1, float x2, float y2);
    static float Distance3D(float x1, float y1, float z1, float x2, float y2, float z2);
    
    // System utilities
    static void ShowConsole();
    static void HideConsole();
    static void SetConsoleTitle(const std::wstring& title);
    static DWORD GetCurrentProcessId();
    static bool IsUserAdmin();
    static void CreateBeep(DWORD frequency, DWORD duration);
    
    // Random utilities
    static int RandomInt(int min, int max);
    static float RandomFloat(float min, float max);
    static void SeedRandom();
    
    // Time utilities
    static DWORD GetCurrentTimeMs();
    static std::string GetCurrentTimeString();
    static void Sleep(DWORD milliseconds);
};

class Logger {
private:
    static std::wstring m_logFilePath;
    static bool m_consoleOutput;
    static bool m_fileOutput;
    
public:
    enum LogLevel {
        LOG_INFO,
        LOG_WARNING,
        LOG_ERROR,
        LOG_DEBUG
    };
    
    static void Initialize(const std::wstring& logPath = L"", bool console = true, bool file = true);
    static void Log(LogLevel level, const std::string& message);
    static void Info(const std::string& message);
    static void Warning(const std::string& message);
    static void Error(const std::string& message);
    static void Debug(const std::string& message);
    static void Shutdown();
    
private:
    static std::string LogLevelToString(LogLevel level);
    static void WriteToFile(const std::string& message);
    static void WriteToConsole(const std::string& message);
};

} // namespace RustTool