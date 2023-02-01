#pragma once
#include<iostream>
#include <iomanip>
#include<queue>
using namespace std;
template<typename DataType>
class BST
{
public:
	BST();
	BST(DataType x[], int n)
	{
		for (int i = 0;i < n;i++)
		{
			this->insert(x[i]);
		}
	}
	~BST()
	{
		erase(myRoot);
	}

	bool empty()const;
	void inoder(ostream& out)const
	{
		inorderAux(out, myRoot);
	}
	void inoderLVR(ostream& out)const
	{
		inorderAuxLVR(out, myRoot);
		out << endl;
	}
	void inoderVLR(ostream& out)const
	{
		inorderAuxVLR(out, myRoot);
		out << endl;
	}
	void inoderLRV(ostream& out)const
	{
		inorderAuxLRV(out, myRoot);
		out << endl;
	}
	void graph(ostream& out)const
	{
		graphAux(out, 0, myRoot);
	}
	void insert(const DataType& item);
	void remove(const DataType& item);
	bool search(const DataType& item)const;
private:
	class BinNode
	{
	public:
		DataType data;
		BinNode* left;
		BinNode* right;
		BinNode() :left(0), right(0) {}
		BinNode(DataType item) :data(item), left(0), right(0) {}
	};
	BinNode* myRoot;
	void inorderAux(ostream& out, BST<DataType>::BinNode* subtreeRoot)const;
	void inorderAuxLVR(ostream& out, BST<DataType>::BinNode* subtreeRoot)const;
	void inorderAuxVLR(ostream& out, BST<DataType>::BinNode* subtreeRoot)const;
	void inorderAuxLRV(ostream& out, BST<DataType>::BinNode* subtreeRoot)const;
	void graphAux(ostream& out, int indent, BST<DataType>::BinNode* subtreeRoot)const;
	bool searchAux(BST<DataType>::BinNode* subtreeRoot, const DataType& item)const;
	void search2(const DataType& item, bool& found, BinNode* locptr, BinNode* parent)const;
	void erase(BST<DataType>::BinNode* subtreeRoot)
	{
		if (subtreeRoot != 0)
		{
			erase(subtreeRoot->left);
			erase(subtreeRoot->right);
			delete subtreeRoot;
		}

	}
	BinNode* RAdjest(BST<DataType>::BinNode* subtreeRoot);
	BinNode* LAdjest(BST<DataType>::BinNode* subtreeRoot);
	BinNode* LRAdjest(BST<DataType>::BinNode* subtreeRoot);
	BinNode* RLAdjest(BST<DataType>::BinNode* subtreeRoot);
	BinNode* insert(BinNode* subtreeRoot, const DataType& item);
	BinNode* remove(BinNode* subtreeRoot, const DataType& item);
	int BalanceFactor(BST<DataType>::BinNode* subtreeRoot)
	{
		return Height(subtreeRoot->left) - Height(subtreeRoot->right);
	}
	int Height(BST<DataType>::BinNode* p);
	BinNode* Balance(BST<DataType>::BinNode* subtreeRoot);
	BinNode* TreeMax(BST<DataType>::BinNode* subtreeRoot) {
		if (!subtreeRoot)
			return NULL;
		while (subtreeRoot->right) {
			subtreeRoot = subtreeRoot->right;
		}
		return subtreeRoot;
	}

	BinNode* TreeMin(BST<DataType>::BinNode* subtreeRoot) {
		if (!subtreeRoot)
			return NULL;
		while (subtreeRoot->left) {
			subtreeRoot = subtreeRoot->left;
		}
		return subtreeRoot;
	}
};

template<typename DataType>
int BST<DataType>::Height(BST<DataType>::BinNode* p) {
	if (p == NULL)
		return 0;
	int i = Height(p->left);
	int j = Height(p->right);
	return i > j ? i + 1 : j + 1;
}

template<typename DataType>
inline BST<DataType>::BST()
	:myRoot(0) {}

template<typename DataType>
inline bool BST<DataType>::empty() const
{
	return myRoot == 0;
}

template<typename DataType>
void BST<DataType>::inorderAux(ostream& out, BST<DataType>::BinNode* subtreePtr)const
{
	queue<BinNode*> s;
	BinNode* root = myRoot;
	s.push(root);
	while (!s.empty()) {
		root = s.front();
		cout << root->data << " ";
		s.pop();
		if (root->left != 0)
			s.push(root->left);
		if (root->right != 0)
			s.push(root->right);
	}
	cout << endl;
}

template<typename DataType>
void BST<DataType>::inorderAuxLVR(ostream& out, BST<DataType>::BinNode* subtreeRoot)const
{
	if (subtreeRoot != 0)
	{
		inorderAuxLVR(out, subtreeRoot->left);
		out << subtreeRoot->data <<endl;
		inorderAuxLVR(out, subtreeRoot->right);
	}
}

template<typename DataType>
void BST<DataType>::inorderAuxVLR(ostream& out, BST<DataType>::BinNode* subtreeRoot)const
{
	if (subtreeRoot != 0)
	{
		out << subtreeRoot->data << " ";
		inorderAuxVLR(out, subtreeRoot->left);
		inorderAuxVLR(out, subtreeRoot->right);
	}
}

template<typename DataType>
void BST<DataType>::inorderAuxLRV(ostream& out, BST<DataType>::BinNode* subtreeRoot)const
{
	if (subtreeRoot != 0)
	{
		inorderAuxLRV(out, subtreeRoot->left);
		inorderAuxLRV(out, subtreeRoot->right);
		out << subtreeRoot->data <<endl;
	}
}

