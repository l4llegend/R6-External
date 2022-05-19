#pragma once 
#include <windows.h>
#include <iostream> 
#include <vector>

struct moduleStruct {
	uintptr_t procHandle;
	LPCTSTR name;
	
};
class Memory
{
private:
		HANDLE procHandle;
		std::vector<moduleStruct*> moduels;
		BOOLEAN bInited;
		DWORD processID;

private:
	BOOLEAN Init(LPCTSTR ProcName);
	uintptr_t FindDMAAddy(uintptr_t addr, std::vector<unsigned int> offset);
	DWORD FindProcessID(LPCTSTR moduleName);
	uintptr_t FindModuleBase(LPCTSTR moduleName);
public:
	Memory();
	Memory(LPCTSTR ProcName);
	BOOLEAN AddModuleToList(LPCTSTR Name);
	uintptr_t getModuleBaseFromList(LPCTSTR Name);
	DWORD getPID();
	HANDLE getPHANDLE();
	template <typename T> T Read(uintptr_t base, std::vector<unsigned int> offset);
	template <typename T> T Read(uintptr_t addr);
	template <typename T> BOOLEAN Write(uintptr_t base, std::vector<unsigned int> offset, T& value);
	template <typename T> BOOLEAN Write(uintptr_t addr, T& value);
	~Memory();

}
