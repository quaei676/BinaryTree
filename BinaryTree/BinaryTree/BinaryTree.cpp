// BinaryTree.cpp : 此檔案包含 'main' 函式。程式會於該處開始執行及結束執行。
//

#include <iostream>

struct Node
{
    Node* parent;
    Node* left;
    Node* right;
    int data;
    int index;
};
int BinarySearch(int *a, int startindex, int endindex, int searachnum)
{
    int middle = (startindex + endindex) >> 1;
    int *middle_num = a + middle;
    if (*middle_num == searachnum)
        return middle;
    else if (searachnum < *middle_num)
        return BinarySearch(a, startindex, middle - 1, searachnum);
    else if (searachnum > *middle_num)
        return BinarySearch(a, middle + 1, endindex, searachnum);

}
int BinaryTreeSearch(Node *root, int searachnum)
{
    try
    {
        if (root == nullptr) 
            throw std::exception("whoops! a nullptr!");
        if (root->data == searachnum)
            return root->index;
        if (root->data > searachnum)
            return BinaryTreeSearch(root->left, searachnum);
        if (root->data < searachnum)
            return BinaryTreeSearch(root->right, searachnum);
    }
    catch (...)
    {
        return -1;
    }
}

void SaveToTree(int *array, Node *root, int l, int r)
{
    int middle = (r + l) >> 1;
    int *middlenum = array + middle;
    root->data = *middlenum;
    root->index = middle;
    root->left = NULL;
    root->right = NULL;
    if (l == r)
        return;
    if (l <= (middle - 1))
    {
        root->left = new Node();
        root->left->parent = root;
        SaveToTree(array, root->left, l, middle - 1);
    }
    if(r >= (middle + 1))
    {
        root->right = new Node();
        root->right->parent = root;
        SaveToTree(array, root->right, middle + 1, r);
    }
}
void inorder_traversal(Node* p)
{
    if (!p) return;
    inorder_traversal(p->left);
    std::cout << p->data<<" ";
    inorder_traversal(p->right);
}
void preorder_traversal(Node* p)
{
    if (!p) return;
    std::cout << p->data << " ";
    preorder_traversal(p->left);
    preorder_traversal(p->right);
}
void postorder_traversal(Node* p)
{
    if (!p) return;
    postorder_traversal(p->left);
    postorder_traversal(p->right);
    std::cout << p->data << " ";
}

int main()
{
    int a[11] = {1,23,35,43,52,68,74,83,91,107,120};
    Node *root = new Node();
    root->parent = NULL;
    SaveToTree(a, root, 0, 10);
    inorder_traversal(root);
    std::cout << std::endl;
    preorder_traversal(root);
    std::cout << std::endl;
    postorder_traversal(root);
    std::cout << std::endl;
    int index = BinaryTreeSearch(root, 112);
    std::cout << "The number " << 112 << " is in index:" << index << std::endl;

    for (int i = 0; i < 10; i++)
    {
            index = BinaryTreeSearch(root, a[i]);
            std::cout << "The number " << a[i] << " is in index:" << index << std::endl;
    }
    std::cout << "Hello World!\n";
}

// 執行程式: Ctrl + F5 或 [偵錯] > [啟動但不偵錯] 功能表
// 偵錯程式: F5 或 [偵錯] > [啟動偵錯] 功能表

// 開始使用的提示: 
//   1. 使用 [方案總管] 視窗，新增/管理檔案
//   2. 使用 [Team Explorer] 視窗，連線到原始檔控制
//   3. 使用 [輸出] 視窗，參閱組建輸出與其他訊息
//   4. 使用 [錯誤清單] 視窗，檢視錯誤
//   5. 前往 [專案] > [新增項目]，建立新的程式碼檔案，或是前往 [專案] > [新增現有項目]，將現有程式碼檔案新增至專案
//   6. 之後要再次開啟此專案時，請前往 [檔案] > [開啟] > [專案]，然後選取 .sln 檔案
