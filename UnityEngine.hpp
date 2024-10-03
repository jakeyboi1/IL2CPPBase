#pragma once
#include "BaseTypes.hpp"
#include "IL2CPP.hpp"
#include "Camera.hpp"

namespace Unity {
	//Declaring namespace here for any extras
	class UnityEngine {
	public:
		CCamera Camera;
		void InitUnityClasses(IL2CPPBaseClass il2cppbaseclass) {
			Camera.Init(il2cppbaseclass);
		}
	};
}