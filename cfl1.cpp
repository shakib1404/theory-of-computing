#include<bits/stdc++.h>
using namespace std;

string p[] = {"e", "0", "1", "0P0", "1P1"};



bool production_exists(string temp) {
    return (find(p, p + 5, temp) != p + 5);
}

int find_P_position(string path) {
    int pos = 0;
    for(int k = 0; k < path.size(); k++) {
        if('P' == path[k]) {
            pos = k;
        }
    }
    return pos;
}

string replace_P(string path, string temp) {
    int pos = find_P_position(path);
    return path.replace(pos, 1, temp);
}

void generate_path(string str) {
    string temp, x, y, path = "P";
    cout << "P" << " -> ";

    for(int i = 0, j = str.size() - 1; i < j; i++, j--) {
        if(str[i] != str[j]) {
            cout << "Not in this grammar.";
            return;
        }

        x = str[i];
        y = str[j];
        temp = x + "P" + y;

        if(production_exists(temp)) {
            path = replace_P(path, temp);
        }

        if(path == "p") {
            cout << "Something missing!!" << endl;
            return;
        }

        cout << path << " -> ";
    }
    cout << str << endl;
}

int main() {
    string str;
    cin >> str;
    generate_path(str);
    return 0;
}