template<typename DataType>
void BST<DataType>::graphAux(ostream& out, int indent, BinNode* subtreeRoot)const
{
	if (subtreeRoot != 0)
	{
		graphAux(out, indent + 8, subtreeRoot->right);
		out << setw(indent) << " " << subtreeRoot->data << endl;
		graphAux(out, indent + 8, subtreeRoot->left);
	}
}

template<typename DataType>
void BST<DataType>::insert(const DataType& item)
{
	myRoot = insert(myRoot, item);
}

template<typename DataType>
typename BST<DataType>::BinNode* BST<DataType>::insert(BinNode* subtreeRoot, const DataType& item)
{
	if (subtreeRoot == NULL) {
		subtreeRoot = new BinNode(item);
	}
	else if (item > subtreeRoot->data)
	{
		subtreeRoot->right = insert(subtreeRoot->right, item);
		subtreeRoot = Balance(subtreeRoot);
	}
	else if (item < subtreeRoot->data)
	{
		subtreeRoot->left = insert(subtreeRoot->left, item);
		subtreeRoot = Balance(subtreeRoot);
	}
	return subtreeRoot;
}

template<typename DataType>
void BST<DataType>::remove(const DataType& item)
{
	myRoot = remove(myRoot, item);
}

template<typename DataType>
typename BST<DataType>::BinNode* BST<DataType>::remove(BinNode* subtreeRoot, const DataType& item)
{
	if (!search(item)) {
		return myRoot;
	}
	if (!myRoot)
		return myRoot;
	if (subtreeRoot->data == item)
	{
		if (subtreeRoot->left && subtreeRoot->right) {
			if (BalanceFactor(subtreeRoot) > 0) {
				BinNode* p = TreeMax(subtreeRoot->left);
				subtreeRoot->data = p->data;
				subtreeRoot->left = remove(subtreeRoot->left, p->data);
			}
			else {
				BinNode* p = TreeMin(subtreeRoot->right);
				subtreeRoot->data = p->data;
				subtreeRoot->right = remove(subtreeRoot->right, p->data);
			}
		}
		else {
			BinNode* p = subtreeRoot;
			subtreeRoot = (subtreeRoot->right) ? (subtreeRoot->right) : (subtreeRoot->left);
			delete p;
			p = nullptr;
		}
	}
	else if (item < subtreeRoot->data) {
		subtreeRoot->left = remove(subtreeRoot->left, item);
		if (BalanceFactor(subtreeRoot) < -1)
			subtreeRoot = Balance(myRoot);
	}
	else {
		subtreeRoot->right = remove(subtreeRoot->right, item);
		if (BalanceFactor(subtreeRoot) > 1)
			subtreeRoot = Balance(myRoot);
	}
	return subtreeRoot;
}

template <class DataType>
void BST<DataType>::search2(const DataType& item, bool& found, BinNode* locptr, BinNode* parent)const
{
	locptr = myRoot;
	parent = 0;
	found = false;
	while (!found && locptr != 0)
	{
		if (item < locptr->data)
		{
			parent = locptr;
			locptr = locptr->left;
		}
		else if (item > locptr->data)
		{
			parent = locptr;
			locptr = locptr->right;
		}
		else
			found = true;
	}
}
template <class DataType>
bool BST<DataType>::search(const DataType& item)const
{
	return searchAux(myRoot, item);
}
template <class DataType>
bool BST<DataType>::searchAux(BST<DataType>::BinNode* subtreeRoot, const DataType& item)const
{
	if (subtreeRoot == 0)
		return false;
	if (item < subtreeRoot->data)
		return searchAux(subtreeRoot->left, item);
	else if (item > subtreeRoot->data)
		return searchAux(subtreeRoot->right, item);
	else
		return true;
}
template <class DataType>
typename BST<DataType>::BinNode* BST<DataType>::RAdjest(BST<DataType>::BinNode* subtreeRoot)
{
	if (subtreeRoot == nullptr)
		return subtreeRoot;
	BinNode* p = subtreeRoot->left;
	subtreeRoot->left = p->right;
	p->right = subtreeRoot;
	return p;
}
template <class DataType>
typename BST<DataType>::BinNode* BST<DataType>::LAdjest(BST<DataType>::BinNode* subtreeRoot)
{
	if (subtreeRoot == nullptr)
		return subtreeRoot;
	BinNode* p = subtreeRoot->right;
	subtreeRoot->right = p->left;
	p->left = subtreeRoot;
	return p;
}
template <class DataType>
typename BST<DataType>::BinNode* BST<DataType>::LRAdjest(BST<DataType>::BinNode* subtreeRoot)
{
	subtreeRoot->left = LAdjest(subtreeRoot->left);
	return RAdjest(subtreeRoot);
}
template <class DataType>
typename BST<DataType>::BinNode* BST<DataType>::RLAdjest(BST<DataType>::BinNode* subtreeRoot)
{
	subtreeRoot->right = RAdjest(subtreeRoot->right);
	return LAdjest(subtreeRoot);
}
template <class DataType>
typename BST<DataType>::BinNode* BST<DataType>::Balance(BST<DataType>::BinNode* subtreeRoot)
{
	int bf = BalanceFactor(subtreeRoot);
	if (bf > 1)
	{
		if (BalanceFactor(subtreeRoot->left) > 0)
			subtreeRoot = RAdjest(subtreeRoot);
		else
			subtreeRoot = LRAdjest(subtreeRoot);
	}
	else if (bf < -1)
	{
		if (BalanceFactor(subtreeRoot->right) > 0)
			subtreeRoot = RLAdjest(subtreeRoot);
		else
			subtreeRoot = LAdjest(subtreeRoot);
	}
	return subtreeRoot;
}
#pragma once
