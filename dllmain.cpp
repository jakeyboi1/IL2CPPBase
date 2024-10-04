#include "pch.h"
#include <string>
#include <Windows.h>
#include <iostream>
#include "IL2CPP.hpp"

// remade unity classes includes
#include "BaseTypes.hpp"
#include "UnityEngine.hpp"
#include "Camera.hpp"

using namespace std;
using namespace Unity;

void Init() {
    // Initilizing our class il2cpp base class and our unity engine class to use the rebuilt unity engine classes
    IL2CPPBaseClass IL2CPPBase;
    IL2CPPBase.Init();
    UnityEngine unityEngine;
    unityEngine.InitUnityClasses(IL2CPPBase); // Must be called before using any functions inside of this class

    // Allocate a console for debugging output
    AllocConsole();
    FILE* console;
    freopen_s(&console, "CONOUT$", "w", stdout); // Redirect stdout to console
    freopen_s(&console, "CONIN$", "r", stdin); // Redirect stdin to console
    cout.clear(); // Clear the output stream

    IL2CPPBase.PrintAllClasses();

    while (true) {
        Sleep(10);
        //unityEngine.Camera.SetFOV(mainCamera, 90.f);
        //Il2CppObject* mainCamera = unityEngine.Camera.GetMain();
    }
}

BOOL APIENTRY DllMain(HMODULE hModule, DWORD ul_reason_for_call, LPVOID lpReserved)
{
    switch (ul_reason_for_call)
    {
    case DLL_PROCESS_ATTACH:
        CreateThread(NULL, 0, (LPTHREAD_START_ROUTINE)Init, NULL, 0, NULL);
        break;
    case DLL_THREAD_ATTACH:
    case DLL_THREAD_DETACH:
    case DLL_PROCESS_DETACH:
        break;
    }
    return TRUE;
}