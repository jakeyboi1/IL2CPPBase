#include "pch.h"
#include <string>
#include <Windows.h>
#include <iostream>
#include "IL2CPP.h"
using namespace std;
void Init() {
    // Initilizing our class
    IL2CPPBaseClass IL2CPPBase;
    IL2CPPBase.Init();

    // Allocate a console for debugging output
    AllocConsole();
    FILE* console;
    freopen_s(&console, "CONOUT$", "w", stdout); // Redirect stdout to console
    freopen_s(&console, "CONIN$", "r", stdin); // Redirect stdin to console
    cout.clear(); // Clear the output stream

    Il2CppClass* cameraClass = IL2CPPBase.GetClassByName("UnityEngine", "Camera");
    if (!cameraClass) {
        printf("Camera class not found.");
        return;
    }
    MethodInfo* getMainCamera = IL2CPPBase.GetMethodFromClass(cameraClass, "get_main", 0);
    if (!getMainCamera) {
        printf("get_main method not found.");
        return;
    }
    Il2CppException* exception = nullptr;
    Il2CppObject* mainCamera = IL2CPPBase.CallMethod(getMainCamera, nullptr, nullptr);

    if (exception) {
        printf("Exception occurred while getting main camera.");
        return;
    }

    if (!mainCamera) {
        printf("Main camera is null.");
        return;
    }
    MethodInfo* setFOVMethod = IL2CPPBase.GetMethodFromClass(cameraClass, "set_fieldOfView", 1);
    if (!setFOVMethod) {
        printf("set_fieldOfView method not found.");
        return;
    }
    while (true) {
        Sleep(10);
        // Set a new field of view
        float newFOV = 90.0f;
        void* args[1];
        args[0] = &newFOV;

        IL2CPPBase.CallMethod(setFOVMethod, mainCamera, args);

        if (exception) {
            printf("Exception occurred while setting field of view.");
        }
        else {
            printf("FOV Set");
        }
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