// STATUS: zavrsen
// IZVOR: KTOS-2015

#include <iostream>
#include <vector>

using namespace std;

int main() {
    int l, h;
    string str;
    vector<string> slova;

    // l = 4;
    // h = 5;

    // vector<string> slova(h, "");

    // slova[0] = " #  ##   ## ##  ### ###  ## # # ###  ## # # #   # # ###  #  ##   #  ##   ## ### # # # # # # # # # # ### ###";
    // slova[1] = "# # # # #   # # #   #   #   # #  #    # # # #   ### # # # # # # # # # # #    #  # # # # # # # # # #   #   #";
    // slova[2] = "### ##  #   # # ##  ##  # # ###  #    # ##  #   ### # # # # ##  # # ##   #   #  # # # # ###  #   #   #   ##";
    // slova[3] = "# # # # #   # # #   #   # # # #  #  # # # # #   # # # # # # #    ## # #   #  #  # # # # ### # #  #  #      ";
    // slova[4] = "# # ##   ## ##  ### #    ## # # ###  #  # # ### # # # #  #  #     # # # ##   #  ###  #  # # # #  #  ###  # ";

    cin >> l >> h;
    cin >> str;

    string linijaSlova;
    for (int i = 0; i < h + 1; i++)
    {
        getline(cin, linijaSlova);
        slova.push_back(linijaSlova);
    }
    slova.erase(slova.begin());
    cout << "\n";
    
    vector<int> indeksiSlova;
    for (int i = 0; i < str.length(); i++)
    {
        if((int)str[i] >= 97 && (int)str[i] <= 122)
            str[i] -= 32;

        indeksiSlova.push_back(str[i] -= 65);
    }
    vector<string> rijec;
    for (int i = 0; i < slova.size(); i++)
    {
        string linija = "";
        for (int j = 0; j < indeksiSlova.size(); j++)
        {
            linija += slova[i].substr(indeksiSlova[j] * l, l);
        }
        rijec.push_back(linija);
    }

    for (int i = 0; i < rijec.size(); i++)
    {
        for (int j = 0; j < rijec[i].length(); j++)
        {
            cout << rijec[i][j];
        }
        cout << "\n";
    }
}