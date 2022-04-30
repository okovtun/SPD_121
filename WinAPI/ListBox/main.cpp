#define _CRT_SECURE_NO_WARNINGS
#include<Windows.h>
#include<cstdio>
#include"resource.h"

CONST CHAR* string[] = { "This", "is", "my", "first", "List", "Box", "1024", "128" };

BOOL CALLBACK DlgProc(HWND hwnd, UINT uMsg, WPARAM wParam, LPARAM lParam);

INT WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInst, LPSTR lpCmdLine, int nCmdShow)
{
	DialogBoxParam(hInstance, MAKEINTRESOURCE(IDD_DIALOG1), 0, DlgProc, 0);
	return 0;
}

BOOL CALLBACK DlgProc(HWND hwnd, UINT uMsg, WPARAM wParam, LPARAM lParam)
{
	switch (uMsg)
	{
	case WM_INITDIALOG:
	{
		HWND hListBox = GetDlgItem(hwnd, IDC_LIST1);
		for (int i = 0; i < sizeof(string) / sizeof(string[0]); i++)
		{
			SendMessage(hListBox, LB_ADDSTRING, 0, (LPARAM)string[i]);
		}
		SendMessage(hListBox, LB_SETCURSEL, 4, 0);
	}
	break;
	case WM_COMMAND:
		switch (LOWORD(wParam))
		{
		case IDC_CHECK_SORT:
		{
			/*if (HIWORD(wParam) == BST_CHECKED)
			{
				MessageBox(hwnd, "Checkbox ����������", "Info", MB_OK);
			}
			else if (HIWORD(wParam) == BST_UNCHECKED)
			{
				MessageBox(hwnd, "Checkbox �������", "Info", MB_OK);
			}*/
			HWND hList = GetDlgItem(hwnd, IDC_LIST1);
			DWORD dwStyle = GetWindowLong(hList, GWL_STYLE);
			if (SendMessage(GetDlgItem(hwnd, IDC_CHECK_SORT), BM_GETCHECK, 0, 0) == BST_CHECKED)
			{
				//MessageBox(hwnd, "Checkbox ����������", "Info", MB_OK);
				MessageBox(hwnd, "���������� ��������", "Info", MB_OK);
				SetWindowLong(hList, GWL_STYLE, dwStyle | LBS_SORT);
			}
			if (SendMessage(GetDlgItem(hwnd, IDC_CHECK_SORT), BM_GETCHECK, 0, 0) == BST_UNCHECKED)
			{
				//MessageBox(hwnd, "Checkbox �������", "Info", MB_OK);
				MessageBox(hwnd, "���������� ���������", "Info", MB_OK);
				dwStyle -= LBS_SORT;
				SetWindowLong(hList, GWL_STYLE, dwStyle);
			}

		}
		break;
		case IDC_BUTTON_ADD:
		{
			DialogBoxParam(GetModuleHandle(NULL), MAKEINTRESOURCE(IDD_DIALOG_ADD), hwnd, DlgProc, 0);
		}
		break;
		case IDOK_ADD:
		{
			CONST INT SIZE = 256;
			CHAR sz_buffer[SIZE] = {};
			HWND hEdit = GetDlgItem(hwnd, IDC_EDIT1);
			SendMessage(hEdit, WM_GETTEXT, SIZE, (LPARAM)sz_buffer);
			HWND parent = GetParent(hwnd);
			HWND hList1 = GetDlgItem(parent, IDC_LIST1);
			SendMessage(hList1, LB_ADDSTRING, 0, (LPARAM)sz_buffer);
			EndDialog(hwnd, 0);
		}
		break;
		case IDOK:
		{
			CONST INT SIZE = 256;
			CHAR sz_buffer[SIZE] = {};
			HWND hListBox = GetDlgItem(hwnd, IDC_LIST1);
			int i = SendMessage(hListBox, LB_GETCURSEL, 0, 0);
			SendMessage(hListBox, LB_GETTEXT, i, (LPARAM)sz_buffer);
			CHAR sz_msg[SIZE] = {};
			sprintf(sz_msg, "�� ������� ������� � %d, �� ��������� %s", i, sz_buffer);
			MessageBox(hwnd, sz_msg, "Info", MB_OK | MB_ICONINFORMATION);
		}
		break;
		case IDCANCEL:EndDialog(hwnd, 0); break;
		}
		break;
	case WM_CLOSE:EndDialog(hwnd, 0);
	}
	return FALSE;
}