#include <iostream>
#include <vector>
#include <map>

using namespace std;

struct Folder {
    string parent;
    string name;
    vector<string> children;
};

map<string, Folder> graph;

string currentFolder;

void coutParent(string child) {
    if(child == "/") {
        cout << "/";
    } else if(graph[child].parent == "/") {
        cout << "/" << child;
    } else {
        coutParent(graph[child].parent);
        cout << "/" << child;
    }
}

void mkdir(string x) {
    for (int i = 0; i < graph[currentFolder].children.size(); i++)
    {
        if(x == graph[currentFolder].children[i]) {
            cout << "greska" << endl;
            return;
        }
    }
    graph[x] = {currentFolder, x, {}};
    graph[currentFolder].children.push_back(x);
    coutParent(x);
    cout << endl;
}
void rmdir(string x) {
    int found = -1;
    for (int i = 0; i < graph[currentFolder].children.size(); i++)
    {
        if(x == graph[currentFolder].children[i]) {
            found = i;
            break;
        }
    }
    if(found == -1) {
        cout << "greska" << endl;
        return;
    }
    if(graph[x].children.size() > 0) {
        cout << "greska" << endl;
        return;
    }
    graph[currentFolder].children.erase(graph[currentFolder].children.begin() + found);
    coutParent(x);
    cout << endl;
}

void cd(string x) {
    int found = -1;
    for (int i = 0; i < graph[currentFolder].children.size(); i++)
    {
        if(x == graph[currentFolder].children[i]) {
            found = i;
            break;
        }
    }
    if(found == -1) {
        cout << "greska" << endl;
        return;
    }
    currentFolder = x;
    coutParent(x);
    cout << endl;
}

void cdOut() {
    if(currentFolder == "/"){
        cout << "greska" << endl;
        return;
    }
    currentFolder = graph[currentFolder].parent;
    coutParent(currentFolder);
    cout << endl;
}

void execute(string action, string value) {
    if(action == "mkdir")
        mkdir(value);
    else if(action == "rmdir")
        rmdir(value);
    else if(action == "cd") {
        if(value == "..")
            cdOut();
        else
            cd(value);
    }
}

int main() {

    Folder root = {"", "/", {}};
    graph["/"] = root;
    currentFolder = root.name;

    int n;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        string action, value;
        cin >> action >> value;
        execute(action, value);
    }

    return 0;
}