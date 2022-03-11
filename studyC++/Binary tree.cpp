#include<iostream>
#include<vector>
using namespace std;

template<class T>
class Node {
public:
	T data;
	Node<T>* left;
	Node<T>* right;

	Node() {
		data = {};
		left = nullptr;
		right = nullptr;
	}
	Node(T data) {
		this->data = data;
		left = nullptr;
		right = nullptr;
	}
};

template<class T>
class BinarySearchTree{
	Node<T>* root;
	//从右子树中寻找最小值节点,如果最小值节点有左子节点,则继续在左子节点的子节点找最大值
	//Node<T>* findReplaceNode(Node<T>* node) {
	//	static Node<T>* result;//最终的节点
	//	static Node<T>* root_temp;最终节点的父节点
	//	if (node == nullptr) {
	//		return result;
	//	}
	//	else {
	//		if (node->left != nullptr) {
	//			findReplaceNode(node->left);
	//		}
	//	}

	//}
public:
	//生成空树
	BinarySearchTree() {}
	//生成根节点
	BinarySearchTree(T data) {
		root = new Node<T>(data);
	}
	//根据数组生成二叉搜索树
	BinarySearchTree(T ary[], int length) {
		root = new Node<T>(ary[0]);
		for (int n{1}; n < length; n++) {
			//insert(new Node<T>(ary[n])); //--非递归
			insert(root, ary[n]);
		}
	}
	//插入节点--非递归
	/*
	void insert(Node<T>* node) {
		Node<T>* temp;
		temp = this->root;
		//从root开始
		//不是空，则进入节点，继续朝下判断
		//如果数值大于此节点数值，则进入右节点，反之左节点
		while (temp != nullptr) {//此节点不为空
			if (node->data > temp->data) {//---------------准备进入下一个节点,右
				if (temp->right != nullptr) {//下一个节点不为空
					temp = temp->right;//进入下一个节点
				}
				else {//为空，放入，结束函数
					temp->right = node;
					return;
				}
			}
			else {//----------------------------------------准备进入下一个节点,左
				if (temp->left != nullptr) {//下一个节点不为空
					temp = temp->left;//进入下一个节点
				}
				else {//为空，放入，结束函数
					temp->left = node;
					return;
				}
			}
		}
		root = node;//第一个就为空的话就直接放入
	}
	*/
	//插入节点
	void insert(Node<T>* node,T data) {
		if (data < node->data) {
			if (node->left != nullptr) {
				insert(node->left, data);
			}
			else {
				node->left = new Node<T>(data);
			}
		}
		else {
			if (node->right!= nullptr) {
				insert(node->right, data);
			}
			else {
				node->right = new Node<T>(data);
			}
		}
	}
	//获取根节点
	Node<T>* getRoot() {
		return root;
	}
	//获取根节点,伪函数形式
	Node<T>* operator() () {
		return root;
	}
	//查找最值并返回节点--真为最大，假为最小--非递归写法
	/*Node<T>* findNodeMax(bool isMax = true) {
		Node<T>* temp = root;
		if (isMax) {
			while (temp->right != nullptr) {
				temp = temp->right;
			}
		}
		else {
			while (temp->left != nullptr) {
				temp = temp->left;
			}
		}
		return temp;
	}*/
	//查找最值并返回节点--真为最大，假为最小
	Node<T>* findNodeMax(Node<T>* node, bool isMax = true) {
		if (isMax) {
			if (node->right != nullptr) {
				return findNodeMax(node->right, isMax);
			}
		}
		else {
			if (node->left != nullptr) {
				return findNodeMax(node->left, isMax);
			}
		}
	}
	//查找节点并返回节点--非递归写法
	/*Node<T>* findNode(T data) {
		Node<T>* temp = root;
		while (temp != nullptr) {
			if (data == temp->data) {
				return temp;
			}
			else if (data < temp->data) {
				temp = temp->left;
			}
			else {
				temp = temp->right;
			}
		}
		return nullptr;
	}*/
	//查找数据并返回节点
	Node<T>* findNode(Node<T>* node,T data) {
		if (node == nullptr) {
			return nullptr;
		}
		else if (data == node->data) {
			return node;
		}
		else if(data < node->data) {
			findNode(node->left, data);
		}
		else {
			findNode(node->right, data);
		}
	}
	//根据数据删除节点
	//void delNode(Node<T>* node, T data) {
	//	static Node<T>* root_temp = new Node<T>();	//保存要删除的节点的父节点
	//	static bool isLeft;							//是在 要删除的节点的父节点 的左边还是右边

