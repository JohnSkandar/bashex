// bashex.cpp : Defines the entry point for the console application.
//
// Bash Extended call utility for WSL
// 
// Usage: bashex.exe linux_command arguments
// (arguments with spaces must be put between " ")
// 
// Calls bash.exe -c "linux_command arguments"
// where arguments that are paths are translated to Linux paths and put between ' '
//

#include "stdafx.h"

int wmain(int argc, wchar_t *argv[])
{
	if (argc <= 2)
	{
		wprintf(L"Missing arguments");
		return 1;
	}

	CString out_command = L"C:\\Windows\\Sysnative\\bash.exe -c \"" + CString(argv[1]);

	for (int i = 2; i < argc; i++)
	{
		CString cmd(argv[i]);
		// files in the working directory (beginning with ".\")
		if (cmd.GetLength() >= 2 && cmd.Left(2).Compare(L".\\") == 0)
		{
			// path is translated to "./..."
			cmd.Replace(L"\\", L"/");
			cmd = L"'" + cmd + L"'";
		}
		// files in other directories (beginning with "drive:\")
		else if (cmd.GetLength() >= 3 && iswalpha(cmd[0]) && cmd.Mid(1, 2).Compare(L":\\") == 0)
		{
			// path is translated to "/mnt/drive/..."
			cmd.Format(L"'/mnt/%s/%s'", cmd.Left(1).MakeLower(), cmd.Right(cmd.GetLength() - 3));
			cmd.Replace(L"\\", L"/");
		}
		out_command += L" " + cmd;
	}

	out_command += L"\"";
	wprintf(out_command);
	_wsystem(out_command);
	return 0;
}