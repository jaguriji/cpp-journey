#include<iostream>
#include<string>
using namespace std;

struct TrieNode {
    TrieNode* children[26];
    bool isEnd;
    TrieNode() {
        isEnd = false;
        for(int i = 0; i < 26; i++)
            children[i] = NULL;
    }
};

class Trie {
    TrieNode* root;
public:
    Trie() { root = new TrieNode(); }

    void insert(string word) {
        TrieNode* curr = root;
        for(char c : word) {
            int idx = c - 'a';
            if(!curr->children[idx])
                curr->children[idx] = new TrieNode();
            curr = curr->children[idx];
        }
        curr->isEnd = true;
        cout << "Inserted: " << word << endl;
    }

    bool search(string word) {
        TrieNode* curr = root;
        for(char c : word) {
            int idx = c - 'a';
            if(!curr->children[idx]) return false;
            curr = curr->children[idx];
        }
        return curr->isEnd;
    }

    bool startsWith(string prefix) {
        TrieNode* curr = root;
        for(char c : prefix) {
            int idx = c - 'a';
            if(!curr->children[idx]) return false;
            curr = curr->children[idx];
        }
        return true;
    }

    void suggestHelper(TrieNode* curr, string prefix) {
        if(curr->isEnd) cout << prefix << endl;
        for(int i = 0; i < 26; i++)
            if(curr->children[i])
                suggestHelper(curr->children[i], prefix + (char)('a'+i));
    }

    void suggest(string prefix) {
        TrieNode* curr = root;
        for(char c : prefix) {
            int idx = c - 'a';
            if(!curr->children[idx]) {
                cout << "No suggestions for: " << prefix << endl;
                return;
            }
            curr = curr->children[idx];
        }
        cout << "Suggestions for \"" << prefix << "\":" << endl;
        suggestHelper(curr, prefix);
    }
};

int main() {
    Trie t;
    t.insert("apple");
    t.insert("app");
    t.insert("application");
    t.insert("apply");
    t.insert("banana");
    t.insert("band");
    t.insert("bandana");

    cout << "\n--- Search ---" << endl;
    cout << "Search 'app': " << (t.search("app") ? "Found" : "Not Found") << endl;
    cout << "Search 'apple': " << (t.search("apple") ? "Found" : "Not Found") << endl;
    cout << "Search 'apt': " << (t.search("apt") ? "Found" : "Not Found") << endl;

    cout << "\n--- Prefix Check ---" << endl;
    cout << "Starts with 'app': " << (t.startsWith("app") ? "Yes" : "No") << endl;
    cout << "Starts with 'ban': " << (t.startsWith("ban") ? "Yes" : "No") << endl;
    cout << "Starts with 'cat': " << (t.startsWith("cat") ? "Yes" : "No") << endl;

    cout << "\n--- Suggestions ---" << endl;
    t.suggest("app");
    t.suggest("ban");

    return 0;
}