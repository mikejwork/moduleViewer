#include <iostream>
#include <Windows.h>
#include <TlHelp32.h>
#include <memory>
#include <string_view>
#include <cstdint>
#include <vector>
#include <Psapi.h>

bool listModules(DWORD pid);

int main() {
	DWORD processID;
	std::cout << "Enter a process id" << std::endl;
	std::cout << "> "; std::cin >> processID;

	if (listModules(processID)) {
		std::cout << "\n[/] Finished" << std::endl;

	}
	else {
		std::cout << "\n[?] Process ID Invalid" << std::endl;
	}

	do {
	} while (!GetKeyState(VK_INSERT));
	return NULL;

}

bool listModules(DWORD pid) {
	HMODULE hMods[1024];
	HANDLE hProcess;
	DWORD cbNeeded;
	unsigned int i;
	WCHAR szModName[MAX_PATH];
	hProcess = OpenProcess(PROCESS_QUERY_INFORMATION | PROCESS_VM_READ, FALSE, pid);

	if (hProcess == NULL) {
		std::cout << "Invalid Process" << std::endl;
	}

	if (EnumProcessModulesEx(hProcess, hMods, sizeof(hMods), &cbNeeded, LIST_MODULES_ALL)) {
		for (i = 0; i < (cbNeeded / sizeof(HMODULE)); i++) {
			if (GetModuleFileNameEx(hProcess, hMods[i], (LPSTR)szModName, sizeof(szModName) / sizeof(WCHAR))) {
				printf("%s\t(0x%08X)\n", szModName, hMods[i]);
			}
		}
	}
	CloseHandle(hProcess);
	return TRUE;
}