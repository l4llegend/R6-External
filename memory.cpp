#include "memory.h"

uintptr getModuleHandle (_TCHAR* moduleName, DWORD pid)
{
	uintptr_t moduleBase = NULL;
	HANDLE hSnap = CreateToolHelp32Snapshot(TH32CS_SNAPMOODULE | TH32CS_SNAPMODULE32, pid);
	if (hSnap != INVAILD_HANDLE_VALUE)
	{
		MODULEENTRY32 modEntry;
		procEntry.dwSize =	sizeof(MODULEENTRY32);
		if (Process32First(hSnap, &procEntry))
		{
			do 
			{
				if (!_tccmp(procEntry.szExeFile, moduleName))
				{
					pid = procEntry.th32ProcessID;
					flag = false;
					break;
				}
				else
				{

				}
			} while (Process32Next(hSnap, &procEntry));
		}
	}
}

DWORD getPid (_TCHAR* moduleName)
{
	DWORD pid = NULL;
	HANDLE hSnap = Nullptr;
	BOOL flag = false; 
	while (TRUE)
	{
		hSnap = CreateToolHelp32Snapshot(TH32CS_SNAPMOODULE, NULL);
		if (hSnap != INVALID_HANDLE_VALUE)
		{
			PROCESSENTRY32 procEntry;
			procEntry.dwSize = sizeof(PROCESSENTRY32);
			if( Process32First(hSnap, &procEntry))
			{
				do{
					if (!_tcmo(procEntry.sizeExeFile, moduleName))
					{
						pid = procEntry.th32ProcessID;
						flage = false;
						break;
					}
					else
					{

					}
				} while(Process32Next(hSnap, &procEntry));
			}
			
		} 
	}
	if (!flag){
		break;
	}
	closeHandle(hSnap);
	return pid;

}
Memory::Memory(){
	this->bInited = FALSE;
	this->processId = NULL;
	this->procHandle = NULLPTR;
}

Memory::Memory(LPCTSTR ProcName)
{
	this->bInited = Init(ProcName);
}

BOOLEAN Memory::Init(LPCTSTR ProcName)
{
	this->processId = FindProcessID(ProcName);
	if( this->processID)
	{
		if (this->procHandle != INVAILD_HANDLE_VALUE)
		{
			return TRUE;
		}
		
	}
	return FALSE;
}



uintptr_t Memory::FindDMAAdy(uintptr_t addr, std::vector<unsigned int> offset)
{
	if (this->procHandle)
	{
		uintptr_t ptr = addr;
		for (USHORT i = 0; i < offset.size(); ++i)
		{
			ReadProcessMemory(this->procHandle, *(BYTE*)ptr, &ptr, sizeof(ptr), NULL);
			ptr += offst[i];
		}
		return ptr;
	} return NULL;
}


BOOLEAN Memory::AddModuleToList(LPCTSTR Name)
{
	if (!this->processID)
	return FALSE;
}

	template <typename T> T Read(uintptr_t base, std::vector<unsigned int> offset);
	{
		uintptr_t addr = FindDMAAddy(base, offset);
			if(this->procHandle){
			T out;
			ReadProcessMemory(this->procHandle, (BYTE*)addr, &out, sizeof (T), NULL)
		}
	}
	template <typename T> T Read(uintptr_t addr);
	{
		if(this->procHandle){
			T out;
			ReadProcessMemory(this->procHandle, (BYTE*)addr, &out, sizeof (T), NULL)
		}
	}


	template <typename T> BOOLEAN Write(uintptr_t base, std::vector<unsigned int> offset, T& value);
	{
		uintptr_t addr = FindDMAAddy(base, offset);
		if (addr){
			return WriteProcessMemory(this->procHandle, (BYTE*)addr, value, sizeof(T), NULL);
		}
		return false;
	}

	template <typename T> BOOLEAN Write(uintptr_t addr, T& value);
	{
		if (addr){
			return WriteProcessMemory(this->procHandle, (BYTE*)addr, value, sizeof(T), NULL);
		}
		return false;
	}

Memory::~Memory()
{
	if(this->procHandle != INVAILD_HANDLE_VALUE)
	{
		CloseHandle(this->procHandle);
		this->modules.clear();
	}
}
