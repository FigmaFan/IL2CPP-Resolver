#pragma once

#include <Windows.h>
#include <string.h>
#include <string>

#define ASSEMBLY_FILE "GameAssembly.dll"
#define ASSEMBLY_NAME "Assembly-CSharp"

#define ASSERT(x) { MessageBox(NULL, x, "il2cpp error", MB_OK | MB_ICONERROR); return false; }

namespace il2cpp
{
	namespace _internal
	{
		namespace unity_structs {
			struct il2cppImage
			{
				const char* m_pName;
				const char* m_oNameNoExt;
			};

			struct il2cppAssemblyName
			{
				const char* m_pName;
				const char* m_pCulture;
				const char* m_pHash;
				const char* m_pPublicKey;
				unsigned int m_uHash;
				int m_iHashLength;
				unsigned int m_uFlags;
				int m_iMajor;
				int m_iMinor;
				int m_iBuild;
				int m_bRevision;
				unsigned char m_uPublicKeyToken[8];
			};

			struct il2cppAssembly
			{
				il2cppImage* m_pImage;
				unsigned int m_uToken;
				int m_ReferencedAssemblyStart;
				int m_ReferencedAssemblyCount;
				il2cppAssemblyName m_aName;
			};

			struct il2cppClass
			{
				void* m_pImage;
				void* m_pGC;
				const char* m_pName;
				const char* m_pNamespace;
				void* m_pValue;
				void* m_pArgs;
				il2cppClass* m_pElementClass;
				il2cppClass* m_pCastClass;
				il2cppClass* m_pDeclareClass;
				il2cppClass* m_pParentClass;
				void* m_pGenericClass;
				void* m_pTypeDefinition;
				void* m_pInteropData;
				void* m_pFields;
				void* m_pEvents;
				void* m_pProperties;
				void** m_pMethods;
				il2cppClass** m_pNestedTypes;
				il2cppClass** m_ImplementedInterfaces;
				void* m_pInterfaceOffsets;
				void* m_pStaticFields;
				void* m_pRGCTX;
			};

			struct il2cppObject
			{
				il2cppClass* m_pClass = nullptr;
				void* m_pMonitor = nullptr;
			};

			struct il2cppType
			{
				union
				{
					void* m_pDummy;
					unsigned int m_uClassIndex;
					il2cppType* m_pType;
					void* m_pArray;
					unsigned int m_uGenericParameterIndex;
					void* m_pGenericClass;
				};
				unsigned int m_uAttributes : 16;
				unsigned int m_uType : 8;
				unsigned int m_uMods : 6;
				unsigned int m_uByref : 1;
				unsigned int m_uPinned : 1;
			};

			struct il2cppFieldInfo
			{
				const char* m_pName;
				il2cppType* m_pType;
				il2cppClass* m_pParentClass;
				int m_iOffset;
				int m_iAttributeIndex;
				unsigned int m_uToken;
			};

			struct il2cppParameterInfo
			{
				const char* m_pName;
				int m_iPosition;
				unsigned int m_uToken;
				il2cppType* m_pParameterType;
			};

			struct il2cppMethodInfo
			{
				void* m_pMethodPointer;
				void* m_pInvokerMethod;
				const char* m_pName;
				il2cppClass* m_pClass;
				il2cppType* m_pReturnType;
				il2cppParameterInfo* m_pParameters;

				union
				{
					void* m_pRGCTX;
					void* m_pMethodDefinition;
				};

				union
				{
					void* m_pGenericMethod;
					void* m_pGenericContainer;
				};

				unsigned int m_uToken;
				unsigned short m_uFlags;
				unsigned short m_uFlags2;
				unsigned short m_uSlot;
				unsigned char m_uArgsCount;
				unsigned char m_uGeneric : 1;
				unsigned char m_uInflated : 1;
				unsigned char m_uWrapperType : 1;
				unsigned char m_uMarshaledFromNative : 1;
			};

			struct il2cppPropertyInfo
			{
				il2cppClass* m_pParentClass;
				const char* m_pName;
				il2cppMethodInfo* m_pGet;
				il2cppMethodInfo* m_pSet;
				unsigned int m_uAttributes;
				unsigned int m_uToken;
			};

			struct il2cppArrayBounds
			{
				unsigned long long m_uLength;
				int m_iLowerBound;
			};

			struct Il2CppRuntimeInterfaceOffsetPair
			{
				il2cppClass* interfaceType;
				int32_t offset;
			};

