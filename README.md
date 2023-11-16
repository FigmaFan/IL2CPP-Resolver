# IL2CPP-Resolver
unity il2cpp game hacking library

# how to use
include il2cpp_resolver.h in your project

# doc
before using il2cpp resolver, call il2cpp::init once!

## how to call a function
```C++
auto result = il2cpp::call_function<[return type]>(il2cpp::get_method("[namespace]", "[class_name]", "[method_name]"), [class_instance], [argument(s)], [method]);
```
example:
```C++
il2cpp::call_function<void>(il2cpp::get_method("Assets.Scripts.Unity.Player", "Btd6Player", "AddItemToInventory"), p_btd6_player, p_item_id, 0);
```
## how to read value of a static field
```C++

```
example:
```C++

```
## how to write value to a static field
```C++

```
example:
```C++

```
## how to convert "il2cpp string" to std::string
```C++
std::string converted_string = il2cpp::to_string([string_to_convert]);
```
example:
```C++
System_String_o* p_sys_str = ...;
std::string str = il2cpp::to_string(p_sys_str);
```
