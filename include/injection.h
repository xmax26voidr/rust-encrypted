#pragma once

#include <windows.h>
#include <string>
#include <vector>

namespace RustTool {

class ProcessUtils {
public:
    static DWORD GetProcessIdByName(const std::wstring& processName);
    static HANDLE OpenProcessWithAccess(DWORD processId, DWORD access);
    static bool IsProcessRunning(DWORD processId);
    static std::wstring GetProcessPath(DWORD processId);
    static bool InjectDLL(DWORD processId, const std::wstring& dllPath);
    static std::vector<DWORD> GetAllProcessIds(const std::wstring& processName);
};

class Injection {
public:
    static bool ManualMapDLL(HANDLE hProcess, const std::string& dllData);
    static bool LoadLibraryInject(HANDLE hProcess, const std::wstring& dllPath);
    static bool SetWindowsHookInject(const std::wstring& dllPath);
    static void* GetModuleBaseAddress(HANDLE hProcess, const std::wstring& moduleName);
};

} // namespace RustTool