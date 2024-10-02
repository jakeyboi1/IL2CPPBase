#pragma once
// Defining and setting our types for il2cpp
#define DO_API(r, n, p); // This is reuired for one of the included files
#ifndef IL2CPP_ILTYPES_H_
#define IL2CPP_ILTYPES_H_

// Include IL2CPP API types and functions
#include <il2cpp-api-types.h>
#include <il2cpp-api-functions.h> // File is a godsend and where we can find exact function signatures
#include <il2cpp-class-internals.h>
#include <il2cpp-object-internals.h>

// Typedefs for IL2CPP functions to be used later
// You can find the info for these inside of il2cpp-api-functions.h
// We are basically just recreating the function signatures
// DO_API(Il2CppDomain*, il2cpp_domain_get, ());
// DO_API(const Il2CppAssembly**, il2cpp_domain_get_assemblies, (const Il2CppDomain * domain, size_t * size));
// these are 2 examples from the file
typedef Il2CppDomain* (*domain_get_t)(); // Pointer type for getting the current domain
typedef const Il2CppAssembly** (*domain_get_assemblies_t)(const Il2CppDomain* domain, size_t* size);
typedef const Il2CppAssembly* (*domain_assembly_open_t)(Il2CppDomain* domain, const char* name);
typedef Il2CppClass* (*class_from_name_t)(const Il2CppImage* assembly, const char* name_space, const char* name);
typedef Il2CppClass* (*class_from_type_t)(const Il2CppType* type);
typedef MethodInfo* (*class_get_method_from_name_t)(Il2CppClass* klass, const char* name, int paramcount);
typedef const PropertyInfo* (*class_get_property_from_name_t)(Il2CppClass* klass, const char* name);
typedef Il2CppClass* (*class_from_il2cpp_type_t)(const Il2CppType* type);
typedef const MethodInfo* (*class_get_methods_t)(Il2CppClass* klass, void** iter);
typedef FieldInfo* (*class_get_field_from_name_t)(Il2CppClass* klass, const char* name);
typedef void (*field_get_value_t)(Il2CppObject* obj, FieldInfo* field, void* value);
typedef Il2CppObject* (*field_get_value_object_t)(FieldInfo* field, Il2CppObject* obj);
typedef Il2CppObject* (*type_get_object_t)(const Il2CppType* type);
typedef Il2CppObject* (*runtime_invoke_t)(const MethodInfo* method, void* obj, void** params, Il2CppException** exc);
typedef Il2CppObject* (*runtime_invoke_convert_args_t)(const MethodInfo* method, void* obj, Il2CppObject** params, int paramCount, Il2CppObject** exc);
typedef Il2CppString* (*string_new_t)(const char* str);
typedef Il2CppThread* (*thread_attach_t)(Il2CppDomain* domain);
typedef Il2CppObject* (*value_box_t)(Il2CppClass* klass, void* data);
typedef Il2CppObject* (*object_new_t)(Il2CppClass* klass);
typedef void* (*object_unbox_t)(Il2CppObject* obj);
typedef void (*runtime_object_init_t)(Il2CppObject* obj);
typedef FieldInfo* (*class_get_fields_t)(Il2CppClass* klass, void** iter);

// Inline declarations of the function pointers to avoid multiple definitions
inline domain_get_t domain_get; // Pointer to get the current domain
inline domain_get_assemblies_t domain_get_assemblies;
inline domain_assembly_open_t domain_assembly_open;
inline class_from_name_t class_from_name;
inline class_from_type_t class_from_type;
inline class_get_method_from_name_t class_get_method_from_name;
inline class_get_property_from_name_t class_get_property_from_name;
inline class_from_il2cpp_type_t class_from_il2cpp_type;
inline class_get_methods_t class_get_methods;
inline class_get_field_from_name_t class_get_field_from_name;
inline field_get_value_t field_get_value;
inline field_get_value_object_t field_get_value_object;
inline type_get_object_t type_get_object;
inline runtime_invoke_t runtime_invoke;
inline runtime_invoke_convert_args_t runtime_invoke_convert_args;
inline string_new_t string_new;
inline thread_attach_t thread_attach;
inline value_box_t value_box;
inline object_new_t object_new;
inline object_unbox_t object_unbox;
inline runtime_object_init_t runtime_object_init;
inline class_get_fields_t class_get_fields;
#endif