			struct Il2CppClass_1
			{
				void* image;
				void* gc_desc;
				const char* name;
				const char* namespaze;
				il2cppType byval_arg;
				il2cppType this_arg;
				il2cppClass* element_class;
				il2cppClass* castClass;
				il2cppClass* declaringType;
				il2cppClass* parent;
				void* generic_class;
				void* typeMetadataHandle;
				void* interopData;
				il2cppClass* klass;
				void* fields;
				void* events;
				void* properties;
				void* methods;
				il2cppClass** nestedTypes;
				il2cppClass** implementedInterfaces;
				Il2CppRuntimeInterfaceOffsetPair* interfaceOffsets;
			};

			struct Il2CppClass_2
			{
				il2cppClass** typeHierarchy;
				void* unity_user_data;
				UINT32 initializationExceptionGCHandle;
				UINT32 cctor_started;
				UINT32 cctor_finished;
				size_t cctor_thread;
				void* genericContainerHandle;
				UINT32 instance_size;
				UINT32 actualSize;
				UINT32 element_size;
				INT32 native_size;
				UINT32 static_fields_size;
				UINT32 thread_static_fields_size;
				INT32 thread_static_fields_offset;
				UINT32 flags;
				UINT32 token;
				UINT16 method_count;
				UINT16 property_count;
				UINT16 field_count;
				UINT16 event_count;
				UINT16 nested_type_count;
				UINT16 vtable_count;
				UINT16 interfaces_count;
				UINT16 interface_offsets_count;
				UINT8 typeHierarchyDepth;
				UINT8 genericRecursionDepth;
				UINT8 rank;
				UINT8 minimumAlignment;
				UINT8 naturalAligment;
				UINT8 packingSize;
				UINT8 bitflags1;
				UINT8 bitflags2;
			};

			typedef void(*Il2CppMethodPointer)();
			struct VirtualInvokeData
			{
				Il2CppMethodPointer methodPtr;
				const il2cppMethodInfo* method;
			};

			struct System_String_VTable
			{
				VirtualInvokeData _0_Equals;
				VirtualInvokeData _1_Finalize;
				VirtualInvokeData _2_GetHashCode;
				VirtualInvokeData _3_ToString;
				VirtualInvokeData _4_CompareTo;
				VirtualInvokeData _5_System_Collections_IEnumerable_GetEnumerator;
				VirtualInvokeData _6_System_Collections_Generic_IEnumerable_System_Char__GetEnumerator;
				VirtualInvokeData _7_CompareTo;
				VirtualInvokeData _8_Equals;
				VirtualInvokeData _9_GetTypeCode;
				VirtualInvokeData _10_System_IConvertible_ToBoolean;
				VirtualInvokeData _11_System_IConvertible_ToChar;
				VirtualInvokeData _12_System_IConvertible_ToSByte;
				VirtualInvokeData _13_System_IConvertible_ToByte;
				VirtualInvokeData _14_System_IConvertible_ToInt16;
				VirtualInvokeData _15_System_IConvertible_ToUInt16;
				VirtualInvokeData _16_System_IConvertible_ToInt32;
				VirtualInvokeData _17_System_IConvertible_ToUInt32;
				VirtualInvokeData _18_System_IConvertible_ToInt64;
				VirtualInvokeData _19_System_IConvertible_ToUInt64;
				VirtualInvokeData _20_System_IConvertible_ToSingle;
				VirtualInvokeData _21_System_IConvertible_ToDouble;
				VirtualInvokeData _22_System_IConvertible_ToDecimal;
				VirtualInvokeData _23_System_IConvertible_ToDateTime;
				VirtualInvokeData _24_ToString;
				VirtualInvokeData _25_System_IConvertible_ToType;
				VirtualInvokeData _26_Clone;
			};

			struct System_String_c
			{
				Il2CppClass_1 _1;
				struct System_String_StaticFields* static_fields;
				void* rgctx_data;
				Il2CppClass_2 _2;
				System_String_VTable vtable;
			};

			struct __declspec(align(8)) System_String_Fields
			{
				UINT32 _stringLength;
				UINT16 _firstChar;
			};

			struct System_String_o
			{
				System_String_c* klass;
				void* monitor;
				System_String_Fields fields;
			};
		}

		inline HMODULE p_game_assembly = GetModuleHandleA(ASSEMBLY_FILE);
		inline _internal::unity_structs::il2cppAssembly* p_assembly = nullptr;

		template <class T>
		T resolve_export(::std::string name) {
			return reinterpret_cast<T>(GetProcAddress((HMODULE)p_game_assembly, name.c_str()));
		}

