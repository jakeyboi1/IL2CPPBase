#pragma once
#include "IL2CPP.hpp"
#include "BaseTypes.hpp"

namespace Unity {
	class CCamera {
	public:
		IL2CPPBaseClass ilbase;
		Il2CppClass* camClass;

		// Constructor to initialize variables we need
		void Init(IL2CPPBaseClass base) {
			ilbase = base;
			camClass = ilbase.GetClassByName("UnityEngine", "Camera");
		}

		Il2CppObject* GetMain() {
			MethodInfo* getMainCamera = ilbase.GetMethodFromClass(camClass, "get_main", 0);
			Il2CppObject* mainCamera = ilbase.CallMethod(getMainCamera, nullptr, nullptr);
			mainCamera->vtable->methods;
			return mainCamera;
		}

		Il2CppObject* GetCurrent() {
			MethodInfo* getCurrCamera = ilbase.GetMethodFromClass(camClass, "get_current", 0);
			Il2CppObject* currCamera = ilbase.CallMethod(getCurrCamera, nullptr, nullptr);
			return currCamera;
		}

		void SetFOV(Il2CppObject* camToChange, float fov) {
			MethodInfo* setFOV = ilbase.GetMethodFromClass(camClass, "set_fieldOfView", 1);
			Il2CppObject* mainCamera = GetMain();
			// Set a new field of view
			float newFOV = fov;
			void* args[1];
			args[0] = &newFOV;

			ilbase.CallMethod(setFOV, mainCamera, args);
		}
	};
}