	//	if (node == nullptr) {
	//		return;
	//	}
	//	else {
	//		if (node->data != data) {//寻找阶段
	//			if (node->left->data == data) {//预判操作，将删除节点的父节点保存下来
	//				root_temp = node->left;
	//				isLeft = true;//左节点的数据符合，即将删除
	//			}
	//			else if (node->right->data = data) {
	//				root_temp = node->right;
	//				isLeft = false;//右节点数据符合，即将删除
	//			}

	//			if (data < node->data) {
	//				delNode(node->left, data);
	//			}
	//			else if (data > node->data) {
	//				delNode(node->right, data);
	//			}
	//			
	//		}
	//		else {//执行阶段
	//			
	//			if (node->left == nullptr && node->right == nullptr) {//第一种情况
	//				delete node;
	//			}
	//			else if (//第二种情况
	//						(node->left != nullptr && node->right == nullptr) ||
	//						(node->left == nullptr && node->right != nullptr)
	//					) {
	//				if (isLeft) {
	//					root_temp->left = node->left != nullptr ? node->left : node->right;//总有一个不为空
	//				}
	//				else {
	//					root_temp->right = node->left != nullptr ? node->left : node->right;//总有一个不为空
	//				}
	//				delete node;
	//			}
	//			else {//第三种情况，都有 -- 从右子树寻找最小值,如果右子树有左子树，则再从左子树找最大值
	//				Node<T>* replaceN = findReplaceNode(node);
	//				

	//			}
	//		}
	//	}
	//}
	//获取此树的高度--非递归写法
	/*int getHeight() {
		Node<T>* temp = root;
		int lH{}, rH{};
		while (temp->left != nullptr) {
			temp = temp->left;
			lH++;
		}
		while (temp->right != nullptr) {
			temp = temp->right;
			rH++;
		}
		return (lH > rH ? lH : rH)+1;
	}*/
	//获取此树的高度
	int getHeight(Node<T>* node) {
		if (node != nullptr) {
			int lH = getHeight(node->left);
			int rH = getHeight(node->right);
			int max = lH;
			if (rH > max) {
				max = rH;
			}
			return max + 1;
		}
		else {
			return 0;
		}
	}
	//先序遍历
	vector<T> preOrder(Node<T>* node) {
		static vector<T> resultSet;
		if (node != nullptr) {
			resultSet.push_back(node->data);
			preOrder(node->left);
			preOrder(node->right);
		}
		return resultSet;
	}
	//先序遍历--非递归
	/*vector<T> preOrder(Node<T>* node) {

	}*/
	//中序遍历
	vector<T> inOrder(Node<T>* node) {
		static vector<T> resultSet;
		if (node != nullptr) {
			inOrder(node->left);
			resultSet.push_back(node->data);
			inOrder(node->right);
		}
		return resultSet;
	}

};


//int main() {
//	const int length = 6;
//	int arr[length] = { 6,5,4,3,2,1 };
//	BinarySearchTree<int> bst(arr, length);
//	vector<int> result1 = bst.preOrder(bst.getRoot());
//	vector<int> result2 = bst.inOrder(bst.getRoot());
//
//	for (int n : result1) {
//		cout << n << " ";
//	}
//	cout << endl;
//	for (int n : result2) {
//		cout << n << " ";
//	}
//
//	cout << "------" << endl;
//	cout << bst.findNodeMax(bst())->data << endl;;
//
//	return 0;
//}