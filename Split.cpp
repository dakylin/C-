#include <string>
#include <vector>
#include <iostream>
#include <algorithm>

int _tmain(int argc, _TCHAR* argv[])
{
	std::wstring a = _T("a,bc,d");


	const TCHAR *S = _T(",");
	const TCHAR* P = a.c_str();

	std::vector<std::wstring> n;

	TCHAR * temp = const_cast<TCHAR*>(P);
	temp = wcstok(temp, S);
	while (temp)
	{
		n.push_back(temp);
		wprintf(_T("%s\n"), temp);
		temp = wcstok(NULL, S);
	}
	std::cout << "Start Vector" << std::endl;
	for (std::vector<std::wstring>::iterator it = n.begin(); it != n.end(); ++it)
	{
		std::wstring x = *it;
		wprintf(_T("%s\n"), it->c_str());
	}

	std::cout << "Use String" << std::endl;

	std::wstring a1 = _T("a,bc,d");

	std::vector<std::wstring> temp2;
	std::wstring::size_type pos1, pos2;
	const TCHAR schar = ',';
	pos2 = a1.find(schar);
	pos1 = 0;
	while (std::wstring::npos != pos2)
	{
		temp2.push_back(a1.substr(pos1, pos2 - pos1));

		pos1 = pos2 + 1;
		pos2 = a1.find(schar, pos1);
	}
	temp2.push_back(a1.substr(pos1));
	for (std::vector<std::wstring>::iterator it = temp2.begin(); it != temp2.end(); ++it)
	{
		wprintf(_T("%s\n"), it->c_str());
	}

	std::cout << "Find a:";
	std::vector<std::wstring>::iterator result = std::find(temp2.begin(), temp2.end(), _T("a"));
	if (result != temp2.end())
	{
		std::cout << "Find" << std::endl;
	}
	else
	{
		std::cout << "Cannot Find" << std::endl;
	}

	std::cout << "Find b:";
	result = std::find(temp2.begin(), temp2.end(), _T("b"));
	if (result != temp2.end())
	{
		std::cout << "Find" << std::endl;
	}
	else
	{
		std::cout << "Cannot Find" << std::endl;
	}

	return 0;
}