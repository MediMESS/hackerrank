#include <iostream>

using namespace std;
class Node
{
public:
    char c;
    Node *next;

    Node(char character)
    {
        c = character;
        next = NULL;
    }
};

class Solution
{

public:
    Node *queue = NULL;
    Node *tailQueue = NULL;
    Node *stack = NULL;

    bool isEmpty(Node *node)
    {
        return node == NULL;
    }
    Node *createElement(char c)
    {
        Node *el = new Node(c);
        return el;
    }

    char removeFirstElement(Node *node)
    {
        char c = node->c;
        node = node->next;
        return c;
    }

    // Push in the stack
    void enqueueCharacter(char c)
    {
        Node *el = createElement(c);
        if (isEmpty(queue))
        {
            queue = el;
            tailQueue = queue;
        }
        else
        {
            tailQueue->next = el;
            tailQueue = el;
        }
    }

    void pushCharacter(char c)
    {
        Node *el = createElement(c);

        if (isEmpty(stack))
        {
            stack = createElement(c);
        }
        else
        {
            el->next = stack;
            stack = el;
        }
    }
    char dequeueCharacter()
    {
        return removeFirstElement(queue);
    }
    char popCharacter()
    {
        return removeFirstElement(stack);
    }
};

int main()
{
    // read the string s.
    string s;
    getline(cin, s);

    // create the Solution class object p.
    Solution obj;

    // push/enqueue all the characters of string s to stack.
    for (int i = 0; i < s.length(); i++)
    {
        obj.pushCharacter(s[i]);
        obj.enqueueCharacter(s[i]);
    }

    bool isPalindrome = true;

    // pop the top character from stack.
    // dequeue the first character from queue.
    // compare both the characters.
    for (int i = 0; i < s.length() / 2; i++)
    {
        if (obj.popCharacter() != obj.dequeueCharacter())
        {
            isPalindrome = false;

            break;
        }
    }

    // finally print whether string s is palindrome or not.
    if (isPalindrome)
    {
        cout << "The word, " << s << ", is a palindrome.";
    }
    else
    {
        cout << "The word, " << s << ", is not a palindrome.";
    }

    return 0;
}