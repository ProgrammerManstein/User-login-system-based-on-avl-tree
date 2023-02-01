#pragma once
#include<iostream>
#include<fstream>
#include<string>
using namespace std;
class UserInfo
{
public:
	inline string id() const { return myId; }
	inline void read(istream& in)
	{
		in >> myId >> myPassword;
	}
	inline void display(ostream& out)
	{
		out << myId << " " << myPassword;
	}
	inline bool operator==(const UserInfo& user)const
	{
		return myId == user.myId && myPassword == user.myPassword;
	}
	inline bool operator<(const UserInfo& user)const
	{
		return myId < user.myId || myId == user.myId && myPassword < user.myPassword;
	}
	inline bool operator>(const UserInfo& user)const
	{
		return myId > user.myId || myId == user.myId && myPassword > user.myPassword;
	}
	inline void setuser(string x,string y) {
		myId = x;
		myPassword = y;
	}

private:
	string myId;
	string myPassword;
};

inline istream& operator>>(istream& in, UserInfo& user)
{
	user.read(in);
	return in;
}

inline ostream& operator<<(ostream& out, UserInfo& user)
{
	user.display(out);
	return out;
}

inline string wstring2string(wstring wstr)
{
	string result;
	int len = WideCharToMultiByte(CP_ACP, 0, wstr.c_str(), wstr.size(), NULL, 0, NULL, NULL);
	char* buffer = new char[len + 1];
	WideCharToMultiByte(CP_ACP, 0, wstr.c_str(), wstr.size(), buffer, len, NULL, NULL);
	buffer[len] = '\0';
	result.append(buffer);
	delete[] buffer;
	return result;
}

