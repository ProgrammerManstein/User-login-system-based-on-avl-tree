#pragma once

#include <afxstr.h>
#include<string>
#include"UserInfo.h"
#include"BST.h"
static CString myidnow;
static CString mypasswordnow;
static ifstream inStream("userinformation.txt");
//static ofstream outStream("userinformation.txt");
static BST<UserInfo> userTree;
static string stridnow;
static string strpasswordnow;