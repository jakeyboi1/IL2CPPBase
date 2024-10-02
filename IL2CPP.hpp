#pragma once
#include "pch.h"
#include <string>
#include <Windows.h>
#include <iostream>
#include "IL2CPPTypes.hpp"
using namespace std;
// Include this folder from the game engine (Yes you do need to download the unity engine, also the 2021.3.5f1 will change depending on the version you use) in your project : C:\Program Files\Unity\Hub\Editor\2021.3.5f1\Editor\Data\il2cpp\libil2cpp
// make sure to use C++ 20 or higher

class IL2CPPBaseClass {
public:
    HMODULE asmMod;
    Il2CppDomain* domain;
    size_t asmCount;
    const Il2CppAssembly** asmList;

	void Init() {
        asmMod = GetModuleHandleA("GameAssembly.dll"); // Get a handle to the GameAssembly module
        // Initialize IL2CPP function pointers
        // These are basically getting these functions from the GameAssembly.dll so we can call them
        domain_get = reinterpret_cast<domain_get_t>(GetProcAddress(asmMod, "il2cpp_domain_get"));
        domain_get_assemblies = reinterpret_cast<domain_get_assemblies_t>(GetProcAddress(asmMod, "il2cpp_domain_get_assemblies"));
        domain_assembly_open = reinterpret_cast<domain_assembly_open_t>(GetProcAddress(asmMod, "il2cpp_domain_assembly_open"));
        class_from_name = reinterpret_cast<class_from_name_t>(GetProcAddress(asmMod, "il2cpp_class_from_name"));
        class_from_type = reinterpret_cast<class_from_type_t>(GetProcAddress(asmMod, "il2cpp_class_from_type"));
        class_get_method_from_name = reinterpret_cast<class_get_method_from_name_t>(GetProcAddress(asmMod, "il2cpp_class_get_method_from_name"));
        class_get_property_from_name = reinterpret_cast<class_get_property_from_name_t>(GetProcAddress(asmMod, "il2cpp_class_get_property_from_name"));
        class_from_il2cpp_type = reinterpret_cast<class_from_il2cpp_type_t>(GetProcAddress(asmMod, "il2cpp_class_from_il2cpp_type"));
        class_get_methods = reinterpret_cast<class_get_methods_t>(GetProcAddress(asmMod, "il2cpp_class_get_methods"));
        class_get_field_from_name = reinterpret_cast<class_get_field_from_name_t>(GetProcAddress(asmMod, "il2cpp_class_get_field_from_name"));
        field_get_value = reinterpret_cast<field_get_value_t>(GetProcAddress(asmMod, "il2cpp_field_get_value"));
        field_get_value_object = reinterpret_cast<field_get_value_object_t>(GetProcAddress(asmMod, "il2cpp_field_get_value_object"));
        type_get_object = reinterpret_cast<type_get_object_t>(GetProcAddress(asmMod, "il2cpp_type_get_object"));
        runtime_invoke = reinterpret_cast<runtime_invoke_t>(GetProcAddress(asmMod, "il2cpp_runtime_invoke"));
        runtime_invoke_convert_args = reinterpret_cast<runtime_invoke_convert_args_t>(GetProcAddress(asmMod, "il2cpp_runtime_invoke_convert_args"));
        string_new = reinterpret_cast<string_new_t>(GetProcAddress(asmMod, "il2cpp_string_new"));
        thread_attach = reinterpret_cast<thread_attach_t>(GetProcAddress(asmMod, "il2cpp_thread_attach"));
        value_box = reinterpret_cast<value_box_t>(GetProcAddress(asmMod, "il2cpp_value_box"));
        object_new = reinterpret_cast<object_new_t>(GetProcAddress(asmMod, "il2cpp_object_new"));
        object_unbox = reinterpret_cast<object_unbox_t>(GetProcAddress(asmMod, "il2cpp_object_unbox"));
        runtime_object_init = reinterpret_cast<runtime_object_init_t>(GetProcAddress(asmMod, "il2cpp_runtime_object_init"));
        class_get_fields = reinterpret_cast<class_get_fields_t>(GetProcAddress(asmMod, "il2cpp_class_get_fields"));

        domain = domain_get(); // Get the current IL2CPP domain
        thread_attach(domain); // Attach the current thread to the IL2CPP domain
	}

    Il2CppImage* GetImageByName(const char* targetName) {
        asmList = domain_get_assemblies(domain, &asmCount); // Get the list of assemblies in the domain
        for (size_t i = 0; i < asmCount; i++) {
            // Retrieve the Il2CppImage directly using the assembly name
            Il2CppImage* image = domain_assembly_open(domain, asmList[i]->aname.name)->image;

            // Check if the assembly name matches the target name
            if (strcmp(asmList[i]->aname.name, targetName) == 0) {
                return image; // Return the image if the name matches
            }
        }
        return nullptr; // Return nullptr if no image with the specified name is found
    }

    Il2CppClass* GetClassByName(const char* classNamespace, const char* className) { //This function searches through every game assembly to find a class (Game assemblies can be obtained through il2cpp dumper if you want to see them yourself)
        asmList = domain_get_assemblies(domain, &asmCount);
        for (size_t i = 0; i < asmCount; i++) {
            Il2CppImage* img = domain_assembly_open(domain, asmList[i]->aname.name)->image;
            Il2CppClass* klass = class_from_name(img, classNamespace, className);
            if (klass) {
                return klass;
            }
        }
    }

    MethodInfo* GetMethodFromClass(Il2CppClass* klass, const char* method, int paramCount) {
        return class_get_method_from_name(klass, method, paramCount);
    }

    auto CallMethod(MethodInfo* method, Il2CppObject* object, void** args) {
        return runtime_invoke(method, object, args, nullptr);
    }
};