		inline auto resolve_call = resolve_export<void* (__fastcall*)(const char*)>("il2cpp_resolve_icall");
		inline auto get_domain = resolve_export<void* (__fastcall*)(void)>("il2cpp_domain_get");
		inline auto thread_attach = resolve_export<void* (__fastcall*)(void*)>("il2cpp_thread_attach");
		inline auto get_assemblies = resolve_export<unity_structs::il2cppAssembly * *(__fastcall*)(void*, size_t*)>("il2cpp_domain_get_assemblies");
		inline auto class_from_name = resolve_export<unity_structs::il2cppClass * (__fastcall*)(unity_structs::il2cppImage*, const char*, const char*)>("il2cpp_class_from_name");
		inline auto method_from_name = resolve_export<unity_structs::il2cppMethodInfo * (__fastcall*)(unity_structs::il2cppClass*, const char*, int)>("il2cpp_class_get_method_from_name");
		inline auto field_from_name = resolve_export<unity_structs::il2cppFieldInfo * (__fastcall*)(unity_structs::il2cppClass*, const char*)>("il2cpp_class_get_field_from_name");
		inline auto static_field_get_value = resolve_export<void(__fastcall*)(unity_structs::il2cppFieldInfo*, void*)>("il2cpp_field_static_get_value");
		inline auto static_field_set_value = resolve_export<void(__fastcall*)(unity_structs::il2cppFieldInfo*, void*)>("il2cpp_field_static_set_value");
		inline auto create_new_string = resolve_export<unity_structs::System_String_o * (__fastcall*)(const char*)>("il2cpp_string_new");
		inline auto field_set_value = resolve_export<void(__fastcall*)(void*, unity_structs::il2cppFieldInfo*, void*)>("il2cpp_field_set_value");
		inline auto field_get_value = resolve_export<void(__fastcall*)(void*, unity_structs::il2cppFieldInfo*, void*)>("il2cpp_field_get_value");

		inline _internal::unity_structs::il2cppAssembly* find_assembly(::std::string assembly_name) {
			if (assembly_name.empty()) { return nullptr; }

			size_t assembly_count = 0;
			auto pp_assemblies = get_assemblies(get_domain(), &assembly_count);
			for (size_t i = 0; i < assembly_count; i++) {
				if (assembly_name.compare(pp_assemblies[i]->m_aName.m_pName) == 0) { return pp_assemblies[i]; }
			}

			return nullptr;
		}
	}

	template <typename ret, typename... _args>
	inline ret call_function(_internal::unity_structs::il2cppMethodInfo* p_method, _args... args) {
		typedef ret(*func)(_args...);
		func fn = (func)((void*)p_method->m_pMethodPointer);
		return fn(args...);
	}

	inline _internal::unity_structs::il2cppClass* find_class(::std::string _namespace, ::std::string class_name, ::std::string assembly_name = "Assembly-CSharp") {
		if (_namespace.empty() || class_name.empty()) { return nullptr; }

		auto p_assembly = _internal::find_assembly(assembly_name);

		if (p_assembly) {
			if (p_assembly->m_pImage) {
				return _internal::class_from_name(p_assembly->m_pImage, _namespace.c_str(), class_name.c_str());
			}
		}
		return nullptr;
	}

	inline _internal::unity_structs::il2cppMethodInfo* get_fn_ptr(_internal::unity_structs::il2cppClass* p_class, ::std::string method_name, int args_count = 0) {
		return _internal::method_from_name(p_class, method_name.c_str(), args_count);
	}

	inline _internal::unity_structs::il2cppMethodInfo* get_method(::std::string _namespace, ::std::string class_name, ::std::string method_name, ::std::string assembly_name = "Assembly-CSharp") {
		if (_namespace.empty() || class_name.empty() || method_name.empty()) { return nullptr; }

		auto p_class = find_class(_namespace, class_name, assembly_name);

		for (int i = 0; i < 16; i++) {
			auto p_info = _internal::method_from_name(p_class, method_name.c_str(), i);

			if (!p_info) { continue; }

			return p_info;
		}

		return nullptr;
	}

	inline ::std::string to_string(_internal::unity_structs::System_String_o* p_sys_str) {
		if (!p_sys_str) { return ::std::string(); }
		else {
			auto w_str = ::std::wstring((wchar_t*)(&p_sys_str->fields._firstChar));
			return ::std::string(w_str.begin(), w_str.end());
		}
	}

	template <class type>
	type get_object_field_value(void* p_instance, ::std::string _namespace, ::std::string class_name, ::std::string field_name, ::std::string assembly_name = "Assembly-CSharp") {
		if (!p_instance || _namespace.empty() || class_name.empty() || field_name.empty()) { return NULL; }

		const auto p_class = find_class(_namespace, class_name);
		if (!p_class) { return NULL; }

		const auto p_field = _internal::field_from_name(p_class, field_name.c_str());
		if (!p_field) { return NULL; }

		type buffer;
		_internal::field_get_value(p_instance, p_field, &buffer);
		return buffer;
	}

