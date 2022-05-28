// STATUS: zavrsen
// IZVOR: BHOI

#include <iostream>
#include <vector>
#include <string>
#include <fstream>

using namespace std;

// nidje veze samo brute force...

int counter(string word){
    int index = 1;
    string gen = "a";
    while(word != gen){
        bool newChar = true;
        for(int i = gen.size() - 1; i >= 0; i--){
            if(i == gen.size() - 1 && gen[i] =='z')
                continue;
            if(i != gen.size() - 1 && gen[i] == gen[i + 1] - 1)
                continue;
            index++;
            gen[i]++;

            for(int j = i +1; j < gen.size(); j++){
                gen[j] = gen[j - 1] + 1;
            }

            newChar = false;
            break;
        }
        if(newChar == true){
            int newSize = gen.size() + 1;
            gen = "a";
            for(int i = 1; i < newSize; i++){
                gen.push_back(gen[i - 1] + 1);

            }
            index++;
        }
        //cout << gen << endl;
    }
    return index;
}


int main()
{
    string word;
    vector<int> results;
    int t;
    cin >> t;
    while(t--){
        cin >> word;
        bool invalid = false;
        for(int i(1); i < word.size(); i++){
            if(word[i] <= word[i-1]){
                results.push_back(0);
                invalid = true;
                break;
            }

        }
        if(invalid == false)
        results.push_back(counter(word));

    }
    for(int i = 0; i < results.size(); i++){
        cout << results[i];
        cout << endl;
    }
    return 0;
}