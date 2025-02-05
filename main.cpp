#include <iostream>

class treeNode
{
public:
    int value;
    bool init;
    treeNode* rightPtr;
    treeNode* leftPtr;

    treeNode(int passedValue, treeNode* nextRight, treeNode* nextLeft, bool initOrNot) : value{passedValue}, rightPtr{nextRight}, leftPtr{nextLeft}, init(initOrNot){};

    explicit treeNode(int passedValue) : value(passedValue), rightPtr{nullptr}, leftPtr{nullptr}, init(false){};
    treeNode() = default;
    ~treeNode() = default;

    static treeNode* searchValue(int insertedValue, treeNode* root)
    {
        if (root->value == insertedValue)
        {
            return root;
        }
        if (insertedValue <= root->value)
        {
            if (root->leftPtr != nullptr)
            {
                return searchValue(insertedValue, root->leftPtr);
            }
        }
        if (insertedValue > root->value)
        {
            if (root->rightPtr != nullptr)
            {
                return searchValue(insertedValue, root->rightPtr);
            }
        }
    }

    static void insertValue(int insertedValue, treeNode* root)
    {
        if (root->init == false)
        {
            root->value = insertedValue;
            root->init = true;
            return;
        }
        if (insertedValue > root->value)
        {
            if (root->rightPtr == nullptr)
            {
                return insertValue(insertedValue, root->rightPtr = new treeNode(0));
            }
            return insertValue(insertedValue, root->rightPtr);

        }
        if (root->leftPtr == nullptr)
        {
            return insertValue(insertedValue, root->leftPtr = new treeNode(0));
        }
        return insertValue(insertedValue, root->leftPtr);
    }
};

int main()
{
    auto* root = new treeNode(0);
    treeNode::insertValue(5,root);
    treeNode::insertValue(10, root);
    treeNode::insertValue(3, root);
    treeNode::insertValue(7, root);
    treeNode::insertValue(2, root);
    treeNode::insertValue(0, root);
    treeNode::insertValue(1, root);
    auto* foundValue = treeNode::searchValue(0, root);
;
}