	template <class type>
	bool set_object_field_value(void* p_instance, ::std::string _namespace, ::std::string class_name, ::std::string field_name, type value, ::std::string assembly_name = "Assembly-CSharp") {
		if (!p_instance || _namespace.empty() || class_name.empty() || field_name.empty()) { return false; }

		const auto p_class = find_class(_namespace, class_name);
		if (!p_class) { return false; }

		const auto p_field = _internal::field_from_name(p_class, field_name);
		if (!p_field) { return false; }

		_internal::field_set_value(p_instance, p_field, &value);
		return true;
	}

	template <class type>
	type get_static_field_value(_internal::unity_structs::il2cppClass* p_class, ::std::string field_name) {
		if (!p_class || field_name.empty()) { return NULL; }

		auto field = _internal::field_from_name(p_class, field_name.c_str());

		type buffer;
		_internal::static_field_get_value(field, &buffer);
		return buffer;
	}

	template <class type>
	bool set_static_field_value(_internal::unity_structs::il2cppClass* p_class, ::std::string field_name, type value) {
		if (!p_class || field_name.empty()) { return false; }

		auto p_field = _internal::field_from_name(p_class, field_name);
		if (!p_field) { return false; }

		_internal::static_field_set_value(p_field, &value);
	}

	inline int get_field_offset(::std::string _namespace, ::std::string class_name, ::std::string field_name, ::std::string assembly_name = "Assembly-CSharp") {
		if (_namespace.empty() || class_name.empty() || field_name.empty()) { return -1; }

		auto p_class = find_class(_namespace, class_name, assembly_name);
		if (p_class) {
			auto p_field = _internal::field_from_name(p_class, field_name.c_str());
			if (p_field) { return p_field->m_iOffset; }
		}

		return -1;
	}

	inline _internal::unity_structs::System_String_o* create_new_string(::std::string str) {
		if (str.empty()) { return nullptr; }

		return _internal::create_new_string(str.c_str());
	}

	/*
	* Gets a 32-bit integer that represents the number of elements in the specified dimension of the System.Array
	* dimension: A zero-based dimension of the System.Array whose length needs to be determined.
	* returns: A 32-bit integer that represents the number of elements in the specified dimension.
	*/
	inline int get_array_size(void* p_system_array_o, int dimension) {
		if (!p_system_array_o || dimension < 0) { return 0; }

		auto pGetLengthMethodInfo = get_method("System", "Array", "GetLength", "mscorlib");
		if (pGetLengthMethodInfo) {
			return il2cpp::call_function<int>(pGetLengthMethodInfo, p_system_array_o, dimension, 0);
		}

		return 0;
	}

	/*
	* Gets the value at the specified position in the one-dimensional System.Array. The index is specified as a 64-bit integer.
	* index: A 64-bit integer that represents the position of the System.Array element to get.
	* returns: The value at the specified position in the one-dimensional System.Array.
	*/
	template <typename ret>
	inline ret get_array_element(void* p_array, long long index) {
		if (!p_array) { return NULL; }

		auto pGetValueMethodInfo = get_method("System", "Array", "GetValue", "mscorlib");
		if (pGetValueMethodInfo) {
			return il2cpp::call_function<ret>(pGetValueMethodInfo, p_array, index, 0);
		}

		return NULL;
	}

	/*
	* Copies the elements of the System.Collections.ArrayList to a new System.Object array.
	* returns: An System.Object array containing copies of the elements of the System.Collections.ArrayList.
	*/
	inline void* convert_array_list_to_array(void* p_system_collections_arraylist_o) {
		if (!p_system_collections_arraylist_o) { return nullptr; }

		auto pToArrayMethodInfo = get_method("System.Collections", "ArrayList", "ToArray", "mscorlib");
		if (pToArrayMethodInfo) {
			return il2cpp::call_function<void*>(pToArrayMethodInfo, p_system_collections_arraylist_o, 0);
		}

		return nullptr;
	}

	inline bool init() {
		if (!_internal::p_game_assembly) { ASSERT("failed to get GameAssembly.dll") }
		if (!_internal::resolve_call) { ASSERT("failed to get resolve_call") }
		if (!_internal::get_domain) { ASSERT("failed to get get_domain") }
		if (!_internal::thread_attach) { ASSERT("failed to get thread_attach") }

		size_t assembly_count = 0;
		auto p_domain = _internal::get_domain();
		if (p_domain) {
			auto pp_assemblies = _internal::get_assemblies(p_domain, &assembly_count);
			for (size_t i = 0; i < assembly_count; i++) {
				if (::std::string(pp_assemblies[i]->m_aName.m_pName) == ASSEMBLY_NAME) { _internal::p_assembly = pp_assemblies[i]; }
			}
		}

		if (!_internal::p_assembly) { ASSERT("failed to find assembly") }

		return true;
	}
}