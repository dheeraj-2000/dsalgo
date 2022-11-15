// IMP!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
//  NOTE: ONLY ADD LOWERCASE CHARACTERS IN THE TRIE !!!!-----------------------------------
//  because I am calculating the index using the ascii values of lowercase letters, make sure to add lower case characters for it to work

#include <bits/stdc++.h>
using namespace std;

// structure for each node of trie
// it consists of the data in char, a boolean data type to check if the word ends at that particular node or not and an array of pointers of struct node type to hold its children
struct node
{
    char data;
    int word_end;
    struct node *children[26];
};
struct node *create_node()
{
    struct node *new_node = new node();
    int i = 0;
    for (int i = 0; i < 26; i++)
    {
        new_node->children[i] = NULL; // making sure each child is null for conditional checking
    }
    return new_node;
}
struct node *insert(node *root, string data)
{
    struct node *ptr = root;
    int i = 0;
    while (i < data.length())
    {
        // checking if it contains address or not, if it does not that means that character       does not exist and we need to create a node and add its address in the children array
        if (ptr->children[int(data[i]) - 97] == NULL)
        {
            struct node *new_node = create_node();
            ptr->children[int(data[i]) - 97] = new_node;
            new_node->data = data[i];
        }
        // once we reach the end of the string we increment the word_end of the last added node by 1 indicating that it contains a word which ends at this node
        if (i == data.length() - 1)
            ptr->children[int(data[i]) - 97]->word_end += 1;
        ptr = ptr->children[int(data[i] - 97)];
        i++;
    }
    cout << "string was inserted successfully!" << endl;
    return root;
}
bool search(struct node *root, string data)
{
    cout << endl;
    struct node *ptr = root;
    int i = 0;
    while (i < data.length())
    {
        // if the index of the string to be added is null,that means the character does not exist hence we return false
        if (ptr->children[int(data[i]) - 97] == NULL)
        {
            cout << "string doesn't exist" << endl;
            return false;
        }
        if (i == data.length() - 1)
        {
            // we check if we have reached the end of the string to be searched and if that node contains a word_end or not, if it doesnt that means that the trie does not contain that word
            if (ptr->children[int(data[i]) - 97]->word_end)
            {
                cout << "String was found!" << endl;
                return true;
            }
            else
            {
                cout << "String doesn't exist " << endl;
                return false;
            }
        }
        ptr = ptr->children[int(data[i]) - 97];
        i++;
    }
    cout << endl;
}
void printAllStrings(struct node *root, string s)
{
    if (root == NULL)
    {
        return;
    }
    // we check for each child in the array of every node and if it contains an adress(if it's not NULL that is) we recursively go deeper and append the data into a string untill we reach null, if we reach null then we come back and check if that node contains a word_end or not, if it does we print the string and then we pop the last added character(backtracking).
    for (int i = 0; i < 26; i++)
    {
        if (root != NULL && root->children[i] != NULL)
        {
            s += root->children[i]->data;
            printAllStrings(root->children[i], s); // go deeper into that node
            if (root->children[i]->word_end)
                cout << s << endl;
            s.pop_back();
        }
    }
}
struct node *delete_string(struct node *root, string s)
{
    cout << endl;
    if (search(root, s)) // we first check if the string exists or not
    {
        cout << "deleting string  : " << s << "..." << endl;
        int i = 0;
        struct node *ptr = root;
        // if the string exist we go deeper into the trie untill we hit the word_end only at the s.length()-1 index and then we decrement the value of the word_end
        while (i < s.length())
        {

            if (i == s.length() - 1)
                ptr->children[int(s[i]) - 97]->word_end--;
            ptr = ptr->children[int(s[i]) - 97];
            i++;
        }
        cout << "string deleted succesfully!" << endl;
        cout << endl;
    }
    return root;
}
// menu driven program
void menu()
{
    bool exit = false;
    struct node *root = create_node();
    cout << "Trie Manipulation" << endl;
    while (!exit)
    {
        cout << "1)Insert\n2)Search\n3)Print All strings\n4)delete\n5)exit" << endl;
        int n;
        cin >> n;
        string s;
        switch (n)
        {
            // case usually does not require braces around it but for some reason it was giving a compile time error "transfer of control bypasses intitialization of:" so after searching on stack overflow, I added the braces
        case 1:
        {
            bool stop = false;
            while (!stop)
            {
                cout << "Enter String to be inserted" << endl;
                cin >> s;
                insert(root, s);
                cout << "continue ?" << endl;
                int a;
                cin >> a;
                if (!a)
                    stop = true;
            }
            break;
        }
        case 2:
        {
            bool stop = false;

            while (!stop)
            {
                cout << "Enter string to be searched" << endl;
                cin >> s;
                search(root, s);
                cout << "continue ?" << endl;
                int a;
                cin >> a;
                if (!a)
                    stop = true;
            }
            break;
        }
        case 3:
        {
            cout << "Strings in the Trie are : " << endl;
            cout << endl;
            printAllStrings(root, "");
            cout << endl;
            break;
        }
        case 4:
        {
            bool stop = false;
            while (!stop)
            {
                cout << "Enter string to be deleted" << endl;
                cin >> s;
                root = delete_string(root, s);
                cout << "continue?" << endl;
                int a;
                cin >> a;
                if (!a)
                    stop = true;
            }
            break;
        }
        case 5:
        {
            cout << "Are you sure you want to quit?\n press 1 to quit\n press 0 to cancel" << endl;
            int a;
            cin >> a;
            if (a)
                exit = true;
            break;
        }
        default: // for checking wrong inputs
        {
            cout << "invalid input" << endl;
            break;
        }
        }
    }
}
int main()
{
    menu();
    return 0;
}
